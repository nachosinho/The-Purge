#include "GameManager.h"
#include "Rifle.h"

Rifle::Rifle(GameManager* _gameManager, Player* _player)
: Weapon(_gameManager, _player), m_MaxAmmo(10), m_Ammo(10)
{
	if (m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	this->m_Bullets = new vector<Bullet*>;
	this->setDamage(40);
	this->setDelay(0.00005f);
	this->setCooldown(this->getDelay());
}

void Rifle::setAmmo(int _value) {
	if (_value < 0) _value = 0;
	this->m_Ammo = _value;
}

void Rifle::setMaxAmmo(int _value) {
	if (_value < 0) _value = 0;
	this->m_MaxAmmo = _value;
}

void Rifle::shoot(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Ammo == 0) {
		this->getOwner()->playSFX("EMPTY");
		return;
	}

	if (this->m_Cooldown < this->m_Delay)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	if (anim->getName() != "MOVE" &&
		anim->getName() != "IDLE")
		return;

	this->getOwner()->setAnimation("ATTACK");
	this->m_Bullets->push_back(new Bullet(this));
	this->getOwner()->playSFX("ATTACK");
}

void Rifle::reload(void) {
	if (this->m_GameManager == nullptr)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	if (anim->getName() != "MOVE" &&
		anim->getName() != "IDLE")
		return;

	this->getOwner()->setAnimation("RELOAD");
	this->getOwner()->playSFX("RELOAD");
}

void Rifle::update(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	if (this->m_Bullets == nullptr)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	float elapsedTime = this->m_GameManager->getClock()->restart().asSeconds();
	if (this->m_Cooldown + elapsedTime < this->m_Delay) this->m_Cooldown += elapsedTime;
	else this->m_Cooldown = this->m_Delay;

	if (anim->getName() == "RELOAD") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			this->getOwner()->setAnimation("IDLE");
			this->m_Ammo = this->m_MaxAmmo;
			dynamic_cast<Player*>(this->getOwner())->getAmmoInfo()->updateText();
		}
	}

	else if (anim->getName() == "ATTACK") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			this->getOwner()->setAnimation("IDLE");
			this->m_Ammo--;
			this->m_Cooldown = 0.f;
			dynamic_cast<Player*>(this->getOwner())->getAmmoInfo()->updateText();
		}
	}

	if (this->m_GameManager->getEnemySpawner() == nullptr)
		return;

	for (int i = 0, end = this->m_Bullets->size(); i < end; i++) {
		if (i >= end) break;

		Bullet* _bullet = (*m_Bullets)[i];
		if (_bullet == nullptr) continue;

		_bullet->update(this->m_GameManager->getWindow());

		if (_bullet->getPosition().x <= 0 ||
			_bullet->getPosition().x + _bullet->getGlobalBounds().width >= WINDOW_X ||
			_bullet->getPosition().y <= 0 ||
			_bullet->getPosition().y + _bullet->getGlobalBounds().height >= WINDOW_Y) {
			_bullet = nullptr;
			delete _bullet;
			m_Bullets->erase(m_Bullets->begin() + i);
			break;
		}

		for (int j = 0, jend = this->m_GameManager->getEnemySpawner()->getEnemies()->size(); j < jend; j++) {
			Enemy* _enemy = (*this->m_GameManager->getEnemySpawner()->getEnemies())[j];
			if (_enemy == nullptr)
				break;

			FloatRect enemyHitbox = _enemy->getGlobalBounds();
			enemyHitbox.top += enemyHitbox.height / 4.f;
			enemyHitbox.height /= 2.f;
			enemyHitbox.left += enemyHitbox.width / 4.f;
			enemyHitbox.width /= 2.f;

			if (_bullet->getGlobalBounds().intersects(enemyHitbox)) {
				_enemy->setHealth(_enemy->getHealth() - this->getDamage());
				if (_enemy->getHealth() > 0)
					_enemy->playSFX("WOUND");
				_bullet = nullptr;
				delete _bullet;
				m_Bullets->erase(m_Bullets->begin() + i);
				break;
			}
		}
	}
}
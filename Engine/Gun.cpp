#include "Gun.h"
#include "GameManager.h"


Gun::Gun(GameManager* _gameManager, NPC* _npc)
	: Weapon(_gameManager, _npc), m_BulletVelocity(5.f), m_MaxAmmo(10), m_Ammo(10)
{
	this->m_Bullets = new vector<Bullet*>;
}

void Gun::setBulletVelocity(float _velocity) {
	if (_velocity < 0.f) _velocity = 0.f;
	this->m_BulletVelocity = _velocity;
}

void Gun::setAmmo(int _value) {
	if (_value < 0) _value = 0;
	this->m_Ammo = _value;
}

void Gun::setMaxAmmo(int _value) {
	if (_value < 0) _value = 0;
	this->m_MaxAmmo = _value;
	this->m_Ammo = _value;
}

void Gun::reset(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_WeaponType >= Weapon::WEAPONTYPE::MELEE)
		return;

	this->setDamage(this->DEFAULT_DAMAGE[this->m_WeaponType]);
	this->setBulletVelocity(this->DEFAULT_BULLET_VELOCITY[this->m_WeaponType]);
	this->setMaxAmmo(this->DEFAULT_MAX_AMMO[this->m_WeaponType]);
	this->setDelay(this->DEFAULT_DELAY[this->m_WeaponType]);
}

void Gun::reload(void) {
	if (this->m_GameManager == nullptr)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	if (anim->getName() != this->getName() + "_MOVE" &&
		anim->getName() != this->getName() + "_IDLE")
		return;

	if (this->getAmmo() == this->getMaxAmmo())
		return;

	this->getOwner()->setAnimation(this->getName() + "_RELOAD");
	this->getOwner()->playSFX(this->getName() + "_RELOAD");
}

void Gun::update(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	if (this->m_Bullets == nullptr)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	float elapsedTime = this->m_GameManager->getElapsedTime();
	if (this->m_Cooldown + elapsedTime < this->m_Delay) this->m_Cooldown += elapsedTime;
	else this->m_Cooldown = this->m_Delay;

	if (anim->getName() == this->getName() + "_RELOAD") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			this->getOwner()->setAnimation(this->getName() + "_IDLE");
			this->m_Ammo = this->m_MaxAmmo;
			dynamic_cast<Player*>(this->getOwner())->getAmmoInfo()->updateText();
		}
	}

	else if (anim->getName() == this->getName() + "_ATTACK") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			this->getOwner()->setAnimation(this->getName() + "_IDLE");
			this->m_Ammo--;
			this->m_Cooldown = 0.f;
			dynamic_cast<Player*>(this->getOwner())->getAmmoInfo()->updateText();
		}
	}

	else if (anim->getName() == this->getName() + "_SWITCH") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			this->m_Bullets->clear();
			this->equipNextWeapon();
			this->getOwner()->setAnimation(this->getName() + "_IDLE");
			AmmoInfo* ammoInfo = dynamic_cast<Player*>(this->getOwner())->getAmmoInfo();
			if (ammoInfo == nullptr)
				return;
			ammoInfo->updateText();
		}
	}

	if (this->m_GameManager->getEnemySpawner() == nullptr)
		return;

	for (int i = 0, end = this->m_Bullets->size(); i < end; i++) {
		if (i >= end) break;

		Bullet* _bullet = (*m_Bullets)[i];
		if (_bullet == nullptr) continue;
		
		bool bulletCollided = false;

		_bullet->update(this->m_GameManager->getWindow());

		if (_bullet->getPosition().x <= 0 ||
			_bullet->getPosition().x + _bullet->getGlobalBounds().width >= WINDOW_X ||
			_bullet->getPosition().y <= 0 ||
			_bullet->getPosition().y + _bullet->getGlobalBounds().height >= WINDOW_Y) {
			m_Bullets->erase(m_Bullets->begin() + i);
			bulletCollided = true;
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
				m_Bullets->erase(m_Bullets->begin() + i);
				bulletCollided = true;
				break;
			}
		}
		if (bulletCollided) break;
	}
}
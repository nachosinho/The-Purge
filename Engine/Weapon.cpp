#include "GameManager.h"
#include "Weapon.h"

Weapon::Weapon(GameManager* _gameManager, Player* _player)
	: m_MaxAmmo(10), m_Ammo(10), m_Damage(1), m_MaxTrace(0.00025f), m_Trace(0.00025f), m_Bullets()
{
	this->m_GameManager = _gameManager;
	this->m_Owner = _player;

	if (m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	this->m_Bullets = new vector<Bullet*>;
}

void Weapon::shoot(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Ammo == 0)
		return;

	if (this->m_Trace < this->m_MaxTrace)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	if (anim->getName() != "MOVE" &&
		anim->getName() != "IDLE")
		return;

	this->getOwner()->setAnimation("ATTACK");
	this->m_Bullets->push_back(new Bullet(this));
}

void Weapon::reload(void) {
	if (this->m_GameManager == nullptr)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	if (anim->getName() != "MOVE" &&
		anim->getName() != "IDLE")
		return;

	this->getOwner()->setAnimation("RELOAD");
}

void Weapon::update(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	float elapsedTime = this->m_GameManager->getClock()->restart().asSeconds();
	if (this->m_Trace + elapsedTime < this->m_MaxTrace) this->m_Trace += elapsedTime;
	else this->m_Trace = this->m_MaxTrace;

	if (anim->getName() == "RELOAD") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			this->getOwner()->setAnimation("IDLE");
			this->m_Ammo = this->m_MaxAmmo;
		}
	}

	else if (anim->getName() == "ATTACK") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			this->getOwner()->setAnimation("IDLE");
			this->m_Ammo--;
			this->m_Trace = 0.f;
		}
	}

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
	}
}
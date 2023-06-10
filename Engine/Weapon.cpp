#include "Weapon.h"
#include "GameManager.h"

Weapon::Weapon(GameManager* _gameManager)
	: m_MaxAmmo(10), m_Ammo(10), m_Damage(1), m_MaxTrace(0.00025f), m_Trace(0.00025f)
{
	this->m_GameManager = _gameManager;

	this->m_Bullets = new vector<Bullet*>;
}

void Weapon::shoot(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Ammo == 0)
		return;

	if (this->m_Trace < this->m_MaxTrace)
		return;

	Animation* anim = this->m_GameManager->getPlayer()->getCurrentAnimation();

	if (anim->getName() != "WALK" &&
		anim->getName() != "IDLE")
		return;

	std::cout << anim->getName() << std::endl;

	this->m_GameManager->getPlayer()->setAnimation("ATTACK");
	//std::cout << this->m_Ammo << std::endl;
}

void Weapon::reload(void) {
	if (this->m_GameManager == nullptr)
		return;

	Animation* anim = this->m_GameManager->getPlayer()->getCurrentAnimation();

	if (anim->getName() != "WALK" &&
		anim->getName() != "IDLE")
		return;

	this->m_GameManager->getPlayer()->setAnimation("RELOAD");
}

void Weapon::update(void) {
	if (this->m_GameManager == nullptr)
		return;

	Animation* anim = this->m_GameManager->getPlayer()->getCurrentAnimation();

	float elapsedTime = this->m_GameManager->getClock()->restart().asSeconds();
	if (this->m_Trace + elapsedTime < this->m_MaxTrace) this->m_Trace += elapsedTime;
	else this->m_Trace = this->m_MaxTrace;

	if (anim->getName() == "RELOAD") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			this->m_GameManager->getPlayer()->setAnimation("IDLE");
			this->m_Ammo = this->m_MaxAmmo;
		}
	}

	else if (anim->getName() == "ATTACK") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			std::cout << anim->getName() << std::endl;
			this->m_GameManager->getPlayer()->setAnimation("IDLE");
			this->m_Ammo--;
			this->m_Trace = 0.f;
		}
	}

	
}
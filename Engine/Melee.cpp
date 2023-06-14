#include "GameManager.h"
#include "Melee.h"

Melee::Melee(GameManager* _gameManager, NPC* _player)
	: Weapon(_gameManager, _player)
{
	if (m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	this->m_Name = "MELEE";
	this->m_WeaponType = Weapon::WEAPONTYPE::MELEE;
	this->reset();
}

void Melee::attack(NPC* _target) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Cooldown < this->m_Delay)
		return;

	if (_target == nullptr)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	if (anim->getName() != "MOVE" &&
		anim->getName() != "IDLE")
		return;

	this->getOwner()->setAnimation("ATTACK");
	_target->setHealth(_target->getHealth() - this->getDamage());
	this->getOwner()->playSFX("ATTACK");
}

void Melee::update(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	float elapsedTime = this->m_GameManager->getElapsedTime();
	if (this->m_Cooldown + elapsedTime < this->m_Delay) this->m_Cooldown += elapsedTime;
	else this->m_Cooldown = this->m_Delay;

	if (anim->getName() == "ATTACK") {
		if (anim->getCurrentFrame() == anim->getFramesCount() - 1) {
			this->getOwner()->setAnimation("IDLE");
			this->m_Cooldown = 0.f;
		}
	}
}
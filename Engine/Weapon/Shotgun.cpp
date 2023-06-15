#include "Shotgun.h"
#include "../Core/GameManager.h"

Shotgun::Shotgun(GameManager* _gameManager, NPC* _npc)
	: Gun(_gameManager, _npc)
{
	if (m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	this->m_Name = "SHOTGUN";
	this->m_WeaponType = Weapon::WEAPONTYPE::SHOTGUN;
	this->reset();
}

void Shotgun::shoot(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Ammo == 0) {
		this->getOwner()->playSFX("WEAPON_EMPTY");
		return;
	}

	if (this->m_Cooldown < this->m_Delay)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	if (anim->getName() != this->getName() + "_MOVE" &&
		anim->getName() != this->getName() + "_IDLE")
		return;

	this->getOwner()->setAnimation(this->getName() + "_ATTACK");
	this->m_Bullets->push_back(new Bullet(this, -5));
	this->m_Bullets->push_back(new Bullet(this, 0));
	this->m_Bullets->push_back(new Bullet(this, 5));
	this->getOwner()->playSFX(this->getName() + "_ATTACK");
}
#include "GameManager.h"
#include "Pistol.h"

Pistol::Pistol(GameManager* _gameManager, NPC* _npc)
	: Gun(_gameManager, _npc)
{
	if (m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	this->m_Name = "PISTOL";
	this->m_WeaponType = Weapon::WEAPONTYPE::PISTOL;
	this->reset();
}

void Pistol::shoot(void) {
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
	this->m_Bullets->push_back(new Bullet(this));
	this->getOwner()->playSFX(this->getName() + "_ATTACK");
}
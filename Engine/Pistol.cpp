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
	this->setDamage(40);
	this->setMaxAmmo(7);
	this->setDelay(0.5f);
	this->setCooldown(this->getDelay());
}

void Pistol::shoot(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Ammo == 0) {
		this->getOwner()->playSFX("EMPTY");
		return;
	}

	if (this->m_Cooldown < this->m_Delay)
		return;

	Animation* anim = this->getOwner()->getCurrentAnimation();

	if (anim->getName() != "PISTOL_MOVE" &&
		anim->getName() != "PISTOL_IDLE")
		return;

	this->getOwner()->setAnimation("PISTOL_ATTACK");
	this->m_Bullets->push_back(new Bullet(this));
	this->getOwner()->playSFX("ATTACK");
}
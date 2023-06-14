#include "GameManager.h"
#include "Rifle.h"

Rifle::Rifle(GameManager* _gameManager, NPC* _npc)
: Gun(_gameManager, _npc)
{
	if (m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

	this->m_Name = "RIFLE";
	this->m_Bullets = new vector<Bullet*>;
	this->setMaxAmmo(30);
	this->setDamage(10);
	this->setDelay(0.05f);
	this->setCooldown(this->getDelay());
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

	if (anim->getName() != "RIFLE_MOVE" &&
		anim->getName() != "RIFLE_IDLE")
		return;

	this->getOwner()->setAnimation("RIFLE_ATTACK");
	this->m_Bullets->push_back(new Bullet(this));
	this->getOwner()->playSFX("ATTACK");
}
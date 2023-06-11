#pragma once
#include "Bullet.h"

class Weapon {
protected:
	float m_Cooldown, m_Delay;
	int m_Damage;

	class GameManager* m_GameManager;
	class NPC* m_Owner;
public:
	Weapon(class GameManager*, class NPC*);

	int getDamage(void) { return this->m_Damage; }
	float getCooldown(void) { return this->m_Cooldown; }
	float getDelay(void) { return this->m_Delay; }

	void setDamage(int);
	void setCooldown(float);
	void setDelay(float);

	class NPC* getOwner(void) { return this->m_Owner; }

	virtual void update(void) = 0;
};
#pragma once
#include "Bullet.h"

class Weapon {
protected:
	float m_Cooldown, m_Delay;
	int m_Damage;
	string m_Name;

	int m_NextWeapon;

	class GameManager* m_GameManager;
	class NPC* m_Owner;

public:
	Weapon(class GameManager*, class NPC*);
	enum WEAPONTYPE { PISTOL, RIFLE };

	int getDamage(void) { return this->m_Damage; }
	string getName(void) { return this->m_Name; }
	float getCooldown(void) { return this->m_Cooldown; }
	float getDelay(void) { return this->m_Delay; }

	int getNextWeapon(void) { return this->m_NextWeapon; }

	void equipNextWeapon(void);
	void setDamage(int);
	void setCooldown(float);
	void setDelay(float);
	void switchWeapon(int);

	class NPC* getOwner(void) { return this->m_Owner; }

	virtual void update(void) = 0;
};
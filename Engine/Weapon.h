#pragma once
#include "Bullet.h"

class Weapon {
protected:
	float m_Cooldown, m_Delay;
	int m_Damage;
	string m_Name;

	int m_NextWeapon, m_WeaponType;

	class GameManager* m_GameManager;
	class NPC* m_Owner;

public:
	Weapon(class GameManager*, class NPC*);
	enum WEAPONTYPE { PISTOL, RIFLE, SHOTGUN, MELEE, NONE };

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

	void reset(void);
	virtual void update(void) = 0;

	// Pistol, Rifle, Shotgun, Melee
	const int DEFAULT_MAX_AMMO[3] = { 7, 30, 2 };
	const int DEFAULT_DAMAGE[4] = { 25, 10, 50, 15 };
	const float DEFAULT_DELAY[4] = { 0.5f, 0.05f, 1.75f, 0.5f };
	const float DEFAULT_BULLET_VELOCITY[3] = { 5.f, 7.5f, 4.f };
};
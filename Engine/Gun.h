#pragma once
#include "Weapon.h"

class Gun : public Weapon {
protected:
	int m_Ammo, m_MaxAmmo;
	float m_BulletVelocity;
	vector<Bullet*>* m_Bullets;
public:
	Gun(class GameManager*, class NPC*);

	float getBulletVelocity(void) { return this->m_BulletVelocity; }
	int getAmmo(void) { return this->m_Ammo; }
	int getMaxAmmo(void) { return this->m_MaxAmmo; }

	void setBulletVelocity(float);
	void setAmmo(int);
	void setMaxAmmo(int);

	virtual void shoot(void) = 0;
	void reset(void);
	void reload(void);
	void update(void);

	// Pistol, Rifle, Shotgun
	const int DEFAULT_MAX_AMMO[3] = { 7, 30, 2 };
	const int DEFAULT_DAMAGE[3] = { 25, 10, 50 };
	const float DEFAULT_DELAY[3] = { 0.5f, 0.05f, 1.75f };
	const float DEFAULT_BULLET_VELOCITY[3] = { 5.f, 7.5f, 4.f };
};
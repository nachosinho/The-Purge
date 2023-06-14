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
	vector<Bullet*>* getBullets(void) { return this->m_Bullets; }

	void setBulletVelocity(float);
	void setAmmo(int);
	void setMaxAmmo(int);

	virtual void shoot(void) = 0;
	void reload(void);
	void update(void);
};
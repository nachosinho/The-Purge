#pragma once
#include "Weapon.h"

class Gun : public Weapon {
protected:
	int m_Ammo, m_MaxAmmo;
	vector<Bullet*>* m_Bullets;
public:
	Gun(class GameManager*, class NPC*);
	int getAmmo(void) { return this->m_Ammo; }
	int getMaxAmmo(void) { return this->m_MaxAmmo; }

	void setAmmo(int);
	void setMaxAmmo(int);

	void reload(void);
	virtual void shoot(void) = 0;
	void update(void);
};
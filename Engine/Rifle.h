#pragma once
#include "Weapon.h"

class Rifle : public Weapon {
private:
	int m_Ammo, m_MaxAmmo;
	vector<Bullet*>* m_Bullets;

public:
	Rifle(class GameManager*, class Player*);

	int getAmmo(void) { return this->m_Ammo; }
	int getMaxAmmo(void) { return this->m_MaxAmmo; }

	void setAmmo(int);
	void setMaxAmmo(int);

	void reload(void);
	void shoot(void);
	void update(void);
};
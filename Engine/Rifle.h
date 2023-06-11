#pragma once
#include "Weapon.h"

class Rifle : public Weapon {
private:
	int m_Ammo, m_MaxAmmo;
	vector<Bullet*>* m_Bullets;
public:
	Rifle(class GameManager*, class Player*);

	void reload(void);
	void shoot(void);
	void update(void);
};
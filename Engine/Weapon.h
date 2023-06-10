#pragma once
#include "Bullet.h"

class Weapon {
private:
	float m_Trace, m_MaxTrace;
	int m_Damage, m_Ammo, m_MaxAmmo;
	vector<Bullet*>* m_Bullets;

	class GameManager* m_GameManager;
public:
	Weapon(class GameManager*);

	void reload(void);
	void shoot(void);

	void update(void);
};
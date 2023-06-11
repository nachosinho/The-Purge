#pragma once
#include "Weapon.h"

class Melee : public Weapon {
private:
public:
	Melee(class GameManager*, class NPC*);

	void attack(class NPC*);
	void update(void);
};
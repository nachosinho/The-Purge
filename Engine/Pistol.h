#pragma once
#include "Gun.h"

class Pistol : public Gun {
public:
	Pistol(class GameManager*, class NPC*);

	void shoot(void);
};
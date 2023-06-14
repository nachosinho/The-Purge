#pragma once
#include "Gun.h"

class Rifle : public Gun {
public:
	Rifle(class GameManager*, class NPC*);

	void shoot(void);
};
#pragma once
#include "Gun.h"

class Shotgun : public Gun {
public:
	Shotgun(class GameManager*, class NPC*);

	void shoot(void);
};
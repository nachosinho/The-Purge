#pragma once
#include "NPC.h"

class Player : public NPC {

public:
	Player(class GameManager*);
	void render(void);
};
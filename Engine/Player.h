#pragma once
#include "NPC.h"

class Player : public NPC {
private:
public:
	Player(class GameManager*);
	
	void loadAnimations(void);
	void moveControl(void);

	void render(void);
};
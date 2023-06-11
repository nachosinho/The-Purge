#pragma once
#include "NPC.h"
#include "Rifle.h"

class Player : public NPC {
private:
public:
	Player(class GameManager*);
	
	void loadAnimations(void);
	void animationControl(void);
	void moveControl(void);

	void render(void);
};
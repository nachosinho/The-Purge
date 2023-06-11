#pragma once
#include "Melee.h"
#include "NPC.h"

class Enemy : public NPC {
private:
public:
	Enemy(class GameManager*);

	void loadAnimations(void);
	void loadSFXs(void);
	void animationControl(void);
	void moveControl(void);

	void render(void);
};
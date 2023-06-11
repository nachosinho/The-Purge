#pragma once
#include "NPC.h"

class Enemy : public NPC {
private:
public:
	Enemy(class GameManager*);

	void loadAnimations(void);
	void animationControl(void);
	void moveControl(void);

	void render(void);
};
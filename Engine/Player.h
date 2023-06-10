#pragma once
#include "NPC.h"
#include "Weapon.h"

class Player : public NPC {
private:
	Weapon* m_Weapon;
public:
	Player(class GameManager*);
	
	void loadAnimations(void);
	void moveControl(void);

	void render(void);
};
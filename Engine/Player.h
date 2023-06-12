#pragma once
#include "NPC.h"
#include "Rifle.h"
#include "AmmoInfo.h"

class Player : public NPC {
private:
	AmmoInfo* m_AmmoInfo;
public:
	Player(class GameManager*);
	
	AmmoInfo* getAmmoInfo(void) { return this->m_AmmoInfo; }

	void loadAnimations(void);
	void loadSFXs(void);
	void animationControl(void);
	void moveControl(void);
	void reset(void);

	void render(void);
};
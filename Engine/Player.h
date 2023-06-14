#pragma once
#include "NPC.h"
#include "Rifle.h"
#include "Pistol.h"
#include "Shotgun.h"
#include "AmmoInfo.h"

class Player : public NPC {
private:
	AmmoInfo* m_AmmoInfo;
	vector<Weapon*>* m_Weapons;
public:
	Player(class GameManager*);
	
	AmmoInfo* getAmmoInfo(void) { return this->m_AmmoInfo; }
	vector<Weapon*>* getWeapons(void) { return this->m_Weapons; }

	void loadAnimations(void);
	void loadSFXs(void);
	void animationControl(void);
	void moveControl(void);
	void reset(void);

	void render(void);
};
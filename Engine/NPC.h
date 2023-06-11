#pragma once
#include "SFX.h"
#include "HealthBar.h"
#include "Weapon.h"
#include "Animation.h"

class NPC : public Sprite {
protected:
	HealthBar* m_HealthBar;
	Animation* m_CurrentAnimation;
	map<string, Animation*>*  m_Animations;
	map<string, SFX*>* m_SFXs;
	Weapon* m_Weapon;

	int m_Health = 100;
	bool m_Dead = false;

	class GameManager* m_GameManager;

public:
	NPC(void);

	int getHealth(void) { return this->m_Health; }

	void setHealth(int);

	Animation* getCurrentAnimation(void) { return this->m_CurrentAnimation; }

	virtual void loadAnimations(void) = 0;
	void addAnimation(Animation*);
	void setAnimation(string);

	virtual void loadSFXs(void) = 0;
	void addSFX(SFX*);
	void playSFX(string);

	virtual void animationControl(void) = 0;
	virtual void moveControl(void) = 0;

	virtual void render(void) = 0;
};
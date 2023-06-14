#pragma once
#include "include.h"
#include "SFX.h"

class Menu {
protected:
	string m_Name;
	int m_GameState;
	SFX* m_SFX;

	class GameManager* m_GameManager;
public:
	Menu(string, class GameManager*);

	SFX* getSFX(void) { return this->m_SFX; }
	string getName(void) { return this->m_Name; }
	int getGameState(void) { return this->m_GameState; }

	virtual void handleInput(void) = 0;
	virtual void update(void) = 0;
	virtual void reload(void) = 0;
	virtual void render(void) = 0;
};
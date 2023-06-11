#pragma once
#include "include.h"

class Menu {
protected:
	class GameManager* m_GameManager;
public:
	Menu() {};
	virtual void handleInput(void) = 0;
	virtual void update(void) = 0;
	virtual void render(void) = 0;
};
#pragma once
#include "Player.h"
#include "Enemy.h"

class GameManager {
private:
	int m_GameState;
	HWND m_WindowHandler;

	RenderWindow* m_Window;
	Event* m_Event;
	Clock* m_Clock;

	Player* m_Player;
	vector<Enemy*>* m_Enemies;
	//Level* m_Level;
	//Menu* m_Menu;
	//SubMenu* m_SubMenu;

	void loadSettings(void);
	void eventManager(void);	
	void render(void);

public:
	enum GAMESTATE {
		MAINMENU,
		PLAYING,
		PAUSED,
		OVER
	};

	GameManager(void);

	//Level* getCurrentLevel(void) { return this->m_CurrentLevel; }
	Player* getPlayer(void) { return this->m_Player; }
	vector<Enemy*>* getEnemies(void) { return this->m_Enemies; }

	RenderWindow* getWindow(void) { return this->m_Window; }
	int getGameStatus(void) { return this->m_GameState; }
	Clock* getClock(void) { return this->m_Clock; }

	void addEnemy(Enemy*);

	//void setMenu(Menu*, int);
	//void getMenu(void) { return this->m_Menu; }
	//void setSubMenu(Menu*, int);
	//void getSubMenu(void) { return this->m_Menu; }

	void restartGame(void);
};
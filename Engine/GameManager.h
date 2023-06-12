#pragma once
#include "Player.h"
#include "EnemySpawner.h"
#include "KillCount.h"
#include "../Levels/LevelsList.h"
#include "../Menus/MenusList.h"

class GameManager {
private:
	int m_GameState;
	HWND m_WindowHandler;

	RenderWindow* m_Window;
	Event* m_Event;
	Clock* m_Clock;
	float m_ElapsedTime;

	vector<Level*>* m_Levels;

	Player* m_Player;
	EnemySpawner* m_EnemySpawner;
	Level* m_Level;
	Menu* m_Menu;
	KillCount* m_KillCount;
	//SubMenu* m_SubMenu;

	void loadSettings(void);
	void loadLevels(void);
	void eventManager(void);

	void setElapsedTime(float);

	void render(void);

public:
	enum GAMESTATE {
		MAINMENU,
		PLAYING,
		PAUSED,
		OVER
	};

	GameManager(void);

	Level* getCurrentLevel(void) { return this->m_Level; }
	Player* getPlayer(void) { return this->m_Player; }
	RenderWindow* getWindow(void) { return this->m_Window; }
	int getGameStatus(void) { return this->m_GameState; }
	Event* getEvent(void) { return this->m_Event; }
	Clock* getClock(void) { return this->m_Clock; }
	float getElapsedTime(void) { return this->m_ElapsedTime; }
	EnemySpawner* getEnemySpawner(void) { return this->m_EnemySpawner; }
	KillCount* getKillCount(void) { return this->m_KillCount; }
	Menu* getMenu(void) { return this->m_Menu; }
	
	void setMenu(Menu*, int);

	//void setSubMenu(Menu*, int);
	//Menu* getSubMenu(void) { return this->m_Menu; }

	void restartGame(void);
};
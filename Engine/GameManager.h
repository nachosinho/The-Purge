#pragma once
#include "Player.h"
#include "EnemySpawner.h"
#include "KillCount.h"
#include "../Levels/LevelsList.h"
#include "../Menus/MenusList.h"
#include "LootBox.h"
#include "Scoreboard.h"

class GameManager {
private:
	int m_GameState;
	HWND m_WindowHandler;

	RenderWindow* m_Window;
	Event* m_Event;
	Clock* m_Clock;
	float m_ElapsedTime;

	vector<Level*>* m_Levels;
	map<string, Menu*>* m_Menus;

	Player* m_Player;
	EnemySpawner* m_EnemySpawner;
	Level* m_Level;
	Menu* m_Menu;
	KillCount* m_KillCount;
	LootBox* m_LootBox;
	//SubMenu* m_SubMenu;

	ScoreBoard* m_ScoreBoard;

	void loadSettings(void);
	void loadMenus(void);
	void loadLevels(void);
	void eventManager(void);

	void setElapsedTime(float);
	void addMenu(Menu*);

	void render(void);

public:
	enum GAMESTATE {
		MAINMENU,
		PLAYING,
		PAUSED,
		OVER
	};

	GameManager(void);
	~GameManager(void);

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
	ScoreBoard* getScoreBoard(void) { return this->m_ScoreBoard; }
	
	void setMenu(string);

	//void setSubMenu(Menu*, int);
	//Menu* getSubMenu(void) { return this->m_Menu; }

	void restartGame(void);
	void exitGame(void);
};
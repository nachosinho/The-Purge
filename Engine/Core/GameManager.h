#pragma once
#include "../NPC/Player.h"
#include "EnemySpawner.h"
#include "../NPC/KillCount.h"
#include "../../Levels/LevelsList.h"
#include "../../Menus/MenusList.h"
#include "../Weapon/LootBox.h"
#include "Scoreboard.h"

/*
	GameManager jest klas¹ reprezentuj¹c¹ zarz¹dcê gry.
	Jest odpowiedzialny za kontrolê ogólnego stanu gry, zarz¹dzanie obiektami gry (takimi jak poziomy, menu, gracz) oraz obs³ugê zdarzeñ i renderowanie.
	Zawiera ró¿ne metody dostêpowe do wa¿nych elementów gry, takich jak aktualny poziom, obiekt gracza, okno renderowania, status gry itp.
	Dodatkowo posiada metody umo¿liwiaj¹ce restartowanie gry i zakoñczenie jej.
	Klasa GameManager pe³ni kluczow¹ rolê w zarz¹dzaniu wszystkimi aspektami gry.
*/

class GameManager {
private:
	int m_GameState; // Zmienna przechowuj¹ca aktualny stan gry.
	HWND m_WindowHandler; // Uchwyt do okna gry.

	RenderWindow* m_Window; // Obiekt renderowania okna.
	Event* m_Event; // Obiekt obs³uguj¹cy zdarzenia.
	Clock* m_Clock; // Obiekt licz¹cy czas.
	float m_ElapsedTime; // Czas, który up³yn¹³ od ostatniej klatki.

	vector<Level*>* m_Levels; // Wektor wskaŸników na poziomy gry.
	map<string, Menu*>* m_Menus; // Mapa nazwa-menu -> wskaŸnik na menu.

	Player* m_Player; // WskaŸnik na obiekt gracza.
	EnemySpawner* m_EnemySpawner; // WskaŸnik na obiekt generuj¹cy wrogów.
	Level* m_Level; // WskaŸnik na aktualny poziom.
	Menu* m_Menu; // WskaŸnik na aktualne menu.
	KillCount* m_KillCount; // WskaŸnik na obiekt licz¹cy iloœæ zabitych wrogów.
	LootBox* m_LootBox; // WskaŸnik na obiekt skrzyni z nagrodami.

	ScoreBoard* m_ScoreBoard; // WskaŸnik na tablicê wyników.

	void loadSettings(void); // Metoda wczytuj¹ca ustawienia gry.
	void loadMenus(void); // Metoda wczytuj¹ca menu.
	void loadLevels(void); // Metoda wczytuj¹ca poziomy gry.
	void eventManager(void); // Metoda obs³uguj¹ca zdarzenia.

	void setElapsedTime(float); // Metoda ustawiaj¹ca up³yniêty czas.
	void addMenu(Menu*); // Metoda dodaj¹ca menu.

	void render(void); // Metoda renderuj¹ca obraz gry.

public:
	enum GAMESTATE {
		MAINMENU, // G³ówne menu.
		PLAYING, // Tryb gry.
		PAUSED, // Tryb zatrzymania gry.
		OVER // Gra zakoñczona.
	};

	GameManager(void); // Konstruktor klasy GameManager.
	~GameManager(void); // Destruktor klasy GameManager.

	Level* getCurrentLevel(void) { return this->m_Level; } // Metoda zwracaj¹ca aktualny poziom gry.
	Player* getPlayer(void) { return this->m_Player; } // Metoda zwracaj¹ca obiekt gracza.
	RenderWindow* getWindow(void) { return this->m_Window; } // Metoda zwracaj¹ca obiekt okna.
	int getGameStatus(void) { return this->m_GameState; } // Metoda zwracaj¹ca status gry.
	Event* getEvent(void) { return this->m_Event; } // Metoda zwracaj¹ca obiekt zdarzenia.
	Clock* getClock(void) { return this->m_Clock; } // Metoda zwracaj¹ca obiekt zegara.
	float getElapsedTime(void) { return this->m_ElapsedTime; } // Metoda zwracaj¹ca up³yniêty czas.
	EnemySpawner* getEnemySpawner(void) { return this->m_EnemySpawner; } // Metoda zwracaj¹ca obiekt generuj¹cy wrogów.
	KillCount* getKillCount(void) { return this->m_KillCount; } // Metoda zwracaj¹ca obiekt licz¹cy iloœæ zabitych wrogów.
	Menu* getMenu(void) { return this->m_Menu; } // Metoda zwracaj¹ca aktualne menu.
	ScoreBoard* getScoreBoard(void) { return this->m_ScoreBoard; } // Metoda zwracaj¹ca tablicê wyników.

	void setMenu(string); // Metoda ustawiaj¹ca aktualne menu.

	void restartGame(void); // Metoda restartuj¹ca grê.
	void exitGame(void); // Metoda koñcz¹ca grê.
};
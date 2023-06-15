#pragma once
#include "../NPC/Player.h"
#include "EnemySpawner.h"
#include "../NPC/KillCount.h"
#include "../../Levels/LevelsList.h"
#include "../../Menus/MenusList.h"
#include "../Weapon/LootBox.h"
#include "Scoreboard.h"

/*
	GameManager jest klas� reprezentuj�c� zarz�dc� gry.
	Jest odpowiedzialny za kontrol� og�lnego stanu gry, zarz�dzanie obiektami gry (takimi jak poziomy, menu, gracz) oraz obs�ug� zdarze� i renderowanie.
	Zawiera r�ne metody dost�powe do wa�nych element�w gry, takich jak aktualny poziom, obiekt gracza, okno renderowania, status gry itp.
	Dodatkowo posiada metody umo�liwiaj�ce restartowanie gry i zako�czenie jej.
	Klasa GameManager pe�ni kluczow� rol� w zarz�dzaniu wszystkimi aspektami gry.
*/

class GameManager {
private:
	int m_GameState; // Zmienna przechowuj�ca aktualny stan gry.
	HWND m_WindowHandler; // Uchwyt do okna gry.

	RenderWindow* m_Window; // Obiekt renderowania okna.
	Event* m_Event; // Obiekt obs�uguj�cy zdarzenia.
	Clock* m_Clock; // Obiekt licz�cy czas.
	float m_ElapsedTime; // Czas, kt�ry up�yn�� od ostatniej klatki.

	vector<Level*>* m_Levels; // Wektor wska�nik�w na poziomy gry.
	map<string, Menu*>* m_Menus; // Mapa nazwa-menu -> wska�nik na menu.

	Player* m_Player; // Wska�nik na obiekt gracza.
	EnemySpawner* m_EnemySpawner; // Wska�nik na obiekt generuj�cy wrog�w.
	Level* m_Level; // Wska�nik na aktualny poziom.
	Menu* m_Menu; // Wska�nik na aktualne menu.
	KillCount* m_KillCount; // Wska�nik na obiekt licz�cy ilo�� zabitych wrog�w.
	LootBox* m_LootBox; // Wska�nik na obiekt skrzyni z nagrodami.

	ScoreBoard* m_ScoreBoard; // Wska�nik na tablic� wynik�w.

	void loadSettings(void); // Metoda wczytuj�ca ustawienia gry.
	void loadMenus(void); // Metoda wczytuj�ca menu.
	void loadLevels(void); // Metoda wczytuj�ca poziomy gry.
	void eventManager(void); // Metoda obs�uguj�ca zdarzenia.

	void setElapsedTime(float); // Metoda ustawiaj�ca up�yni�ty czas.
	void addMenu(Menu*); // Metoda dodaj�ca menu.

	void render(void); // Metoda renderuj�ca obraz gry.

public:
	enum GAMESTATE {
		MAINMENU, // G��wne menu.
		PLAYING, // Tryb gry.
		PAUSED, // Tryb zatrzymania gry.
		OVER // Gra zako�czona.
	};

	GameManager(void); // Konstruktor klasy GameManager.
	~GameManager(void); // Destruktor klasy GameManager.

	Level* getCurrentLevel(void) { return this->m_Level; } // Metoda zwracaj�ca aktualny poziom gry.
	Player* getPlayer(void) { return this->m_Player; } // Metoda zwracaj�ca obiekt gracza.
	RenderWindow* getWindow(void) { return this->m_Window; } // Metoda zwracaj�ca obiekt okna.
	int getGameStatus(void) { return this->m_GameState; } // Metoda zwracaj�ca status gry.
	Event* getEvent(void) { return this->m_Event; } // Metoda zwracaj�ca obiekt zdarzenia.
	Clock* getClock(void) { return this->m_Clock; } // Metoda zwracaj�ca obiekt zegara.
	float getElapsedTime(void) { return this->m_ElapsedTime; } // Metoda zwracaj�ca up�yni�ty czas.
	EnemySpawner* getEnemySpawner(void) { return this->m_EnemySpawner; } // Metoda zwracaj�ca obiekt generuj�cy wrog�w.
	KillCount* getKillCount(void) { return this->m_KillCount; } // Metoda zwracaj�ca obiekt licz�cy ilo�� zabitych wrog�w.
	Menu* getMenu(void) { return this->m_Menu; } // Metoda zwracaj�ca aktualne menu.
	ScoreBoard* getScoreBoard(void) { return this->m_ScoreBoard; } // Metoda zwracaj�ca tablic� wynik�w.

	void setMenu(string); // Metoda ustawiaj�ca aktualne menu.

	void restartGame(void); // Metoda restartuj�ca gr�.
	void exitGame(void); // Metoda ko�cz�ca gr�.
};
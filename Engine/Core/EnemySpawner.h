#pragma once
#include "../NPC/Enemy.h"

/*
	EnemySpawner jest klas� odpowiedzialn� za generowanie wrog�w w grze.
	Przechowuje wektor wska�nik�w na obiekty wrog�w oraz liczb� up�yni�tego czasu od ostatniego od�wie�enia.
	Posiada wska�nik na obiekt klasy GameManager, kt�ry umo�liwia dost�p do innych element�w gry.

	Metody klasy EnemySpawner umo�liwiaj� dodawanie wrog�w do wektora, ponowne �adowanie wrog�w oraz aktualizacj� stanu wrog�w.
	Metoda getEnemies zwraca wska�nik na wektor wrog�w, aby inne cz�ci gry mog�y mie� do nich dost�p.

	Klasa EnemySpawner jest �ci�le powi�zana z klas� GameManager, poniewa� u�ywa wska�nika na ten obiekt do koordynacji generowania wrog�w w grze.
	Jest to wa�ny element odpowiedzialny za tworzenie i zarz�dzanie wrogami w �rodowisku gry.
*/

class EnemySpawner {
private:
	vector<Enemy*>* m_Enemies; // Wektor wska�nik�w na obiekty wrog�w.
	float m_ElapsedTime; // Czas, kt�ry up�yn�� od ostatniego od�wie�enia.

	class GameManager* m_GameManager; // Wska�nik na obiekt klasy GameManager.
public:
	EnemySpawner(class GameManager*); // Konstruktor klasy EnemySpawner.

	vector<Enemy*>* getEnemies(void) { return this->m_Enemies; } // Metoda zwracaj�ca wska�nik na wektor wrog�w.

	void addEnemy(Enemy*); // Metoda dodaj�ca wroga.

	void reload(void); // Metoda ponownie �adowuj�ca wrog�w.

	void update(void); // Metoda aktualizuj�ca stan wrog�w.
};
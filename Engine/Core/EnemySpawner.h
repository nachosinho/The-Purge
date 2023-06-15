#pragma once
#include "../NPC/Enemy.h"

/*
	EnemySpawner jest klas¹ odpowiedzialn¹ za generowanie wrogów w grze.
	Przechowuje wektor wskaŸników na obiekty wrogów oraz liczbê up³yniêtego czasu od ostatniego odœwie¿enia.
	Posiada wskaŸnik na obiekt klasy GameManager, który umo¿liwia dostêp do innych elementów gry.

	Metody klasy EnemySpawner umo¿liwiaj¹ dodawanie wrogów do wektora, ponowne ³adowanie wrogów oraz aktualizacjê stanu wrogów.
	Metoda getEnemies zwraca wskaŸnik na wektor wrogów, aby inne czêœci gry mog³y mieæ do nich dostêp.

	Klasa EnemySpawner jest œciœle powi¹zana z klas¹ GameManager, poniewa¿ u¿ywa wskaŸnika na ten obiekt do koordynacji generowania wrogów w grze.
	Jest to wa¿ny element odpowiedzialny za tworzenie i zarz¹dzanie wrogami w œrodowisku gry.
*/

class EnemySpawner {
private:
	vector<Enemy*>* m_Enemies; // Wektor wskaŸników na obiekty wrogów.
	float m_ElapsedTime; // Czas, który up³yn¹³ od ostatniego odœwie¿enia.

	class GameManager* m_GameManager; // WskaŸnik na obiekt klasy GameManager.
public:
	EnemySpawner(class GameManager*); // Konstruktor klasy EnemySpawner.

	vector<Enemy*>* getEnemies(void) { return this->m_Enemies; } // Metoda zwracaj¹ca wskaŸnik na wektor wrogów.

	void addEnemy(Enemy*); // Metoda dodaj¹ca wroga.

	void reload(void); // Metoda ponownie ³adowuj¹ca wrogów.

	void update(void); // Metoda aktualizuj¹ca stan wrogów.
};
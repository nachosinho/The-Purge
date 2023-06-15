#pragma once
#include "NPC.h"

/*
	Enemy jest klas¹ reprezentuj¹c¹ przeciwnika w grze.
	Jest pochodn¹ klasy NPC i dziedziczy po niej. Klasa nie posiada dodatkowych pól.

	Konstruktor klasy Enemy przyjmuje wskaŸnik na obiekt klasy GameManager i inicjalizuje przeciwnika.

	Metody klasy Enemy s³u¿¹ do zarz¹dzania animacjami, efektami dŸwiêkowymi,
	kontrolowania animacji i ruchu przeciwnika, resetowania przeciwnika oraz renderowania go.

	Klasa Enemy reprezentuje przeciwnika w grze i zawiera logikê zwi¹zan¹ z jego zachowaniem i wygl¹dem.
	Jest pochodn¹ klasy NPC i dziedziczy po niej, co umo¿liwia wspólne funkcje i w³aœciwoœci z innymi obiektami NPC.
*/

class Enemy : public NPC {
private:
	// Brak dodatkowych pól.
public:
	Enemy(class GameManager*); // Konstruktor klasy Enemy.

	void loadAnimations(void); // Metoda wczytuj¹ca animacje przeciwnika.
	void loadSFXs(void); // Metoda wczytuj¹ca efekty dŸwiêkowe przeciwnika.
	void animationControl(void); // Metoda kontroluj¹ca animacjê przeciwnika.
	void moveControl(void); // Metoda kontroluj¹ca ruch przeciwnika.
	void reset(void); // Metoda resetuj¹ca przeciwnika.

	void render(void); // Metoda renderuj¹ca przeciwnika.
};
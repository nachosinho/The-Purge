#pragma once
#include "NPC.h"

/*
	Enemy jest klas� reprezentuj�c� przeciwnika w grze.
	Jest pochodn� klasy NPC i dziedziczy po niej. Klasa nie posiada dodatkowych p�l.

	Konstruktor klasy Enemy przyjmuje wska�nik na obiekt klasy GameManager i inicjalizuje przeciwnika.

	Metody klasy Enemy s�u�� do zarz�dzania animacjami, efektami d�wi�kowymi,
	kontrolowania animacji i ruchu przeciwnika, resetowania przeciwnika oraz renderowania go.

	Klasa Enemy reprezentuje przeciwnika w grze i zawiera logik� zwi�zan� z jego zachowaniem i wygl�dem.
	Jest pochodn� klasy NPC i dziedziczy po niej, co umo�liwia wsp�lne funkcje i w�a�ciwo�ci z innymi obiektami NPC.
*/

class Enemy : public NPC {
private:
	// Brak dodatkowych p�l.
public:
	Enemy(class GameManager*); // Konstruktor klasy Enemy.

	void loadAnimations(void); // Metoda wczytuj�ca animacje przeciwnika.
	void loadSFXs(void); // Metoda wczytuj�ca efekty d�wi�kowe przeciwnika.
	void animationControl(void); // Metoda kontroluj�ca animacj� przeciwnika.
	void moveControl(void); // Metoda kontroluj�ca ruch przeciwnika.
	void reset(void); // Metoda resetuj�ca przeciwnika.

	void render(void); // Metoda renderuj�ca przeciwnika.
};
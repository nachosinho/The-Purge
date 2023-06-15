#pragma once
#include "SFX.h"

/*
	Level jest klas� reprezentuj�c� poziom gry.
	Jest pochodn� klasy Sprite i dziedziczy po niej. Klasa przechowuje wska�niki na tekstur� obiektu Level oraz obiekt efekt�w d�wi�kowych (SFX).
	Posiada tak�e wska�nik na obiekt klasy GameManager, umo�liwiaj�cy dost�p do zarz�dcy gry.

	Metody klasy Level umo�liwiaj� uzyskiwanie i ustawianie obiektu efekt�w d�wi�kowych, dodawanie tekstury, zarz�dzanie muzyk� oraz renderowanie obrazu.

	Klasa Level jest istotnym elementem gry, reprezentuj�cym konkretny poziom, jego wygl�d, efekty d�wi�kowe i renderowanie.
	Jest powi�zana z klas� GameManager, kt�ra zarz�dza ca�� gr�.
*/

class Level : public Sprite {
private:
	Texture* m_Texture; // Wska�nik na tekstur� obiektu Level.
	SFX* m_SFX; // Wska�nik na obiekt efekt�w d�wi�kowych.

	class GameManager* m_GameManager; // Wska�nik na obiekt klasy GameManager.
public:
	Level(class GameManager*); // Konstruktor klasy Level.

	SFX* getSFX(void) { return this->m_SFX; } // Metoda zwracaj�ca wska�nik na obiekt efekt�w d�wi�kowych.

	void setSFX(SFX*); // Metoda ustawiaj�ca obiekt efekt�w d�wi�kowych.

	void addTexture(string); // Metoda dodaj�ca tekstur�.
	void manageMusic(void); // Metoda zarz�dzaj�ca muzyk�.

	void render(void); // Metoda renderuj�ca obraz.
};
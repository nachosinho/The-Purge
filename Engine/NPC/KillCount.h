#pragma once
#include "../include.h"

/*
	KillCount jest klas� reprezentuj�c� licznik zab�jstw w grze.
	Jest pochodn� klasy Sprite i dziedziczy po niej.
	Posiada pola przechowuj�ce wska�niki na tekstur� licznika, czcionk�, tekst oraz liczb� zab�jstw.
	Zawiera r�wnie� wska�nik na obiekt klasy GameManager.

	Konstruktor klasy KillCount przyjmuje wska�nik na obiekt klasy GameManager i inicjalizuje licznik zab�jstw.

	Metody klasy KillCount umo�liwiaj� uzyskiwanie informacji o liczbie zab�jstw,
	ustawianie liczby zab�jstw oraz aktualizowanie tekstu licznika zab�jstw.
	Metoda render renderuje licznik zab�jstw.

	Klasa KillCount reprezentuje licznik zab�jstw w grze.
	Przechowuje informacje o liczbie zab�jstw oraz wy�wietla t� informacj� w postaci tekstu na ekranie.
*/

class KillCount : public Sprite {
private:
	Texture* m_Texture; // Wska�nik na tekstur� licznika zab�jstw.
	Font* m_Font; // Wska�nik na czcionk� licznika zab�jstw.
	Text* m_Text; // Wska�nik na tekst licznika zab�jstw.
	int m_Score; // Liczba zab�jstw.
	class GameManager* m_GameManager; // Wska�nik na obiekt klasy GameManager.

public:
	KillCount(class GameManager*); // Konstruktor klasy KillCount.

	int getScore(void) { return this->m_Score; } // Metoda zwracaj�ca liczb� zab�jstw.

	void setScore(int); // Metoda ustawiaj�ca liczb� zab�jstw.
	void updateText(void); // Metoda aktualizuj�ca tekst licznika zab�jstw.

	void render(void); // Metoda renderuj�ca licznik zab�jstw.
};
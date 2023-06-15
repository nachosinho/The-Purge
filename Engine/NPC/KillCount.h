#pragma once
#include "../include.h"

/*
	KillCount jest klas¹ reprezentuj¹c¹ licznik zabójstw w grze.
	Jest pochodn¹ klasy Sprite i dziedziczy po niej.
	Posiada pola przechowuj¹ce wskaŸniki na teksturê licznika, czcionkê, tekst oraz liczbê zabójstw.
	Zawiera równie¿ wskaŸnik na obiekt klasy GameManager.

	Konstruktor klasy KillCount przyjmuje wskaŸnik na obiekt klasy GameManager i inicjalizuje licznik zabójstw.

	Metody klasy KillCount umo¿liwiaj¹ uzyskiwanie informacji o liczbie zabójstw,
	ustawianie liczby zabójstw oraz aktualizowanie tekstu licznika zabójstw.
	Metoda render renderuje licznik zabójstw.

	Klasa KillCount reprezentuje licznik zabójstw w grze.
	Przechowuje informacje o liczbie zabójstw oraz wyœwietla tê informacjê w postaci tekstu na ekranie.
*/

class KillCount : public Sprite {
private:
	Texture* m_Texture; // WskaŸnik na teksturê licznika zabójstw.
	Font* m_Font; // WskaŸnik na czcionkê licznika zabójstw.
	Text* m_Text; // WskaŸnik na tekst licznika zabójstw.
	int m_Score; // Liczba zabójstw.
	class GameManager* m_GameManager; // WskaŸnik na obiekt klasy GameManager.

public:
	KillCount(class GameManager*); // Konstruktor klasy KillCount.

	int getScore(void) { return this->m_Score; } // Metoda zwracaj¹ca liczbê zabójstw.

	void setScore(int); // Metoda ustawiaj¹ca liczbê zabójstw.
	void updateText(void); // Metoda aktualizuj¹ca tekst licznika zabójstw.

	void render(void); // Metoda renderuj¹ca licznik zabójstw.
};
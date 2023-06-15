#pragma once
#include "../include.h"

/*
	Klasa AmmoInfo dziedziczy po klasie Sprite i reprezentuje informacje o amunicji.
	Posiada pola przechowuj¹ce wskaŸniki na obiekt RenderWindow, teksturê amunicji, czcionkê amunicji oraz tekst amunicji.
	Zawiera tak¿e informacje o minimalnej i maksymalnej wartoœci amunicji oraz wskaŸnik na obiekt klasy Gun.

	Konstruktor klasy AmmoInfo przyjmuje wskaŸnik na obiekt klasy Gun oraz wskaŸnik na obiekt RenderWindow i inicjalizuje pola zwi¹zane z grafik¹ i czcionk¹.

	Metody klasy AmmoInfo umo¿liwiaj¹ aktualizacjê tekstu amunicji, ustawianie minimalnej i maksymalnej wartoœci amunicji,
	zmianê broni oraz renderowanie informacji o amunicji.

	Klasa AmmoInfo jest odpowiedzialna za wyœwietlanie graficznych informacji o aktualnej amunicji i jej wartoœci.
*/

class AmmoInfo : public Sprite {
private:
	RenderWindow* m_RenderWindow; // WskaŸnik na obiekt RenderWindow.
	Texture* m_AmmoTexture; // WskaŸnik na teksturê amunicji.
	Font* m_AmmoFont; // WskaŸnik na czcionkê amunicji.
	Text* m_AmmoText; // WskaŸnik na tekst amunicji.

	int m_Min, m_Max; // Minimalna i maksymalna wartoœæ amunicji.

	class Gun* m_Gun; // WskaŸnik na obiekt klasy Gun.
public:
	AmmoInfo(class Gun*, RenderWindow*); // Konstruktor klasy AmmoInfo.

	void updateText(void); // Metoda aktualizuj¹ca tekst amunicji.

	void setMin(int); // Metoda ustawiaj¹ca minimaln¹ wartoœæ amunicji.
	void setMax(int); // Metoda ustawiaj¹ca maksymaln¹ wartoœæ amunicji.

	void changeGun(class Gun*); // Metoda zmieniaj¹ca broñ.

	void render(void); // Metoda renderuj¹ca amunicjê.
};
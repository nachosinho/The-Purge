#pragma once
#include "../include.h"

/*
	Klasa AmmoInfo dziedziczy po klasie Sprite i reprezentuje informacje o amunicji.
	Posiada pola przechowuj�ce wska�niki na obiekt RenderWindow, tekstur� amunicji, czcionk� amunicji oraz tekst amunicji.
	Zawiera tak�e informacje o minimalnej i maksymalnej warto�ci amunicji oraz wska�nik na obiekt klasy Gun.

	Konstruktor klasy AmmoInfo przyjmuje wska�nik na obiekt klasy Gun oraz wska�nik na obiekt RenderWindow i inicjalizuje pola zwi�zane z grafik� i czcionk�.

	Metody klasy AmmoInfo umo�liwiaj� aktualizacj� tekstu amunicji, ustawianie minimalnej i maksymalnej warto�ci amunicji,
	zmian� broni oraz renderowanie informacji o amunicji.

	Klasa AmmoInfo jest odpowiedzialna za wy�wietlanie graficznych informacji o aktualnej amunicji i jej warto�ci.
*/

class AmmoInfo : public Sprite {
private:
	RenderWindow* m_RenderWindow; // Wska�nik na obiekt RenderWindow.
	Texture* m_AmmoTexture; // Wska�nik na tekstur� amunicji.
	Font* m_AmmoFont; // Wska�nik na czcionk� amunicji.
	Text* m_AmmoText; // Wska�nik na tekst amunicji.

	int m_Min, m_Max; // Minimalna i maksymalna warto�� amunicji.

	class Gun* m_Gun; // Wska�nik na obiekt klasy Gun.
public:
	AmmoInfo(class Gun*, RenderWindow*); // Konstruktor klasy AmmoInfo.

	void updateText(void); // Metoda aktualizuj�ca tekst amunicji.

	void setMin(int); // Metoda ustawiaj�ca minimaln� warto�� amunicji.
	void setMax(int); // Metoda ustawiaj�ca maksymaln� warto�� amunicji.

	void changeGun(class Gun*); // Metoda zmieniaj�ca bro�.

	void render(void); // Metoda renderuj�ca amunicj�.
};
#pragma once
#include "../include.h"

/*
	HealthBar jest klas� reprezentuj�c� pasek zdrowia w grze.
	Posiada pola przechowuj�ce wska�niki na prostok�ty reprezentuj�ce t�o i przedni� cz�� paska zdrowia,
	wska�nik na obiekt RenderWindow oraz wska�nik na obiekt klasy NPC, z kt�rym pasek zdrowia jest powi�zany.

	Konstruktor klasy HealthBar przyjmuje wska�nik na obiekt klasy NPC oraz wska�nik na obiekt RenderWindow i inicjalizuje pasek zdrowia.

	Metody klasy HealthBar umo�liwiaj� ustawianie koloru, procentowego wype�nienia oraz pozycji paska zdrowia. Metoda render renderuje pasek zdrowia.

	Klasa HealthBar jest odpowiedzialna za wy�wietlanie paska zdrowia dla obiektu klasy NPC w grze.
	Przechowuje informacje o wygl�dzie i po�o�eniu paska zdrowia oraz umo�liwia aktualizowanie tych informacji w zale�no�ci od stanu zdrowia obiektu NPC.
*/

class HealthBar {
private:
	RectangleShape* m_HealthBarBack; // Wska�nik na prostok�t reprezentuj�cy t�o paska zdrowia.
	RectangleShape* m_HealthBarFront; // Wska�nik na prostok�t reprezentuj�cy przedni� cz�� paska zdrowia.
	RenderWindow* m_RenderWindow; // Wska�nik na obiekt RenderWindow.
	class NPC* m_NPC; // Wska�nik na obiekt klasy NPC.
public:
	HealthBar(class NPC*, RenderWindow*); // Konstruktor klasy HealthBar.

	Vector2f getPosition(void) { return this->m_HealthBarBack->getPosition(); } // Metoda zwracaj�ca pozycj� t�a paska zdrowia.
	Vector2f getSize(void) { return this->m_HealthBarBack->getSize(); } // Metoda zwracaj�ca rozmiar t�a paska zdrowia.

	void setColor(Color); // Metoda ustawiaj�ca kolor paska zdrowia.
	void setPercentage(float); // Metoda ustawiaj�ca procentowe wype�nienie paska zdrowia.
	void setPosition(float, float); // Metoda ustawiaj�ca pozycj� paska zdrowia na podstawie wsp�rz�dnych x i y.
	void setPosition(Vector2f); // Metoda ustawiaj�ca pozycj� paska zdrowia na podstawie wektora pozycji.

	void render(void); // Metoda renderuj�ca pasek zdrowia.
};
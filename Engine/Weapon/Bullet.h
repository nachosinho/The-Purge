#pragma once
#include "../include.h"

/*
	Klasa Bullet dziedziczy po klasie Sprite i reprezentuje pocisk.
	Posiada pola przechowuj¹ce wskaŸniki na teksturê pocisku oraz obiekt klasy Weapon, którym zosta³ wystrzelony.

	Konstruktor klasy Bullet przyjmuje wskaŸnik na obiekt klasy Weapon oraz opcjonalny parametr okreœlaj¹cy specjalne zachowanie pocisku (domyœlnie ustawiony na 0).

	Metoda update aktualizuje stan pocisku na podstawie obiektu RenderWindow, tak aby odpowiednio porusza³ siê po ekranie.

	Klasa Bullet odpowiada za reprezentacjê i zachowanie pojedynczego pocisku wystrzelonego przez broñ.
*/

class Bullet : public Sprite {
private:
	Texture* m_Texture; // WskaŸnik na teksturê pocisku.
	class Weapon* m_Weapon; // WskaŸnik na obiekt klasy Weapon.
public:
	Bullet(class Weapon*, int = 0); // Konstruktor klasy Bullet.

	void update(RenderWindow*); // Metoda aktualizuj¹ca pocisk.
};
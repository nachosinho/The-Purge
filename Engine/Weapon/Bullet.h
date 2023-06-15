#pragma once
#include "../include.h"

/*
	Klasa Bullet dziedziczy po klasie Sprite i reprezentuje pocisk.
	Posiada pola przechowuj�ce wska�niki na tekstur� pocisku oraz obiekt klasy Weapon, kt�rym zosta� wystrzelony.

	Konstruktor klasy Bullet przyjmuje wska�nik na obiekt klasy Weapon oraz opcjonalny parametr okre�laj�cy specjalne zachowanie pocisku (domy�lnie ustawiony na 0).

	Metoda update aktualizuje stan pocisku na podstawie obiektu RenderWindow, tak aby odpowiednio porusza� si� po ekranie.

	Klasa Bullet odpowiada za reprezentacj� i zachowanie pojedynczego pocisku wystrzelonego przez bro�.
*/

class Bullet : public Sprite {
private:
	Texture* m_Texture; // Wska�nik na tekstur� pocisku.
	class Weapon* m_Weapon; // Wska�nik na obiekt klasy Weapon.
public:
	Bullet(class Weapon*, int = 0); // Konstruktor klasy Bullet.

	void update(RenderWindow*); // Metoda aktualizuj�ca pocisk.
};
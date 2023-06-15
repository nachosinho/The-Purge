#pragma once
#include "Gun.h"

/*
	Klasa Pistol dziedziczy po klasie Gun i reprezentuje pistolet.

	Konstruktor klasy Pistol przyjmuje wska�nik na obiekt klasy GameManager oraz wska�nik na obiekt klasy NPC i inicjalizuje odpowiednie pola.

	Metoda shoot jest odpowiedzialna za wykonanie strza�u z pistoletu.
*/

class Pistol : public Gun {
public:
	Pistol(class GameManager*, class NPC*); // Konstruktor klasy Pistol.

	void shoot(void); // Metoda wykonuj�ca strza� z pistoletu.
};
#pragma once
#include "Gun.h"

/*
	Klasa Pistol dziedziczy po klasie Gun i reprezentuje pistolet.

	Konstruktor klasy Pistol przyjmuje wskaünik na obiekt klasy GameManager oraz wskaünik na obiekt klasy NPC i inicjalizuje odpowiednie pola.

	Metoda shoot jest odpowiedzialna za wykonanie strza≥u z pistoletu.
*/

class Pistol : public Gun {
public:
	Pistol(class GameManager*, class NPC*); // Konstruktor klasy Pistol.

	void shoot(void); // Metoda wykonujπca strza≥ z pistoletu.
};
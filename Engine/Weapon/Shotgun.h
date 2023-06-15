#pragma once
#include "Gun.h"

/*
	Klasa Shotgun dziedziczy po klasie Gun i reprezentuje shotgun.

	Konstruktor klasy Shotgun przyjmuje wskaünik na obiekt klasy GameManager oraz wskaünik na obiekt klasy NPC i inicjalizuje odpowiednie pola.

	Metoda shoot jest odpowiedzialna za wykonanie strza≥u z shotgunu.
*/

class Shotgun : public Gun {
public:
	Shotgun(class GameManager*, class NPC*); // Konstruktor klasy Shotgun.

	void shoot(void); // Metoda wykonujπca strza≥ z shotgunu.
};
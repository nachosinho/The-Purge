#pragma once
#include "Gun.h"

/*
	Klasa Shotgun dziedziczy po klasie Gun i reprezentuje shotgun.

	Konstruktor klasy Shotgun przyjmuje wska�nik na obiekt klasy GameManager oraz wska�nik na obiekt klasy NPC i inicjalizuje odpowiednie pola.

	Metoda shoot jest odpowiedzialna za wykonanie strza�u z shotgunu.
*/

class Shotgun : public Gun {
public:
	Shotgun(class GameManager*, class NPC*); // Konstruktor klasy Shotgun.

	void shoot(void); // Metoda wykonuj�ca strza� z shotgunu.
};
#pragma once
#include "Gun.h"

/*
	Klasa Rifle dziedziczy po klasie Gun i reprezentuje karabin.

	Konstruktor klasy Rifle przyjmuje wska�nik na obiekt klasy GameManager oraz wska�nik na obiekt klasy NPC i inicjalizuje odpowiednie pola.

	Metoda shoot jest odpowiedzialna za wykonanie strza�u z karabinu.
*/

class Rifle : public Gun {
public:
	Rifle(class GameManager*, class NPC*); // Konstruktor klasy Rifle.

	void shoot(void); // Metoda wykonuj�ca strza� z karabinu.
};
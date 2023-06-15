#pragma once
#include "Weapon.h"

/*
	Klasa Melee dziedziczy po klasie Weapon i reprezentuje bro� typu Melee.

	Konstruktor klasy Melee przyjmuje wska�nik na obiekt klasy GameManager oraz wska�nik na obiekt klasy NPC i inicjalizuje odpowiednie pola.

	Metoda attack s�u�y do atakowania innego obiektu klasy NPC za pomoc� broni typu Melee.

	Metoda update jest odpowiedzialna za aktualizacj� stanu broni typu Melee.
*/

class Melee : public Weapon {
private:
public:
	Melee(class GameManager*, class NPC*);

	void attack(class NPC*);
	void update(void);
};
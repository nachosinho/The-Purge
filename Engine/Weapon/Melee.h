#pragma once
#include "Weapon.h"

/*
	Klasa Melee dziedziczy po klasie Weapon i reprezentuje broñ typu Melee.

	Konstruktor klasy Melee przyjmuje wskaŸnik na obiekt klasy GameManager oraz wskaŸnik na obiekt klasy NPC i inicjalizuje odpowiednie pola.

	Metoda attack s³u¿y do atakowania innego obiektu klasy NPC za pomoc¹ broni typu Melee.

	Metoda update jest odpowiedzialna za aktualizacjê stanu broni typu Melee.
*/

class Melee : public Weapon {
private:
public:
	Melee(class GameManager*, class NPC*);

	void attack(class NPC*);
	void update(void);
};
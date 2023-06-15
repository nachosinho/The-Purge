#pragma once
#include "NPC.h"
#include "../Weapon/AmmoInfo.h"
#include "../Weapon/Weapon.h"

/*
	Player jest klas� dziedzicz�c� po klasie NPC i reprezentuje gracza w grze.
	Posiada dodatkowe pola, takie jak wska�nik na informacje o amunicji gracza oraz wska�nik na wektor broni gracza.

	Konstruktor klasy Player przyjmuje wska�nik na obiekt klasy GameManager i inicjalizuje pola zwi�zane z informacjami o amunicji i broni gracza.

	Metody klasy Player umo�liwiaj� uzyskiwanie informacji o amunicji i broni gracza,
	wczytywanie animacji i efekt�w d�wi�kowych, kontrolowanie animacji, kontrolowanie ruchu,
	resetowanie stanu gracza oraz renderowanie gracza.

	Klasa Player rozszerza funkcjonalno�� klasy NPC, dodaj�c specyficzne dla gracza elementy, takie jak informacje o amunicji i posiadane bronie.
*/

class Player : public NPC {
private:
	AmmoInfo* m_AmmoInfo; // Wska�nik na informacje o amunicji gracza.
	vector<Weapon*>* m_Weapons; // Wska�nik na wektor broni gracza.
public:
	Player(class GameManager*); // Konstruktor klasy Player.

	AmmoInfo* getAmmoInfo(void) { return this->m_AmmoInfo; } // Metoda zwracaj�ca informacje o amunicji gracza.
	vector<Weapon*>* getWeapons(void) { return this->m_Weapons; } // Metoda zwracaj�ca wektor broni gracza.

	void loadAnimations(void); // Metoda wczytuj�ca animacje gracza.
	void loadSFXs(void); // Metoda wczytuj�ca efekty d�wi�kowe gracza.
	void animationControl(void); // Metoda kontroluj�ca animacj� gracza.
	void moveControl(void); // Metoda kontroluj�ca ruch gracza.
	void reset(void); // Metoda resetuj�ca stan gracza.

	void render(void); // Metoda renderuj�ca gracza.
};
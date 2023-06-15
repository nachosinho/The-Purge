#pragma once
#include "NPC.h"
#include "../Weapon/AmmoInfo.h"
#include "../Weapon/Weapon.h"

/*
	Player jest klasπ dziedziczπcπ po klasie NPC i reprezentuje gracza w grze.
	Posiada dodatkowe pola, takie jak wskaünik na informacje o amunicji gracza oraz wskaünik na wektor broni gracza.

	Konstruktor klasy Player przyjmuje wskaünik na obiekt klasy GameManager i inicjalizuje pola zwiπzane z informacjami o amunicji i broni gracza.

	Metody klasy Player umoøliwiajπ uzyskiwanie informacji o amunicji i broni gracza,
	wczytywanie animacji i efektÛw düwiÍkowych, kontrolowanie animacji, kontrolowanie ruchu,
	resetowanie stanu gracza oraz renderowanie gracza.

	Klasa Player rozszerza funkcjonalnoúÊ klasy NPC, dodajπc specyficzne dla gracza elementy, takie jak informacje o amunicji i posiadane bronie.
*/

class Player : public NPC {
private:
	AmmoInfo* m_AmmoInfo; // Wskaünik na informacje o amunicji gracza.
	vector<Weapon*>* m_Weapons; // Wskaünik na wektor broni gracza.
public:
	Player(class GameManager*); // Konstruktor klasy Player.

	AmmoInfo* getAmmoInfo(void) { return this->m_AmmoInfo; } // Metoda zwracajπca informacje o amunicji gracza.
	vector<Weapon*>* getWeapons(void) { return this->m_Weapons; } // Metoda zwracajπca wektor broni gracza.

	void loadAnimations(void); // Metoda wczytujπca animacje gracza.
	void loadSFXs(void); // Metoda wczytujπca efekty düwiÍkowe gracza.
	void animationControl(void); // Metoda kontrolujπca animacjÍ gracza.
	void moveControl(void); // Metoda kontrolujπca ruch gracza.
	void reset(void); // Metoda resetujπca stan gracza.

	void render(void); // Metoda renderujπca gracza.
};
#pragma once
#include "Bullet.h"

/*
	Klasa Weapon jest klas¹ bazow¹ dla ró¿nych rodzajów broni.
	Zawiera podstawowe w³aœciwoœci broni, takie jak obra¿enia, czas odnowienia, opóŸnienie miêdzy strza³ami, nazwa itp.

	Konstruktor klasy Weapon przyjmuje wskaŸnik na obiekt klasy GameManager oraz wskaŸnik na obiekt klasy NPC i inicjalizuje odpowiednie pola.

	Metoda getDamage zwraca wartoœæ obra¿eñ broni, a metoda getName zwraca nazwê broni.
	Metoda getCooldown zwraca czas odnowienia broni, a metoda getDelay zwraca opóŸnienie miêdzy strza³ami broni.

	Metoda equipNextWeapon prze³¹cza na nastêpn¹ broñ, a metoda setDamage ustawia wartoœæ obra¿eñ broni.
	Metoda setCooldown ustawia czas odnowienia broni, a metoda setDelay ustawia opóŸnienie miêdzy strza³ami broni.
	Metoda switchWeapon prze³¹cza na okreœlon¹ broñ.

	Metoda getOwner zwraca w³aœciciela broni.

	Metoda reset resetuje ustawienia broni, a metoda update jest metod¹ czysto wirtualn¹,
	która musi byæ zaimplementowana w klasach pochodnych i aktualizuje stan broni.
*/

class Weapon {
protected:
	float m_Cooldown, m_Delay;
	int m_Damage;
	string m_Name;

	int m_NextWeapon, m_WeaponType;

	class GameManager* m_GameManager;
	class NPC* m_Owner;

public:
	Weapon(class GameManager*, class NPC*); // Konstruktor klasy Weapon.

	enum WEAPONTYPE { PISTOL, RIFLE, SHOTGUN, MELEE, NONE }; // Typy broni.

	int getDamage(void) { return this->m_Damage; } // Metoda zwracaj¹ca wartoœæ obra¿eñ broni.
	string getName(void) { return this->m_Name; } // Metoda zwracaj¹ca nazwê broni.
	float getCooldown(void) { return this->m_Cooldown; } // Metoda zwracaj¹ca czas odnowienia broni.
	float getDelay(void) { return this->m_Delay; } // Metoda zwracaj¹ca opóŸnienie miêdzy strza³ami broni.

	int getNextWeapon(void) { return this->m_NextWeapon; } // Metoda zwracaj¹ca numer nastêpnej broni.

	void equipNextWeapon(void); // Metoda prze³¹czaj¹ca na nastêpn¹ broñ.
	void setDamage(int); // Metoda ustawiaj¹ca wartoœæ obra¿eñ broni.
	void setCooldown(float); // Metoda ustawiaj¹ca czas odnowienia broni.
	void setDelay(float); // Metoda ustawiaj¹ca opóŸnienie miêdzy strza³ami broni.
	void switchWeapon(int); // Metoda prze³¹czaj¹ca na okreœlon¹ broñ.

	class NPC* getOwner(void) { return this->m_Owner; } // Metoda zwracaj¹ca w³aœciciela broni.

	void reset(void); // Metoda resetuj¹ca ustawienia broni.
	virtual void update(void) = 0; // Metoda aktualizuj¹ca stan broni.

	// Pistol, Rifle, Shotgun, Melee
	const int DEFAULT_MAX_AMMO[3] = { 7, 30, 2 }; // Domyœlna maksymalna iloœæ amunicji dla ró¿nych rodzajów broni.
	const int DEFAULT_DAMAGE[4] = { 25, 10, 50, 15 }; // Domyœlne obra¿enia dla ró¿nych rodzajów broni.
	const float DEFAULT_DELAY[4] = { 0.5f, 0.05f, 1.75f, 1.f }; // Domyœlne opóŸnienie miêdzy strza³ami dla ró¿nych rodzajów broni.
	const float DEFAULT_BULLET_VELOCITY[3] = { 5.f, 7.5f, 4.f }; // Domyœlna prêdkoœæ pocisków dla ró¿nych rodzajów broni.
};
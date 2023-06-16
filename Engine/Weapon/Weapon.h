#pragma once
#include "Bullet.h"

/*
	Klasa Weapon jest klas� bazow� dla r�nych rodzaj�w broni.
	Zawiera podstawowe w�a�ciwo�ci broni, takie jak obra�enia, czas odnowienia, op�nienie mi�dzy strza�ami, nazwa itp.

	Konstruktor klasy Weapon przyjmuje wska�nik na obiekt klasy GameManager oraz wska�nik na obiekt klasy NPC i inicjalizuje odpowiednie pola.

	Metoda getDamage zwraca warto�� obra�e� broni, a metoda getName zwraca nazw� broni.
	Metoda getCooldown zwraca czas odnowienia broni, a metoda getDelay zwraca op�nienie mi�dzy strza�ami broni.

	Metoda equipNextWeapon prze��cza na nast�pn� bro�, a metoda setDamage ustawia warto�� obra�e� broni.
	Metoda setCooldown ustawia czas odnowienia broni, a metoda setDelay ustawia op�nienie mi�dzy strza�ami broni.
	Metoda switchWeapon prze��cza na okre�lon� bro�.

	Metoda getOwner zwraca w�a�ciciela broni.

	Metoda reset resetuje ustawienia broni, a metoda update jest metod� czysto wirtualn�,
	kt�ra musi by� zaimplementowana w klasach pochodnych i aktualizuje stan broni.
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

	int getDamage(void) { return this->m_Damage; } // Metoda zwracaj�ca warto�� obra�e� broni.
	string getName(void) { return this->m_Name; } // Metoda zwracaj�ca nazw� broni.
	float getCooldown(void) { return this->m_Cooldown; } // Metoda zwracaj�ca czas odnowienia broni.
	float getDelay(void) { return this->m_Delay; } // Metoda zwracaj�ca op�nienie mi�dzy strza�ami broni.

	int getNextWeapon(void) { return this->m_NextWeapon; } // Metoda zwracaj�ca numer nast�pnej broni.

	void equipNextWeapon(void); // Metoda prze��czaj�ca na nast�pn� bro�.
	void setDamage(int); // Metoda ustawiaj�ca warto�� obra�e� broni.
	void setCooldown(float); // Metoda ustawiaj�ca czas odnowienia broni.
	void setDelay(float); // Metoda ustawiaj�ca op�nienie mi�dzy strza�ami broni.
	void switchWeapon(int); // Metoda prze��czaj�ca na okre�lon� bro�.

	class NPC* getOwner(void) { return this->m_Owner; } // Metoda zwracaj�ca w�a�ciciela broni.

	void reset(void); // Metoda resetuj�ca ustawienia broni.
	virtual void update(void) = 0; // Metoda aktualizuj�ca stan broni.

	// Pistol, Rifle, Shotgun, Melee
	const int DEFAULT_MAX_AMMO[3] = { 7, 30, 2 }; // Domy�lna maksymalna ilo�� amunicji dla r�nych rodzaj�w broni.
	const int DEFAULT_DAMAGE[4] = { 25, 10, 50, 15 }; // Domy�lne obra�enia dla r�nych rodzaj�w broni.
	const float DEFAULT_DELAY[4] = { 0.5f, 0.05f, 1.75f, 1.f }; // Domy�lne op�nienie mi�dzy strza�ami dla r�nych rodzaj�w broni.
	const float DEFAULT_BULLET_VELOCITY[3] = { 5.f, 7.5f, 4.f }; // Domy�lna pr�dko�� pocisk�w dla r�nych rodzaj�w broni.
};
#pragma once
#include "Weapon.h"

/*
	Klasa Gun dziedziczy po klasie Weapon i reprezentuje bro� strzelaj�c� pociskami.
	Posiada pola przechowuj�ce informacje o ilo�ci amunicji, maksymalnej ilo�ci amunicji,
	pr�dko�ci pocisk�w oraz wska�nik na wektor pocisk�w wystrzelonych przez bro�.

	Konstruktor klasy Gun przyjmuje wska�niki na obiekty klasy GameManager i NPC i inicjalizuje pola zwi�zane z broni�.

	Metody klasy Gun umo�liwiaj� uzyskanie informacji o pr�dko�ci pocisk�w, ilo�ci amunicji, maksymalnej ilo�ci amunicji oraz wska�nika na wektor pocisk�w.
	Pozwalaj� r�wnie� na ustawienie pr�dko�ci pocisk�w, aktualnej ilo�ci amunicji i maksymalnej ilo�ci amunicji.

	Metoda shoot jest czysto wirtualn� metod�, kt�ra musi by� zaimplementowana w klasach pochodnych i jest odpowiedzialna za wykonanie strza�u z broni.

	Metoda reload s�u�y do prze�adowania broni, a metoda update aktualizuje stan broni, na przyk�ad kontroluje czas mi�dzy kolejnymi strza�ami.

	Klasa Gun odpowiada za reprezentacj� i zachowanie broni palnej, kt�ra mo�e wystrzeliwa� pociski.
*/

class Gun : public Weapon {
protected:
	int m_Ammo; // Aktualna ilo�� amunicji w broni.
	int m_MaxAmmo; // Maksymalna ilo�� amunicji, jak� bro� mo�e pomie�ci�.
	float m_BulletVelocity; // Pr�dko�� pocisk�w wystrzeliwanych z broni.
	vector<Bullet*>* m_Bullets; // Wska�nik na wektor pocisk�w wystrzelonych przez bro�.
public:
	Gun(class GameManager*, class NPC*); // Konstruktor klasy Gun.

	float getBulletVelocity(void) { return this->m_BulletVelocity; } // Metoda zwracaj�ca pr�dko�� pocisk�w.
	int getAmmo(void) { return this->m_Ammo; } // Metoda zwracaj�ca aktualn� ilo�� amunicji.
	int getMaxAmmo(void) { return this->m_MaxAmmo; } // Metoda zwracaj�ca maksymaln� ilo�� amunicji.
	vector<Bullet*>* getBullets(void) { return this->m_Bullets; } // Metoda zwracaj�ca wska�nik na wektor pocisk�w.

	void setBulletVelocity(float); // Metoda ustawiaj�ca pr�dko�� pocisk�w.
	void setAmmo(int); // Metoda ustawiaj�ca aktualn� ilo�� amunicji.
	void setMaxAmmo(int); // Metoda ustawiaj�ca maksymaln� ilo�� amunicji.

	virtual void shoot(void) = 0; // Metoda odpowiedzialna za strza� z broni (implementowana w klasach pochodnych).
	void reload(void); // Metoda prze�adowuj�ca bro�.
	void update(void); // Metoda aktualizuj�ca stan broni.
};
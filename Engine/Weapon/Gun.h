#pragma once
#include "Weapon.h"

/*
	Klasa Gun dziedziczy po klasie Weapon i reprezentuje broñ strzelaj¹c¹ pociskami.
	Posiada pola przechowuj¹ce informacje o iloœci amunicji, maksymalnej iloœci amunicji,
	prêdkoœci pocisków oraz wskaŸnik na wektor pocisków wystrzelonych przez broñ.

	Konstruktor klasy Gun przyjmuje wskaŸniki na obiekty klasy GameManager i NPC i inicjalizuje pola zwi¹zane z broni¹.

	Metody klasy Gun umo¿liwiaj¹ uzyskanie informacji o prêdkoœci pocisków, iloœci amunicji, maksymalnej iloœci amunicji oraz wskaŸnika na wektor pocisków.
	Pozwalaj¹ równie¿ na ustawienie prêdkoœci pocisków, aktualnej iloœci amunicji i maksymalnej iloœci amunicji.

	Metoda shoot jest czysto wirtualn¹ metod¹, która musi byæ zaimplementowana w klasach pochodnych i jest odpowiedzialna za wykonanie strza³u z broni.

	Metoda reload s³u¿y do prze³adowania broni, a metoda update aktualizuje stan broni, na przyk³ad kontroluje czas miêdzy kolejnymi strza³ami.

	Klasa Gun odpowiada za reprezentacjê i zachowanie broni palnej, która mo¿e wystrzeliwaæ pociski.
*/

class Gun : public Weapon {
protected:
	int m_Ammo; // Aktualna iloœæ amunicji w broni.
	int m_MaxAmmo; // Maksymalna iloœæ amunicji, jak¹ broñ mo¿e pomieœciæ.
	float m_BulletVelocity; // Prêdkoœæ pocisków wystrzeliwanych z broni.
	vector<Bullet*>* m_Bullets; // WskaŸnik na wektor pocisków wystrzelonych przez broñ.
public:
	Gun(class GameManager*, class NPC*); // Konstruktor klasy Gun.

	float getBulletVelocity(void) { return this->m_BulletVelocity; } // Metoda zwracaj¹ca prêdkoœæ pocisków.
	int getAmmo(void) { return this->m_Ammo; } // Metoda zwracaj¹ca aktualn¹ iloœæ amunicji.
	int getMaxAmmo(void) { return this->m_MaxAmmo; } // Metoda zwracaj¹ca maksymaln¹ iloœæ amunicji.
	vector<Bullet*>* getBullets(void) { return this->m_Bullets; } // Metoda zwracaj¹ca wskaŸnik na wektor pocisków.

	void setBulletVelocity(float); // Metoda ustawiaj¹ca prêdkoœæ pocisków.
	void setAmmo(int); // Metoda ustawiaj¹ca aktualn¹ iloœæ amunicji.
	void setMaxAmmo(int); // Metoda ustawiaj¹ca maksymaln¹ iloœæ amunicji.

	virtual void shoot(void) = 0; // Metoda odpowiedzialna za strza³ z broni (implementowana w klasach pochodnych).
	void reload(void); // Metoda prze³adowuj¹ca broñ.
	void update(void); // Metoda aktualizuj¹ca stan broni.
};
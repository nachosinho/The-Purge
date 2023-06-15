#pragma once
#include "../Core/SFX.h"
#include "HealthBar.h"
#include "Animation.h"

#include "../Weapon/Melee.h"
#include "../Weapon/Pistol.h"
#include "../Weapon/Rifle.h"
#include "../Weapon/Shotgun.h"

/*
	NPC jest klas� abstrakcyjn� reprezentuj�c� posta� niezale�n� od sterowania gracza w grze.
	Jest pochodn� klasy Sprite i dziedziczy po niej.
	Posiada pola przechowuj�ce wska�niki na pasek zdrowia, aktualn� animacj�, map� animacji,
	map� efekt�w d�wi�kowych, bro� oraz informacje o zdrowiu, maksymalnym zdrowiu, pr�dko�ci i stanie (czy NPC jest martwy).
	Zawiera r�wnie� wska�nik na obiekt klasy GameManager.

	Konstruktor klasy NPC inicjalizuje pola zwi�zane z zdrowiem, pr�dko�ci� i stanie NPC.

	Metody klasy NPC umo�liwiaj� uzyskiwanie informacji o pr�dko�ci, zdrowiu i maksymalnym zdrowiu NPC,
	ustawianie pr�dko�ci, zdrowia i maksymalnego zdrowia, wyposa�anie NPC w bro�, wczytywanie animacji i efekt�w d�wi�kowych,
	dodawanie animacji i efekt�w d�wi�kowych, odtwarzanie efekt�w d�wi�kowych, kontrolowanie animacji,
	kontrolowanie ruchu, resetowanie stanu NPC oraz renderowanie NPC.

	Klasa NPC reprezentuje posta� niezale�n� od sterowania gracza w grze.
	Posiada zdrowie, pr�dko��, animacje, efekty d�wi�kowe i bro�.
	Zapewnia metody do zarz�dzania tymi aspektami NPC.
	Jest klas� abstrakcyjn�, kt�ra wymaga zaimplementowania niekt�rych metod w klasach pochodnych.
*/

class NPC : public Sprite {
protected:
	HealthBar* m_HealthBar; // Wska�nik na pasek zdrowia NPC.
	Animation* m_CurrentAnimation; // Wska�nik na aktualn� animacj� NPC.
	map<string, Animation*>* m_Animations; // Mapa przechowuj�ca animacje NPC.
	map<string, SFX*>* m_SFXs; // Mapa przechowuj�ca efekty d�wi�kowe NPC.
	Weapon* m_Weapon; // Wska�nik na bro� NPC.

	int m_Health; // Aktualne zdrowie NPC.
	int m_MaxHealth; // Maksymalne zdrowie NPC.
	float m_Velocity; // Pr�dko�� NPC.
	bool m_Dead = false; // Flaga okre�laj�ca, czy NPC jest martwy.

	class GameManager* m_GameManager; // Wska�nik na obiekt klasy GameManager.

public:
	NPC(void); // Konstruktor klasy NPC.

	float getVelocity(void) { return this->m_Velocity; } // Metoda zwracaj�ca pr�dko�� NPC.
	int getHealth(void) { return this->m_Health; } // Metoda zwracaj�ca aktualne zdrowie NPC.
	int getMaxHealth(void) { return this->m_MaxHealth; } // Metoda zwracaj�ca maksymalne zdrowie NPC.

	void setVelocity(float); // Metoda ustawiaj�ca pr�dko�� NPC.
	void setHealth(int); // Metoda ustawiaj�ca aktualne zdrowie NPC.
	void setMaxHealth(int); // Metoda ustawiaj�ca maksymalne zdrowie NPC.

	void equipWeapon(Weapon*); // Metoda wyposa�aj�ca NPC w bro�.

	Animation* getCurrentAnimation(void) { return this->m_CurrentAnimation; } // Metoda zwracaj�ca aktualn� animacj� NPC.
	Weapon* getWeapon(void) { return this->m_Weapon; } // Metoda zwracaj�ca bro� NPC.

	virtual void loadAnimations(void) = 0; // Metoda wczytuj�ca animacje NPC.
	void addAnimation(Animation*); // Metoda dodaj�ca animacj� NPC.
	void setAnimation(string); // Metoda ustawiaj�ca aktualn� animacj� NPC na podstawie nazwy.

	virtual void loadSFXs(void) = 0; // Metoda wczytuj�ca efekty d�wi�kowe NPC.
	void addSFX(SFX*); // Metoda dodaj�ca efekt d�wi�kowy NPC.
	void playSFX(string); // Metoda odtwarzaj�ca efekt d�wi�kowy na podstawie nazwy.

	virtual void animationControl(void) = 0; // Metoda kontroluj�ca animacj� NPC.
	virtual void moveControl(void) = 0; // Metoda kontroluj�ca ruch NPC.
	virtual void reset(void) = 0; // Metoda resetuj�ca stan NPC.

	virtual void render(void) = 0; // Metoda renderuj�ca NPC.

	const int DEFAULT_MAX_HEALTH = 100; // Domy�lne maksymalne zdrowie NPC.
	const float DEFAULT_VELOCITY = 1.f; // Domy�lna pr�dko�� NPC.
};
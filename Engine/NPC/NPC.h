#pragma once
#include "../Core/SFX.h"
#include "HealthBar.h"
#include "Animation.h"

#include "../Weapon/Melee.h"
#include "../Weapon/Pistol.h"
#include "../Weapon/Rifle.h"
#include "../Weapon/Shotgun.h"

/*
	NPC jest klas¹ abstrakcyjn¹ reprezentuj¹c¹ postaæ niezale¿n¹ od sterowania gracza w grze.
	Jest pochodn¹ klasy Sprite i dziedziczy po niej.
	Posiada pola przechowuj¹ce wskaŸniki na pasek zdrowia, aktualn¹ animacjê, mapê animacji,
	mapê efektów dŸwiêkowych, broñ oraz informacje o zdrowiu, maksymalnym zdrowiu, prêdkoœci i stanie (czy NPC jest martwy).
	Zawiera równie¿ wskaŸnik na obiekt klasy GameManager.

	Konstruktor klasy NPC inicjalizuje pola zwi¹zane z zdrowiem, prêdkoœci¹ i stanie NPC.

	Metody klasy NPC umo¿liwiaj¹ uzyskiwanie informacji o prêdkoœci, zdrowiu i maksymalnym zdrowiu NPC,
	ustawianie prêdkoœci, zdrowia i maksymalnego zdrowia, wyposa¿anie NPC w broñ, wczytywanie animacji i efektów dŸwiêkowych,
	dodawanie animacji i efektów dŸwiêkowych, odtwarzanie efektów dŸwiêkowych, kontrolowanie animacji,
	kontrolowanie ruchu, resetowanie stanu NPC oraz renderowanie NPC.

	Klasa NPC reprezentuje postaæ niezale¿n¹ od sterowania gracza w grze.
	Posiada zdrowie, prêdkoœæ, animacje, efekty dŸwiêkowe i broñ.
	Zapewnia metody do zarz¹dzania tymi aspektami NPC.
	Jest klas¹ abstrakcyjn¹, która wymaga zaimplementowania niektórych metod w klasach pochodnych.
*/

class NPC : public Sprite {
protected:
	HealthBar* m_HealthBar; // WskaŸnik na pasek zdrowia NPC.
	Animation* m_CurrentAnimation; // WskaŸnik na aktualn¹ animacjê NPC.
	map<string, Animation*>* m_Animations; // Mapa przechowuj¹ca animacje NPC.
	map<string, SFX*>* m_SFXs; // Mapa przechowuj¹ca efekty dŸwiêkowe NPC.
	Weapon* m_Weapon; // WskaŸnik na broñ NPC.

	int m_Health; // Aktualne zdrowie NPC.
	int m_MaxHealth; // Maksymalne zdrowie NPC.
	float m_Velocity; // Prêdkoœæ NPC.
	bool m_Dead = false; // Flaga okreœlaj¹ca, czy NPC jest martwy.

	class GameManager* m_GameManager; // WskaŸnik na obiekt klasy GameManager.

public:
	NPC(void); // Konstruktor klasy NPC.

	float getVelocity(void) { return this->m_Velocity; } // Metoda zwracaj¹ca prêdkoœæ NPC.
	int getHealth(void) { return this->m_Health; } // Metoda zwracaj¹ca aktualne zdrowie NPC.
	int getMaxHealth(void) { return this->m_MaxHealth; } // Metoda zwracaj¹ca maksymalne zdrowie NPC.

	void setVelocity(float); // Metoda ustawiaj¹ca prêdkoœæ NPC.
	void setHealth(int); // Metoda ustawiaj¹ca aktualne zdrowie NPC.
	void setMaxHealth(int); // Metoda ustawiaj¹ca maksymalne zdrowie NPC.

	void equipWeapon(Weapon*); // Metoda wyposa¿aj¹ca NPC w broñ.

	Animation* getCurrentAnimation(void) { return this->m_CurrentAnimation; } // Metoda zwracaj¹ca aktualn¹ animacjê NPC.
	Weapon* getWeapon(void) { return this->m_Weapon; } // Metoda zwracaj¹ca broñ NPC.

	virtual void loadAnimations(void) = 0; // Metoda wczytuj¹ca animacje NPC.
	void addAnimation(Animation*); // Metoda dodaj¹ca animacjê NPC.
	void setAnimation(string); // Metoda ustawiaj¹ca aktualn¹ animacjê NPC na podstawie nazwy.

	virtual void loadSFXs(void) = 0; // Metoda wczytuj¹ca efekty dŸwiêkowe NPC.
	void addSFX(SFX*); // Metoda dodaj¹ca efekt dŸwiêkowy NPC.
	void playSFX(string); // Metoda odtwarzaj¹ca efekt dŸwiêkowy na podstawie nazwy.

	virtual void animationControl(void) = 0; // Metoda kontroluj¹ca animacjê NPC.
	virtual void moveControl(void) = 0; // Metoda kontroluj¹ca ruch NPC.
	virtual void reset(void) = 0; // Metoda resetuj¹ca stan NPC.

	virtual void render(void) = 0; // Metoda renderuj¹ca NPC.

	const int DEFAULT_MAX_HEALTH = 100; // Domyœlne maksymalne zdrowie NPC.
	const float DEFAULT_VELOCITY = 1.f; // Domyœlna prêdkoœæ NPC.
};
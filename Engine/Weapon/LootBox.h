#pragma once
#include "../include.h"

/*
	Klasa LootBox reprezentuje skrzynk� z nagrod� w grze.
	Posiada pole m_BonusDesc, kt�re przechowuje opisy bonus�w dost�pnych w skrzynce.

	Klasa LootBox dziedziczy po klasie Sprite i posiada pola zwi�zane z tekstur�, czcionk� oraz tekstem bonusu.
	Przechowuje r�wnie� informacje o czasie od�wie�ania skrzynki, czasie trwania powiadomienia o zdobytym bonusie,
	aktualnym wylosowanym bonusie oraz flag� m_IsPlaced, kt�ra okre�la, czy skrzynka zosta�a umieszczona na planszy.

	Konstruktor klasy LootBox przyjmuje wska�nik na obiekt klasy GameManager i inicjalizuje pola zwi�zane z graczem i mened�erem gry.

	Metody klasy LootBox umo�liwiaj� sprawdzenie kolizji skrzynki z graczem, losowanie bonusu, przypisanie bonusu do gracza,
	umieszczenie skrzynki na planszy, resetowanie skrzynki oraz renderowanie skrzynki.

	Klasa LootBox zawiera r�wnie� enum BONUSTYPE, kt�ry definiuje dost�pne typy bonus�w w skrzynce.
*/

struct LootBox_Bonus {
	LootBox_Bonus(string, Color); // Konstruktor struktury LootBox_Bonus.

	string m_Text; // Tekstowy opis bonusu.
	Color m_Color; // Kolor bonusu.
};

class LootBox : public Sprite {
private:
	enum BONUSTYPE { DAMAGE, AMMUNITION, BULLET_VELOCITY, RELOAD_TIME, HEALTH, MOVEMENT_VELOCITY, ENUMRANGE }; // Typy bonus�w dost�pne w skrzynce.
	vector<LootBox_Bonus> m_BonusDesc; // Wektor przechowuj�cy opisy bonus�w.

	Texture* m_Texture; // Tekstura skrzynki.
	Font* m_Font; // Czcionka tekstu bonusu.
	Text* m_Text; // Tekst bonusu.
	float m_RefreshTime; // Czas od�wie�ania skrzynki.
	float m_NotificationTime; // Czas trwania powiadomienia o zdobytym bonusie.
	bool m_IsPlaced; // Flaga okre�laj�ca, czy skrzynka zosta�a umieszczona na planszy.
	int m_CurrentBonus; // Aktualny wylosowany bonus.

	const float REFRESH_TIME = 10.f; // Czas od�wie�ania skrzynki.

	class Player* m_Player; // Wska�nik na gracza.
	class GameManager* m_GameManager; // Wska�nik na obiekt GameManager.
public:
	LootBox(class GameManager*); // Konstruktor klasy LootBox.

	void checkCollision(void); // Metoda sprawdzaj�ca kolizj� skrzynki z graczem.
	void rollBonus(void); // Metoda losuj�ca bonus z dost�pnych typ�w.
	void assignBonus(void); // Metoda przypisuj�ca wylosowany bonus do gracza.

	void spawn(void); // Metoda umieszczaj�ca skrzynk� na planszy.
	void reset(void); // Metoda resetuj�ca skrzynk�.

	void render(void); // Metoda renderuj�ca skrzynk�.
};
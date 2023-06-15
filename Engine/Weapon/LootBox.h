#pragma once
#include "../include.h"

/*
	Klasa LootBox reprezentuje skrzynkê z nagrod¹ w grze.
	Posiada pole m_BonusDesc, które przechowuje opisy bonusów dostêpnych w skrzynce.

	Klasa LootBox dziedziczy po klasie Sprite i posiada pola zwi¹zane z tekstur¹, czcionk¹ oraz tekstem bonusu.
	Przechowuje równie¿ informacje o czasie odœwie¿ania skrzynki, czasie trwania powiadomienia o zdobytym bonusie,
	aktualnym wylosowanym bonusie oraz flagê m_IsPlaced, która okreœla, czy skrzynka zosta³a umieszczona na planszy.

	Konstruktor klasy LootBox przyjmuje wskaŸnik na obiekt klasy GameManager i inicjalizuje pola zwi¹zane z graczem i mened¿erem gry.

	Metody klasy LootBox umo¿liwiaj¹ sprawdzenie kolizji skrzynki z graczem, losowanie bonusu, przypisanie bonusu do gracza,
	umieszczenie skrzynki na planszy, resetowanie skrzynki oraz renderowanie skrzynki.

	Klasa LootBox zawiera równie¿ enum BONUSTYPE, który definiuje dostêpne typy bonusów w skrzynce.
*/

struct LootBox_Bonus {
	LootBox_Bonus(string, Color); // Konstruktor struktury LootBox_Bonus.

	string m_Text; // Tekstowy opis bonusu.
	Color m_Color; // Kolor bonusu.
};

class LootBox : public Sprite {
private:
	enum BONUSTYPE { DAMAGE, AMMUNITION, BULLET_VELOCITY, RELOAD_TIME, HEALTH, MOVEMENT_VELOCITY, ENUMRANGE }; // Typy bonusów dostêpne w skrzynce.
	vector<LootBox_Bonus> m_BonusDesc; // Wektor przechowuj¹cy opisy bonusów.

	Texture* m_Texture; // Tekstura skrzynki.
	Font* m_Font; // Czcionka tekstu bonusu.
	Text* m_Text; // Tekst bonusu.
	float m_RefreshTime; // Czas odœwie¿ania skrzynki.
	float m_NotificationTime; // Czas trwania powiadomienia o zdobytym bonusie.
	bool m_IsPlaced; // Flaga okreœlaj¹ca, czy skrzynka zosta³a umieszczona na planszy.
	int m_CurrentBonus; // Aktualny wylosowany bonus.

	const float REFRESH_TIME = 10.f; // Czas odœwie¿ania skrzynki.

	class Player* m_Player; // WskaŸnik na gracza.
	class GameManager* m_GameManager; // WskaŸnik na obiekt GameManager.
public:
	LootBox(class GameManager*); // Konstruktor klasy LootBox.

	void checkCollision(void); // Metoda sprawdzaj¹ca kolizjê skrzynki z graczem.
	void rollBonus(void); // Metoda losuj¹ca bonus z dostêpnych typów.
	void assignBonus(void); // Metoda przypisuj¹ca wylosowany bonus do gracza.

	void spawn(void); // Metoda umieszczaj¹ca skrzynkê na planszy.
	void reset(void); // Metoda resetuj¹ca skrzynkê.

	void render(void); // Metoda renderuj¹ca skrzynkê.
};
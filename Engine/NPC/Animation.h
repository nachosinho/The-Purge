#pragma once
#include "../include.h"

/*
	Animation jest klas¹ reprezentuj¹c¹ animacjê w grze.
	Posiada pole przechowuj¹ce wskaŸnik na teksturê animacji, liczbê klatek animacji, aktualn¹ klatkê animacji,
	rozmiar pojedynczej klatki, czas trwania jednej klatki, ca³kowity czas trwania animacji, nazwê animacji
	oraz wskaŸnik na obiekt klasy NPC,z którym animacja jest powi¹zana.

	Konstruktor klasy Animation przyjmuje parametry, które inicjalizuj¹ obiekt animacji.
	Obejmuj¹ one wskaŸnik na obiekt NPC, nazwê animacji, œcie¿kê do tekstury animacji, rozmiar pojedynczej klatki oraz liczbê klatek animacji.

	Metody klasy Animation umo¿liwiaj¹ uzyskiwanie informacji o animacji, takich jak nazwa, aktualna klatka,
	liczba klatek, tekstura animacji oraz prostok¹t reprezentuj¹cy aktualn¹ klatkê.
	Metoda resetFrame resetuje klatkê animacji, a metoda render renderuje animacjê.

	Klasa Animation jest odpowiedzialna za obs³ugê animacji w grze.
	Jest powi¹zana z obiektem klasy NPC, z którym animacja jest zwi¹zana.
*/

class Animation {
private:
	Texture* m_Texture; // WskaŸnik na teksturê animacji.
	int m_FramesCount; // Liczba klatek animacji.
	int m_CurrentFrame; // Aktualna klatka animacji.
	Vector2i m_FrameSize; // Rozmiar pojedynczej klatki animacji.
	const float m_SwitchTime = 0.3f; // Czas trwania jednej klatki animacji.
	float m_TotalTime; // Ca³kowity czas trwania animacji.
	string m_Name; // Nazwa animacji.
	class NPC* m_NPC; // WskaŸnik na obiekt klasy NPC.

public:
	Animation(class NPC*, string, string, Vector2i, int); // Konstruktor klasy Animation.

	string getName(void) { return this->m_Name; } // Metoda zwracaj¹ca nazwê animacji.
	int getCurrentFrame(void) { return this->m_CurrentFrame; } // Metoda zwracaj¹ca aktualn¹ klatkê animacji.
	int getFramesCount(void) { return this->m_FramesCount; } // Metoda zwracaj¹ca liczbê klatek animacji.
	Texture* getTexture(void) { return this->m_Texture; } // Metoda zwracaj¹ca wskaŸnik na teksturê animacji.
	IntRect getFrameRect(void) {
		return { m_CurrentFrame % 8 * m_FrameSize.x, m_CurrentFrame / 8 * m_FrameSize.y,
								m_FrameSize.x, m_FrameSize.y };
	} // Metoda zwracaj¹ca prostok¹t reprezentuj¹cy aktualn¹ klatkê animacji.

	void resetFrame(void); // Metoda resetuj¹ca klatkê animacji.
	void render(float); // Metoda renderuj¹ca animacjê.
};
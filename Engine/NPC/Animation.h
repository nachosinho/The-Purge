#pragma once
#include "../include.h"

/*
	Animation jest klas� reprezentuj�c� animacj� w grze.
	Posiada pole przechowuj�ce wska�nik na tekstur� animacji, liczb� klatek animacji, aktualn� klatk� animacji,
	rozmiar pojedynczej klatki, czas trwania jednej klatki, ca�kowity czas trwania animacji, nazw� animacji
	oraz wska�nik na obiekt klasy NPC,z kt�rym animacja jest powi�zana.

	Konstruktor klasy Animation przyjmuje parametry, kt�re inicjalizuj� obiekt animacji.
	Obejmuj� one wska�nik na obiekt NPC, nazw� animacji, �cie�k� do tekstury animacji, rozmiar pojedynczej klatki oraz liczb� klatek animacji.

	Metody klasy Animation umo�liwiaj� uzyskiwanie informacji o animacji, takich jak nazwa, aktualna klatka,
	liczba klatek, tekstura animacji oraz prostok�t reprezentuj�cy aktualn� klatk�.
	Metoda resetFrame resetuje klatk� animacji, a metoda render renderuje animacj�.

	Klasa Animation jest odpowiedzialna za obs�ug� animacji w grze.
	Jest powi�zana z obiektem klasy NPC, z kt�rym animacja jest zwi�zana.
*/

class Animation {
private:
	Texture* m_Texture; // Wska�nik na tekstur� animacji.
	int m_FramesCount; // Liczba klatek animacji.
	int m_CurrentFrame; // Aktualna klatka animacji.
	Vector2i m_FrameSize; // Rozmiar pojedynczej klatki animacji.
	const float m_SwitchTime = 0.3f; // Czas trwania jednej klatki animacji.
	float m_TotalTime; // Ca�kowity czas trwania animacji.
	string m_Name; // Nazwa animacji.
	class NPC* m_NPC; // Wska�nik na obiekt klasy NPC.

public:
	Animation(class NPC*, string, string, Vector2i, int); // Konstruktor klasy Animation.

	string getName(void) { return this->m_Name; } // Metoda zwracaj�ca nazw� animacji.
	int getCurrentFrame(void) { return this->m_CurrentFrame; } // Metoda zwracaj�ca aktualn� klatk� animacji.
	int getFramesCount(void) { return this->m_FramesCount; } // Metoda zwracaj�ca liczb� klatek animacji.
	Texture* getTexture(void) { return this->m_Texture; } // Metoda zwracaj�ca wska�nik na tekstur� animacji.
	IntRect getFrameRect(void) {
		return { m_CurrentFrame % 8 * m_FrameSize.x, m_CurrentFrame / 8 * m_FrameSize.y,
								m_FrameSize.x, m_FrameSize.y };
	} // Metoda zwracaj�ca prostok�t reprezentuj�cy aktualn� klatk� animacji.

	void resetFrame(void); // Metoda resetuj�ca klatk� animacji.
	void render(float); // Metoda renderuj�ca animacj�.
};
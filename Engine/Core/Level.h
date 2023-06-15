#pragma once
#include "SFX.h"

/*
	Level jest klas¹ reprezentuj¹c¹ poziom gry.
	Jest pochodn¹ klasy Sprite i dziedziczy po niej. Klasa przechowuje wskaŸniki na teksturê obiektu Level oraz obiekt efektów dŸwiêkowych (SFX).
	Posiada tak¿e wskaŸnik na obiekt klasy GameManager, umo¿liwiaj¹cy dostêp do zarz¹dcy gry.

	Metody klasy Level umo¿liwiaj¹ uzyskiwanie i ustawianie obiektu efektów dŸwiêkowych, dodawanie tekstury, zarz¹dzanie muzyk¹ oraz renderowanie obrazu.

	Klasa Level jest istotnym elementem gry, reprezentuj¹cym konkretny poziom, jego wygl¹d, efekty dŸwiêkowe i renderowanie.
	Jest powi¹zana z klas¹ GameManager, która zarz¹dza ca³¹ gr¹.
*/

class Level : public Sprite {
private:
	Texture* m_Texture; // WskaŸnik na teksturê obiektu Level.
	SFX* m_SFX; // WskaŸnik na obiekt efektów dŸwiêkowych.

	class GameManager* m_GameManager; // WskaŸnik na obiekt klasy GameManager.
public:
	Level(class GameManager*); // Konstruktor klasy Level.

	SFX* getSFX(void) { return this->m_SFX; } // Metoda zwracaj¹ca wskaŸnik na obiekt efektów dŸwiêkowych.

	void setSFX(SFX*); // Metoda ustawiaj¹ca obiekt efektów dŸwiêkowych.

	void addTexture(string); // Metoda dodaj¹ca teksturê.
	void manageMusic(void); // Metoda zarz¹dzaj¹ca muzyk¹.

	void render(void); // Metoda renderuj¹ca obraz.
};
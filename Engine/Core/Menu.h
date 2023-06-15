#pragma once
#include "../include.h"
#include "SFX.h"

/*
	Menu jest klas¹ abstrakcyjn¹ reprezentuj¹c¹ menu w grze.
	Posiada chronione (protected) pola przechowuj¹ce nazwê menu, stan gry zwi¹zany z menu oraz wskaŸnik na obiekt efektów dŸwiêkowych (SFX).
	Klasa posiada tak¿e wskaŸnik na obiekt klasy GameManager, umo¿liwiaj¹cy dostêp do zarz¹dcy gry.

	Metody klasy Menu umo¿liwiaj¹ uzyskiwanie informacji o obiekcie efektów dŸwiêkowych, nazwie menu i stanie gry zwi¹zanych z menu.
	Ponadto, klasa zawiera cztery czysto wirtualne (pure virtual) metody, które musz¹ zostaæ zaimplementowane w klasach pochodnych:
		handleInput: Obs³uguje dane wejœciowe dla menu.
		update: Aktualizuje menu.
		reload: Ponownie ³adowuje menu.
		render: Renderuje obraz menu.

	Klasa Menu jest podstawowym sk³adnikiem systemu menu w grze.
	Jest klas¹ abstrakcyjn¹, która definiuje interfejs dla ró¿nych typów menu.
	Jest powi¹zana z klas¹ GameManager, która zarz¹dza ca³¹ gr¹.
*/

class Menu {
protected:
	string m_Name; // Nazwa menu.
	int m_GameState; // Stan gry zwi¹zany z menu.
	SFX* m_SFX; // WskaŸnik na obiekt efektów dŸwiêkowych.

	class GameManager* m_GameManager; // WskaŸnik na obiekt klasy GameManager.
public:
	Menu(string, class GameManager*); // Konstruktor klasy Menu.

	SFX* getSFX(void) { return this->m_SFX; } // Metoda zwracaj¹ca wskaŸnik na obiekt efektów dŸwiêkowych.
	string getName(void) { return this->m_Name; } // Metoda zwracaj¹ca nazwê menu.
	int getGameState(void) { return this->m_GameState; } // Metoda zwracaj¹ca stan gry zwi¹zany z menu.

	virtual void handleInput(void) = 0; // Metoda obs³uguj¹ca dane wejœciowe dla menu.
	virtual void update(void) = 0; // Metoda aktualizuj¹ca menu.
	virtual void reload(void) = 0; // Metoda ponownie ³adowuj¹ca menu.
	virtual void render(void) = 0; // Metoda renderuj¹ca obraz menu.
};
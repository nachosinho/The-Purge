#pragma once
#include "../include.h"
#include "SFX.h"

/*
	Menu jest klas� abstrakcyjn� reprezentuj�c� menu w grze.
	Posiada chronione (protected) pola przechowuj�ce nazw� menu, stan gry zwi�zany z menu oraz wska�nik na obiekt efekt�w d�wi�kowych (SFX).
	Klasa posiada tak�e wska�nik na obiekt klasy GameManager, umo�liwiaj�cy dost�p do zarz�dcy gry.

	Metody klasy Menu umo�liwiaj� uzyskiwanie informacji o obiekcie efekt�w d�wi�kowych, nazwie menu i stanie gry zwi�zanych z menu.
	Ponadto, klasa zawiera cztery czysto wirtualne (pure virtual) metody, kt�re musz� zosta� zaimplementowane w klasach pochodnych:
		handleInput: Obs�uguje dane wej�ciowe dla menu.
		update: Aktualizuje menu.
		reload: Ponownie �adowuje menu.
		render: Renderuje obraz menu.

	Klasa Menu jest podstawowym sk�adnikiem systemu menu w grze.
	Jest klas� abstrakcyjn�, kt�ra definiuje interfejs dla r�nych typ�w menu.
	Jest powi�zana z klas� GameManager, kt�ra zarz�dza ca�� gr�.
*/

class Menu {
protected:
	string m_Name; // Nazwa menu.
	int m_GameState; // Stan gry zwi�zany z menu.
	SFX* m_SFX; // Wska�nik na obiekt efekt�w d�wi�kowych.

	class GameManager* m_GameManager; // Wska�nik na obiekt klasy GameManager.
public:
	Menu(string, class GameManager*); // Konstruktor klasy Menu.

	SFX* getSFX(void) { return this->m_SFX; } // Metoda zwracaj�ca wska�nik na obiekt efekt�w d�wi�kowych.
	string getName(void) { return this->m_Name; } // Metoda zwracaj�ca nazw� menu.
	int getGameState(void) { return this->m_GameState; } // Metoda zwracaj�ca stan gry zwi�zany z menu.

	virtual void handleInput(void) = 0; // Metoda obs�uguj�ca dane wej�ciowe dla menu.
	virtual void update(void) = 0; // Metoda aktualizuj�ca menu.
	virtual void reload(void) = 0; // Metoda ponownie �adowuj�ca menu.
	virtual void render(void) = 0; // Metoda renderuj�ca obraz menu.
};
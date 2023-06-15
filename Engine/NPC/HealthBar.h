#pragma once
#include "../include.h"

/*
	HealthBar jest klas¹ reprezentuj¹c¹ pasek zdrowia w grze.
	Posiada pola przechowuj¹ce wskaŸniki na prostok¹ty reprezentuj¹ce t³o i przedni¹ czêœæ paska zdrowia,
	wskaŸnik na obiekt RenderWindow oraz wskaŸnik na obiekt klasy NPC, z którym pasek zdrowia jest powi¹zany.

	Konstruktor klasy HealthBar przyjmuje wskaŸnik na obiekt klasy NPC oraz wskaŸnik na obiekt RenderWindow i inicjalizuje pasek zdrowia.

	Metody klasy HealthBar umo¿liwiaj¹ ustawianie koloru, procentowego wype³nienia oraz pozycji paska zdrowia. Metoda render renderuje pasek zdrowia.

	Klasa HealthBar jest odpowiedzialna za wyœwietlanie paska zdrowia dla obiektu klasy NPC w grze.
	Przechowuje informacje o wygl¹dzie i po³o¿eniu paska zdrowia oraz umo¿liwia aktualizowanie tych informacji w zale¿noœci od stanu zdrowia obiektu NPC.
*/

class HealthBar {
private:
	RectangleShape* m_HealthBarBack; // WskaŸnik na prostok¹t reprezentuj¹cy t³o paska zdrowia.
	RectangleShape* m_HealthBarFront; // WskaŸnik na prostok¹t reprezentuj¹cy przedni¹ czêœæ paska zdrowia.
	RenderWindow* m_RenderWindow; // WskaŸnik na obiekt RenderWindow.
	class NPC* m_NPC; // WskaŸnik na obiekt klasy NPC.
public:
	HealthBar(class NPC*, RenderWindow*); // Konstruktor klasy HealthBar.

	Vector2f getPosition(void) { return this->m_HealthBarBack->getPosition(); } // Metoda zwracaj¹ca pozycjê t³a paska zdrowia.
	Vector2f getSize(void) { return this->m_HealthBarBack->getSize(); } // Metoda zwracaj¹ca rozmiar t³a paska zdrowia.

	void setColor(Color); // Metoda ustawiaj¹ca kolor paska zdrowia.
	void setPercentage(float); // Metoda ustawiaj¹ca procentowe wype³nienie paska zdrowia.
	void setPosition(float, float); // Metoda ustawiaj¹ca pozycjê paska zdrowia na podstawie wspó³rzêdnych x i y.
	void setPosition(Vector2f); // Metoda ustawiaj¹ca pozycjê paska zdrowia na podstawie wektora pozycji.

	void render(void); // Metoda renderuj¹ca pasek zdrowia.
};
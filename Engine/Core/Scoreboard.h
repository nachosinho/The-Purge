#pragma once
#include "../include.h"

/*
	Score jest struktur¹ reprezentuj¹c¹ wynik w tablicy wyników.
	Posiada konstruktor domyœlny oraz konstruktor z parametrami, które inicjalizuj¹ nazwê i wartoœæ wyniku.

	ScoreBoard jest klas¹ odpowiedzialn¹ za zarz¹dzanie tablic¹ wyników.
	Posiada wektor wskaŸników na struktury Score, które reprezentuj¹ poszczególne wyniki.
	Klasa zawiera metody umo¿liwiaj¹ce wczytywanie, zapisywanie i dodawanie wyników do tablicy.

	Metoda loadScoreBoard wczytuje tablicê wyników z odpowiedniego Ÿród³a, saveScoreBoard zapisuje tablicê wyników, a addScore dodaje nowy wynik do tablicy.

	Klasa ScoreBoard pe³ni rolê zarz¹dcy tablicy wyników w grze.
	Jest odpowiedzialna za operacje na wynikach, takich jak ich wczytywanie, zapisywanie i dodawanie.
*/

struct Score {
	Score(void) {}; // Konstruktor domyœlny struktury Score.
	Score(string, int); // Konstruktor struktury Score z parametrami.

	string m_Name = "UNNAMED"; // Nazwa gracza.
	int m_Score = -1; // Wartoœæ wyniku.
};

class ScoreBoard {
private:
	vector<Score>* m_ScoreVec; // Wektor wyników.

public:
	ScoreBoard(); // Konstruktor klasy ScoreBoard.

	vector<Score>* getScore(void) { return this->m_ScoreVec; } // Metoda zwracaj¹ca wskaŸnik na wektor wyników.

	void loadScoreBoard(void); // Metoda wczytuj¹ca tablicê wyników z pliku.
	void saveScoreBoard(void); // Metoda zapisuj¹ca tablicê wyników do pliku.
	void addScore(int); // Metoda dodaj¹ca nowy wynik do tablicy.

};
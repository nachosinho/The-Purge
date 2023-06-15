#pragma once
#include "../include.h"

/*
	Score jest struktur� reprezentuj�c� wynik w tablicy wynik�w.
	Posiada konstruktor domy�lny oraz konstruktor z parametrami, kt�re inicjalizuj� nazw� i warto�� wyniku.

	ScoreBoard jest klas� odpowiedzialn� za zarz�dzanie tablic� wynik�w.
	Posiada wektor wska�nik�w na struktury Score, kt�re reprezentuj� poszczeg�lne wyniki.
	Klasa zawiera metody umo�liwiaj�ce wczytywanie, zapisywanie i dodawanie wynik�w do tablicy.

	Metoda loadScoreBoard wczytuje tablic� wynik�w z odpowiedniego �r�d�a, saveScoreBoard zapisuje tablic� wynik�w, a addScore dodaje nowy wynik do tablicy.

	Klasa ScoreBoard pe�ni rol� zarz�dcy tablicy wynik�w w grze.
	Jest odpowiedzialna za operacje na wynikach, takich jak ich wczytywanie, zapisywanie i dodawanie.
*/

struct Score {
	Score(void) {}; // Konstruktor domy�lny struktury Score.
	Score(string, int); // Konstruktor struktury Score z parametrami.

	string m_Name = "UNNAMED"; // Nazwa gracza.
	int m_Score = -1; // Warto�� wyniku.
};

class ScoreBoard {
private:
	vector<Score>* m_ScoreVec; // Wektor wynik�w.

public:
	ScoreBoard(); // Konstruktor klasy ScoreBoard.

	vector<Score>* getScore(void) { return this->m_ScoreVec; } // Metoda zwracaj�ca wska�nik na wektor wynik�w.

	void loadScoreBoard(void); // Metoda wczytuj�ca tablic� wynik�w z pliku.
	void saveScoreBoard(void); // Metoda zapisuj�ca tablic� wynik�w do pliku.
	void addScore(int); // Metoda dodaj�ca nowy wynik do tablicy.

};
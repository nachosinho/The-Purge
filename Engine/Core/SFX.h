#pragma once
#include "../include.h"

/*
	SFX jest klas� reprezentuj�c� efekt d�wi�kowy w grze.
	Jest pochodn� klasy Sound i dziedziczy po niej.
	Posiada pole przechowuj�ce nazw� efektu d�wi�kowego oraz wska�nik na obiekt SoundBuffer, kt�ry reprezentuje bufor d�wi�ku.

	Konstruktor klasy SFX przyjmuje parametry, kt�re inicjalizuj� nazw� efektu d�wi�kowego oraz �cie�k� do pliku d�wi�kowego.

	Metoda getName zwraca nazw� efektu d�wi�kowego.

	Klasa SFX jest odpowiedzialna za obs�ug� efekt�w d�wi�kowych w grze.
	Jest pochodn� klasy Sound, co umo�liwia odtwarzanie d�wi�k�w.
*/

class SFX : public Sound {
private:
	string m_Name; // Nazwa efektu d�wi�kowego.
	SoundBuffer* m_Buffer; // Bufor d�wi�ku.
public:
	SFX(string, string); // Konstruktor klasy SFX z parametrami.

	string getName(void) { return this->m_Name; } // Metoda zwracaj�ca nazw� efektu d�wi�kowego.
};
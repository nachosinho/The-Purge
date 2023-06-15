#pragma once
#include "../include.h"

/*
	SFX jest klas¹ reprezentuj¹c¹ efekt dŸwiêkowy w grze.
	Jest pochodn¹ klasy Sound i dziedziczy po niej.
	Posiada pole przechowuj¹ce nazwê efektu dŸwiêkowego oraz wskaŸnik na obiekt SoundBuffer, który reprezentuje bufor dŸwiêku.

	Konstruktor klasy SFX przyjmuje parametry, które inicjalizuj¹ nazwê efektu dŸwiêkowego oraz œcie¿kê do pliku dŸwiêkowego.

	Metoda getName zwraca nazwê efektu dŸwiêkowego.

	Klasa SFX jest odpowiedzialna za obs³ugê efektów dŸwiêkowych w grze.
	Jest pochodn¹ klasy Sound, co umo¿liwia odtwarzanie dŸwiêków.
*/

class SFX : public Sound {
private:
	string m_Name; // Nazwa efektu dŸwiêkowego.
	SoundBuffer* m_Buffer; // Bufor dŸwiêku.
public:
	SFX(string, string); // Konstruktor klasy SFX z parametrami.

	string getName(void) { return this->m_Name; } // Metoda zwracaj¹ca nazwê efektu dŸwiêkowego.
};
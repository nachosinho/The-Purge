#pragma once
#include "include.h"

class SFX : public Sound {
private:
	string m_Name;
	SoundBuffer* m_Buffer;
public:
	SFX(string, string);

	string getName(void) { return this->m_Name; }
};
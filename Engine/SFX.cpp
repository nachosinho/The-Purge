#include "SFX.h"

SFX::SFX(string _name, string _path) {
	this->m_Buffer = new SoundBuffer;

	if (!this->m_Buffer->loadFromFile(_path))
		return;

	this->setBuffer(*this->m_Buffer);
	this->m_Name = _name;
}
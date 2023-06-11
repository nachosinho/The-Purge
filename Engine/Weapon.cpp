#include "GameManager.h"
#include "Weapon.h"

Weapon::Weapon(GameManager* _gameManager, NPC* _player)
	: m_Damage(1), m_Delay(0.00005f), m_Cooldown(0.00005f)
{
	this->m_GameManager = _gameManager;
	this->m_Owner = _player;

	if (m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;
}

void Weapon::setDamage(int _value) {
	if (_value < 0) _value = 0;
	this->m_Damage = _value;
}

void Weapon::setCooldown(float _value) {
	if (_value < 0.f) _value = 0.f;
	this->m_Cooldown = _value;
}

void Weapon::setDelay(float _value) {
	if (_value < 0.f) _value = 0.f;
	this->m_Delay = _value;
}
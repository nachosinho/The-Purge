#include "NPC.h"
#include "GameManager.h"

NPC::NPC(void) {
	this->m_CurrentAnimation = nullptr;
	this->m_GameManager = nullptr;
	this->m_HealthBar = nullptr;
	this->m_Animations = new map<string, Animation*>;
}

void NPC::setHealth(int _value) {
	if (_value > 100) _value = 100;
	if (_value < 0) _value = 0;

	this->m_Health = _value;
	this->m_HealthBar->setPercentage(this->getHealth());
}

void NPC::addAnimation(string _animName, Animation* _animation) {
	if (m_Animations->find(_animName) != m_Animations->end()) return;
	m_Animations->insert(pair<string, Animation*>(_animName, _animation));
}

void NPC::setAnimation(string _mapKey) {
	if (m_Animations->find(_mapKey) == m_Animations->end()) return;

	this->m_CurrentAnimation = (*m_Animations)[_mapKey];
	this->setTexture(*this->m_CurrentAnimation->getTexture());
	this->setTextureRect(this->m_CurrentAnimation->getFrame());
}
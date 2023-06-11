#include "NPC.h"
#include "GameManager.h"

NPC::NPC(void)
	: m_MaxHealth(100), m_Health(100)
{
	this->m_CurrentAnimation = nullptr;
	this->m_GameManager = nullptr;
	this->m_HealthBar = nullptr;
	this->m_Weapon = nullptr;
	this->m_Animations = new map<string, Animation*>;
	this->m_SFXs = new map<string, SFX*>;
}

void NPC::setHealth(int _value) {
	if (_value < 0) _value = 0;

	this->m_Health = _value;
	this->m_HealthBar->setPercentage(1.f * this->getHealth() / this->m_MaxHealth);
}

void NPC::setMaxHealth(int _value) {
	if (_value < 0) _value = 0;

	this->m_MaxHealth = _value;
	this->m_Health = this->m_MaxHealth;
	this->m_HealthBar->setPercentage(1.f * this->getHealth() / this->m_MaxHealth);
}

void NPC::addAnimation(Animation* _animation) {
	if (m_Animations->find(_animation->getName()) != m_Animations->end()) return;
	m_Animations->insert(pair<string, Animation*>(_animation->getName(), _animation));
}

void NPC::setAnimation(string _mapKey) {
	if (m_Animations->find(_mapKey) == m_Animations->end()) return;
	if (this->m_CurrentAnimation == nullptr) {
		this->m_CurrentAnimation = (*m_Animations)[_mapKey];
		this->setTexture(*this->m_CurrentAnimation->getTexture());
		this->setTextureRect(this->m_CurrentAnimation->getFrameRect());
	}

	else if (this->m_CurrentAnimation->getName() != _mapKey) {
		this->m_CurrentAnimation->resetFrame();
		this->m_CurrentAnimation = (*m_Animations)[_mapKey];
		this->setTexture(*this->m_CurrentAnimation->getTexture());
		this->setTextureRect(this->m_CurrentAnimation->getFrameRect());
	}
}

void NPC::addSFX(SFX* _sfx) {
	if (m_SFXs->find(_sfx->getName()) != m_SFXs->end()) return;
	m_SFXs->insert(pair<string, SFX*>(_sfx->getName(), _sfx));
}

void NPC::playSFX(string _mapKey) {
	if (m_SFXs->find(_mapKey) == m_SFXs->end()) return;
	(*m_SFXs)[_mapKey]->play();
}
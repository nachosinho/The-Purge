#include "HealthBar.h"
#include "NPC.h"

HealthBar::HealthBar(NPC* _npc, RenderWindow* _renderWindow) {
	this->m_RenderWindow = _renderWindow;
	this->m_NPC = _npc;

	this->m_HealthBarBack->setFillColor(Color(153, 153, 153, 153));
	this->m_HealthBarBack->setSize(Vector2f(162, 12));

	this->m_HealthBarFront->setFillColor(Color(201, 0, 0));
	this->m_HealthBarFront->setSize(Vector2f(162, 12));
}

void HealthBar::setColor(Color _color) {
	this->m_HealthBarFront->setFillColor(_color);
}

void HealthBar::setPercentage(float _perc) {
	if (_perc > 1.f) _perc = 1.f;
	if (_perc < 0.f) _perc = 0.f;

	this->m_HealthBarFront->setScale(_perc, 1.f);
}

void HealthBar::setPosition(float _x, float _y) {
	this->m_HealthBarBack->setPosition(_x, _y);
	this->m_HealthBarFront->setPosition(_x, _y);
}

void HealthBar::setPosition(Vector2f _position) {
	this->m_HealthBarBack->setPosition(_position);
	this->m_HealthBarFront->setPosition(_position);
}

void HealthBar::render(void) {
	if (this->m_RenderWindow == nullptr)
		return;

	if (this->m_NPC == nullptr)
		return;

	//this->m_HealthBarBack->setPosition(this->m_NPC->); // getposition
	this->m_HealthBarFront->setPosition(m_HealthBarBack->getPosition());

	this->m_RenderWindow->draw(*this->m_HealthBarBack);
	this->m_RenderWindow->draw(*this->m_HealthBarFront);
}
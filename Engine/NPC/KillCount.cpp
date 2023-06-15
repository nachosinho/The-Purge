#include "KillCount.h"
#include "../Core/GameManager.h"

KillCount::KillCount(GameManager* _gameManager)
	: m_Score(0)
{
	this->m_GameManager = _gameManager;

	this->m_Texture = new Texture;
	if (!this->m_Texture->loadFromFile("Assets/Textures/Interface/Skull.png"))
		return;

	this->setTexture(*this->m_Texture);
	this->setPosition(WINDOW_X - this->getGlobalBounds().width,
		WINDOW_Y - this->getGlobalBounds().height - 5.f);

	this->m_Font = new Font;
	if (!this->m_Font->loadFromFile("Assets/Fonts/Sitka.ttc"))
		return;

	this->m_Text = new Text;
	this->m_Text->setFont(*this->m_Font);
	this->m_Text->setCharacterSize(36);
	this->m_Text->setFillColor(Color(250, 125, 0));
	this->m_Text->setOutlineColor(Color::Black);
	this->m_Text->setOutlineThickness(1.f);
	this->updateText();
}

void KillCount::updateText(void) {
	if (this->m_Text == nullptr)
		return;

	string text;
	text += to_string(this->getScore());
	this->m_Text->setString(text);
	this->m_Text->setPosition(this->getPosition().x + this->getGlobalBounds().width / 2.f - this->m_Text->getGlobalBounds().width / 2.f,
		this->getPosition().y + this->getGlobalBounds().height / 2.f - this->m_Text->getGlobalBounds().height * 2.f);
}

void KillCount::setScore(int _value) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Text == nullptr)
		return;

	this->m_Score = _value;
	this->updateText();
}

void KillCount::render(void) {
	if (this->m_GameManager == nullptr)
		return;
	
	if (this->m_Text == nullptr)
		return;

	this->m_GameManager->getWindow()->draw(*this);
	this->m_GameManager->getWindow()->draw(*this->m_Text);
}
#include "AmmoInfo.h"
#include "Rifle.h"

AmmoInfo::AmmoInfo(Gun* _gun, RenderWindow* _renderWindow)
	: m_Min(0), m_Max(0)
{
	this->m_RenderWindow = _renderWindow;
	this->m_Gun = _gun;

	this->m_AmmoTexture = new Texture;
	if (!this->m_AmmoTexture->loadFromFile("Assets/Textures/Objects/Bullet.png"))
		return;

	this->setTexture(*this->m_AmmoTexture);
	this->setPosition(10.f, WINDOW_Y - this->getGlobalBounds().height - 10.f);

	this->m_AmmoFont = new Font;
	if (!this->m_AmmoFont->loadFromFile("Assets/Fonts/Sitka.ttc"))
		return;

	this->m_AmmoText = new Text;
	this->m_AmmoText->setFont(*this->m_AmmoFont);
	this->m_AmmoText->setCharacterSize(36);
	this->updateText();
	this->m_AmmoText->setFillColor(Color(250, 125, 0));
	this->m_AmmoText->setOutlineColor(Color::Black);
	this->m_AmmoText->setOutlineThickness(1.f);
	this->m_AmmoText->setPosition(this->getPosition().x + this->getGlobalBounds().width + 5.f,
		this->getPosition().y + this->getGlobalBounds().height / 2.f - this->m_AmmoText->getGlobalBounds().height);
}

void AmmoInfo::updateText(void) {
	if (this->m_AmmoText == nullptr)
		return;

	if (this->m_Gun == nullptr)
		return;

	this->setMin(this->m_Gun->getAmmo());
	this->setMax(this->m_Gun->getMaxAmmo());

	string text;
	text += to_string(this->m_Min) + "/" + to_string(this->m_Max);
	this->m_AmmoText->setString(text);
}

void AmmoInfo::setMax(int _value) {
	this->m_Max = _value;
}

void AmmoInfo::setMin(int _value) {
	this->m_Min = _value;
}

void AmmoInfo::changeGun(Gun* _gun) {
	if (_gun == nullptr)
		return;

	this->m_Gun = _gun;
	this->updateText();
}

void AmmoInfo::render(void) {
	if (this->m_RenderWindow == nullptr)
		return;

	if (this->m_Gun == nullptr)
		return;	

	if (this->m_AmmoText == nullptr)
		return;

	this->m_RenderWindow->draw(*this);
	this->m_RenderWindow->draw(*this->m_AmmoText);
}
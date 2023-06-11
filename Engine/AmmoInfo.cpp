#include "AmmoInfo.h"
#include "Rifle.h"

AmmoInfo::AmmoInfo(Rifle* _rifle, RenderWindow* _renderWindow)
	: m_Min(0), m_Max(0)
{
	this->m_RenderWindow = _renderWindow;
	this->m_Rifle = _rifle;

	this->m_AmmoTexture = new Texture;
	if (!this->m_AmmoTexture->loadFromFile("Assets/Textures/Objects/Bullet.png"))
		return;

	this->m_AmmoSprite = new Sprite;
	this->m_AmmoSprite->setTexture(*this->m_AmmoTexture);
	this->m_AmmoSprite->setPosition(10.f, WINDOW_Y - this->m_AmmoSprite->getGlobalBounds().height - 10.f);

	this->m_AmmoFont = new Font;
	if (!this->m_AmmoFont->loadFromFile("arial.ttf"))
		return;

	this->m_AmmoText = new Text;
	this->m_AmmoText->setFont(*this->m_AmmoFont);
	this->m_AmmoText->setCharacterSize(36);
	this->updateText();
	this->m_AmmoText->setFillColor(Color(250, 125, 0));
	this->m_AmmoText->setPosition(this->m_AmmoSprite->getPosition().x + this->m_AmmoSprite->getGlobalBounds().width + 5.f,
		this->m_AmmoSprite->getPosition().y + this->m_AmmoSprite->getGlobalBounds().height / 2.f - this->m_AmmoText->getGlobalBounds().height);
}

void AmmoInfo::updateText(void) {
	if (this->m_AmmoText == nullptr)
		return;

	if (this->m_Rifle == nullptr)
		return;

	Rifle* rifle = dynamic_cast<Rifle*>(this->m_Rifle);

	if (rifle == nullptr)
		return;

	this->setMin(rifle->getAmmo());
	this->setMax(rifle->getMaxAmmo());

	std::cout << this->m_Min << " " << this->m_Max << "\n";

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

void AmmoInfo::render(void) {
	if (this->m_RenderWindow == nullptr)
		return;

	if (this->m_Rifle == nullptr)
		return;	

	if (this->m_AmmoSprite == nullptr)
		return;

	if (this->m_AmmoText == nullptr)
		return;

	this->m_RenderWindow->draw(*this->m_AmmoSprite);
	this->m_RenderWindow->draw(*this->m_AmmoText);
}
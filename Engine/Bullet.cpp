#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(Weapon* _weapon)
	: m_Velocity(5.f), m_Weapon(nullptr)
{
	this->m_Texture = new Texture;
	if (!this->m_Texture->loadFromFile("Assets/Textures/Objects/Bullet.png"))
		return;

	this->m_Weapon = _weapon;

	this->setTexture(*this->m_Texture);
	//this->setOrigin(this->getGlobalBounds().width / 2.f, this->getGlobalBounds().height / 2.f);
	this->setScale(0.5f, 0.5f);
	this->setRotation(this->m_Weapon->getOwner()->getRotation() + 90.f);

	float r = ((256.f * this->m_Weapon->getOwner()->getScale().x) * (256.f * this->m_Weapon->getOwner()->getScale().x)) + ((128.f * this->m_Weapon->getOwner()->getScale().y) * (128.f * this->m_Weapon->getOwner()->getScale().y));
	float a = tan(this->m_Weapon->getOwner()->getRotation());
	float y = sqrt((a * r) / (1 + a));
	float x = y / a;

	Vector2f position = {
		this->m_Weapon->getOwner()->getPosition().x + 256.f * (this->m_Weapon->getOwner()->getScale().x) * cos(this->m_Weapon->getOwner()->getRotation()),
		this->m_Weapon->getOwner()->getPosition().y + 128.f * (this->m_Weapon->getOwner()->getScale().y) * sin(this->m_Weapon->getOwner()->getRotation())
	};

	this->setPosition(position);
}

void Bullet::update(RenderWindow* _rWindow) {
	if (this->m_Weapon == nullptr)
		return;

	sf::Vector2f position = { float(this->getPosition().x + (sin(this->getRotation() * M_PI / 180.f) * this->m_Velocity)),
		float(this->getPosition().y - (cos(this->getRotation() * M_PI / 180.f) * this->m_Velocity)) };

	this->setPosition(position.x, position.y);
	_rWindow->draw(*this);
}
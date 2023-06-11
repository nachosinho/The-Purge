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
	this->setScale(0.5f, 0.5f);
	this->setRotation(this->m_Weapon->getOwner()->getRotation() + 90.f);


	Vector2f position = this->m_Weapon->getOwner()->getPosition();

	this->setPosition(position.x + 260.f * this->m_Weapon->getOwner()->getScale().x * cos((this->m_Weapon->getOwner()->getRotation() + 20.f) * M_PI / 180.f),
		position.y + 260.f * this->m_Weapon->getOwner()->getScale().y * sin((this->m_Weapon->getOwner()->getRotation() + 20.f) * M_PI / 180.f));
}

void Bullet::update(RenderWindow* _rWindow) {
	if (this->m_Weapon == nullptr)
		return;

	sf::Vector2f position = { float(this->getPosition().x + (sin(this->getRotation() * M_PI / 180.f) * this->m_Velocity)),
		float(this->getPosition().y - (cos(this->getRotation() * M_PI / 180.f) * this->m_Velocity)) };

	this->setPosition(position.x, position.y);
	_rWindow->draw(*this);
}
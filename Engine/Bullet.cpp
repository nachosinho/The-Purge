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

	float angle = this->m_Weapon->getOwner()->getRotation();
	Vector2f distance = { 256.f, 128.f };
	float offsetX = cos(angle * M_PI / 180.f) * distance.x * this->m_Weapon->getOwner()->getScale().x;
	float offsetY = sin(angle * M_PI / 180.f) * distance.y * this->m_Weapon->getOwner()->getScale().y;
	float playerX = this->m_Weapon->getOwner()->getPosition().x;
	float playerY = this->m_Weapon->getOwner()->getPosition().y;
	float spriteX = playerX + offsetX;
	float spriteY = playerY + offsetY;

	this->setPosition(spriteX, spriteY);
}

void Bullet::update(RenderWindow* _rWindow) {
	if (this->m_Weapon == nullptr)
		return;

	sf::Vector2f position = { float(this->getPosition().x + (sin(this->getRotation() * M_PI / 180.f) * this->m_Velocity)),
		float(this->getPosition().y - (cos(this->getRotation() * M_PI / 180.f) * this->m_Velocity)) };

	this->setPosition(position.x, position.y);
	std::cout << this->getPosition().x << " " << this->getPosition().y << "\n";
	_rWindow->draw(*this);
}
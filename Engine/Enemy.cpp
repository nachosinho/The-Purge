#include "Enemy.h"
#include "GameManager.h"

Enemy::Enemy(GameManager* _gameManager) {
	this->m_GameManager = _gameManager;

	this->setScale(0.25f, 0.25f);
	//this->setPosition(WINDOW_X / 2.f - this->getGlobalBounds().width / 2.f, WINDOW_Y / 2.f - this->getGlobalBounds().height / 2.f);
	this->setPosition(10.f, 10.f);

	this->m_HealthBar = new HealthBar(this, this->m_GameManager->getWindow());
	//this->m_HealthBar->setColor(Color::Green);

	this->loadAnimations();
}

void Enemy::loadAnimations(void) {
	this->addAnimation(new Animation(this, "IDLE", "Assets/Textures/Enemy/Idle.png", { 241, 222 }, 17));
	this->addAnimation(new Animation(this, "ATTACK", "Assets/Textures/Enemy/Attack.png", { 318, 294 }, 9));
	this->addAnimation(new Animation(this, "MOVE", "Assets/Textures/Enemy/Walk.png", { 288, 311 }, 17));

	this->setAnimation("MOVE");
}

void Enemy::animationControl(void) {
	if (this->getCurrentAnimation()->getName() == "ATTACK")
		return;

	if (Keyboard::isKeyPressed(Keyboard::W) ||
		Keyboard::isKeyPressed(Keyboard::S) ||
		Keyboard::isKeyPressed(Keyboard::A) ||
		Keyboard::isKeyPressed(Keyboard::D))
		this->setAnimation("MOVE");
	else this->setAnimation("IDLE");
}

void Enemy::moveControl(void) {
	this->animationControl();

	Vector2f playerPos = { this->m_GameManager->getPlayer()->getPosition().x + this->m_GameManager->getPlayer()->getGlobalBounds().width / 4.f,
	this->m_GameManager->getPlayer()->getPosition().y + this->m_GameManager->getPlayer()->getGlobalBounds().height / 4.f };
	Vector2f direction = playerPos - this->getPosition();
	float rotation = atan2(direction.y, direction.x) * 180.f / M_PI;

	sf::Vector2f position = { cos(rotation * M_PI / 180.f) * PLAYER_SPEED / 3.f, sin(rotation * M_PI / 180.f) * PLAYER_SPEED / 3.f };

	this->setRotation(rotation);
	this->move(position);

	if (this->m_HealthBar->getPosition().y <= 0)
		this->move(0.f, PLAYER_SPEED);
	if (this->m_HealthBar->getPosition().y + this->m_HealthBar->getSize().y + this->getGlobalBounds().height >= WINDOW_Y)
		this->move(0.f, -PLAYER_SPEED);
	//else this->setAnimation("IDLE");
}

void Enemy::render(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_GameManager->getPlayer() == nullptr)
		return;

	this->moveControl();
	std::cout << m_CurrentAnimation->getCurrentFrame() << "\n";
	this->m_CurrentAnimation->render(this->m_GameManager->getClock()->restart().asSeconds() * 100.f);
	this->m_GameManager->getWindow()->draw(*this);
	this->m_HealthBar->render();
}
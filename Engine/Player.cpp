#include "Player.h"
#include "GameManager.h"

Player::Player(GameManager* _gameManager) {
	this->m_GameManager = _gameManager;

	this->setScale(0.25f, 0.25f);
	this->setPosition(WINDOW_X / 2.f - this->getGlobalBounds().width / 2.f, WINDOW_Y / 2.f - this->getGlobalBounds().height / 2.f);

	this->m_HealthBar = new HealthBar(this, this->m_GameManager->getWindow());
	this->m_HealthBar->setColor(Color::Green);

	this->loadAnimations();
}

void Player::loadAnimations(void) {
	this->addAnimation("IDLE", new Animation(this, "Assets/Textures/Player/Idle.png", { 313, 207 }, 20));
	this->addAnimation("ATTACK", new Animation(this, "Assets/Textures/Player/Attack.png", { 313, 207 }, 3));
	this->addAnimation("MOVE", new Animation(this, "Assets/Textures/Player/Move.png", { 313, 207 }, 20));
	this->addAnimation("RELOAD", new Animation(this, "Assets/Textures/Player/Reload.png", { 313, 207 }, 20));

	this->setAnimation("IDLE");
}

void Player::moveControl(void) {
	Vector2f mousePosition = Vector2f(Mouse::getPosition(*this->m_GameManager->getWindow()));
	Vector2f playerPosition = this->getPosition();
	Vector2f direction = mousePosition - playerPosition;
	float rotation = atan2(direction.y, direction.x) * 180.f / M_PI - 5.f;
	this->setRotation(rotation);
	this->setOrigin(this->getGlobalBounds().width / 2.f, this->getGlobalBounds().height / 2.f);

	if (Keyboard::isKeyPressed(Keyboard::W))
		this->move(0.f, -PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::S))
		this->move(0.f, PLAYER_SPEED);
	if (Keyboard::isKeyPressed(Keyboard::A))
		this->move(-PLAYER_SPEED, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		this->move(PLAYER_SPEED, 0.f);

	if (Keyboard::isKeyPressed(Keyboard::Space))
		this->setAnimation("MOVE");
	else if (Keyboard::isKeyPressed(Keyboard::R))
		this->setAnimation("RELOAD");
	else if (Mouse::isButtonPressed(Mouse::Left))
		this->setAnimation("ATTACK");
	else this->setAnimation("IDLE");
}

void Player::render(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_HealthBar == nullptr)
		return;

	this->moveControl();

	float deltaTime = this->m_GameManager->getClock()->restart().asSeconds();
	//std::cout << m_CurrentAnimation->getFrame().left << std::endl;
	this->m_CurrentAnimation->render(deltaTime);
	this->m_GameManager->getWindow()->draw(*this);
	this->m_HealthBar->render();
}
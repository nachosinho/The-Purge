#include "Player.h"
#include "GameManager.h"

Player::Player(GameManager* _gameManager) {
	this->m_GameManager = _gameManager;
	this->m_Weapon = new Rifle(_gameManager, this);

	this->setScale(0.25f, 0.25f);
	this->setPosition(WINDOW_X / 2.f - this->getGlobalBounds().width / 2.f, WINDOW_Y / 2.f - this->getGlobalBounds().height / 2.f);

	this->m_HealthBar = new HealthBar(this, this->m_GameManager->getWindow());
	this->m_HealthBar->setColor(Color::Green);

	this->m_AmmoInfo = new AmmoInfo(dynamic_cast<Rifle*>(this->m_Weapon), this->m_GameManager->getWindow());
	this->m_AmmoInfo->updateText();

	this->loadSFXs();
	this->loadAnimations();
}

void Player::loadSFXs(void) {
	this->addSFX(new SFX("ATTACK", "Assets/Sounds/SFX/Rifle_Shot.ogg"));
	this->addSFX(new SFX("RELOAD", "Assets/Sounds/SFX/Rifle_Reload.ogg"));
	this->addSFX(new SFX("EMPTY", "Assets/Sounds/SFX/Rifle_Empty.ogg"));
	this->addSFX(new SFX("DEATH", "Assets/Sounds/SFX/Player_Death.ogg"));
}

void Player::loadAnimations(void) {
	this->addAnimation(new Animation(this, "IDLE", "Assets/Textures/Player/Idle.png", { 313, 207 }, 20));
	this->addAnimation(new Animation(this, "ATTACK", "Assets/Textures/Player/Attack.png", { 313, 207 }, 3));
	this->addAnimation(new Animation(this, "MOVE", "Assets/Textures/Player/Move.png", { 313, 207 }, 20));
	this->addAnimation(new Animation(this, "RELOAD", "Assets/Textures/Player/Reload.png", { 313, 207 }, 20));

	this->setAnimation("IDLE");
}

void Player::animationControl(void) {
	if (this->getCurrentAnimation()->getName() == "ATTACK" ||
		this->getCurrentAnimation()->getName() == "RELOAD")
		return;

	if (Keyboard::isKeyPressed(Keyboard::W) ||
		Keyboard::isKeyPressed(Keyboard::S) ||
		Keyboard::isKeyPressed(Keyboard::A) ||
		Keyboard::isKeyPressed(Keyboard::D))
		this->setAnimation("MOVE");
	else this->setAnimation("IDLE");
}

void Player::moveControl(void) {
	this->animationControl();
	Vector2f mousePosition = Vector2f(Mouse::getPosition(*this->m_GameManager->getWindow()));
	Vector2f playerPosition = this->getPosition();
	Vector2f direction = mousePosition - playerPosition;
	float rotation = atan2(direction.y, direction.x) * 180.f / M_PI - 5.f;
	this->setRotation(rotation);
	this->setOrigin(this->getGlobalBounds().width / 2.f, this->getGlobalBounds().height / 2.f);

	if (Keyboard::isKeyPressed(Keyboard::W))
		this->move(0.f, -this->getVelocity());
	if (Keyboard::isKeyPressed(Keyboard::S))
		this->move(0.f, this->getVelocity());
	if (Keyboard::isKeyPressed(Keyboard::A))
		this->move(-this->getVelocity(), 0.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		this->move(this->getVelocity(), 0.f);

	if (this->m_HealthBar->getPosition().x <= 0)
		this->move(this->getVelocity(), 0.f);
	if (this->m_HealthBar->getPosition().x + this->m_HealthBar->getSize().x >= WINDOW_X)
		this->move(-this->getVelocity(), 0.f);

	if (this->m_HealthBar->getPosition().y <= 0)
		this->move(0.f, this->getVelocity());
	if (this->m_HealthBar->getPosition().y + this->m_HealthBar->getSize().y + this->getGlobalBounds().height >= WINDOW_Y)
		this->move(0.f, -this->getVelocity());

	else if (Keyboard::isKeyPressed(Keyboard::R))
		dynamic_cast<Rifle*>(this->m_Weapon)->reload();
	else if (Mouse::isButtonPressed(Mouse::Left))
		dynamic_cast<Rifle*>(this->m_Weapon)->shoot();
}

void Player::reset(void) {
	if (this->m_GameManager == nullptr)
		return;

	this->setPosition(WINDOW_X / 2.f - this->getGlobalBounds().width / 2.f, WINDOW_Y / 2.f - this->getGlobalBounds().height / 2.f);
	this->setRotation(0.f);
	this->setMaxHealth(100);
}

void Player::render(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_HealthBar == nullptr)
		return;

	if (this->m_Weapon == nullptr)
		return;

	if (this->m_AmmoInfo == nullptr)
		return;

	this->moveControl();

	if (this->getHealth() <= 0) {
		this->m_GameManager->setMenu("OVER");
		return;
	}

	this->m_CurrentAnimation->render(this->m_GameManager->getElapsedTime());
	this->m_GameManager->getWindow()->draw(*this);
	this->m_Weapon->update();
	this->m_HealthBar->render();
	this->m_AmmoInfo->render();
}
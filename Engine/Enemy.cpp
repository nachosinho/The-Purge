#include "Enemy.h"
#include "GameManager.h"

Enemy::Enemy(GameManager* _gameManager) {
	this->m_GameManager = _gameManager;
	this->m_Weapon = new Melee(_gameManager, this);

	this->setScale(0.25f, 0.25f);
	//this->setPosition(WINDOW_X / 2.f - this->getGlobalBounds().width / 2.f, WINDOW_Y / 2.f - this->getGlobalBounds().height / 2.f);
	Vector2i startingPosition = { rand() % 2, rand() % 2 };

	if (startingPosition.x) startingPosition.x = WINDOW_X + rand() % 200 + 50.f;
	else startingPosition.x = -(rand() % 200) - 50.f;

	if (startingPosition.y) startingPosition.y = WINDOW_Y + rand() % 200 + 50.f;
	else startingPosition.y = -(rand() % 200) - 50.f;

	this->setPosition(Vector2f(startingPosition));

	this->m_HealthBar = new HealthBar(this, this->m_GameManager->getWindow());
	//this->m_HealthBar->setColor(Color::Green);

	this->loadAnimations();
}

void Enemy::loadAnimations(void) {
	this->addAnimation(new Animation(this, "IDLE", "Assets/Textures/Enemy/Idle.png", { 241, 222 }, 17));
	this->addAnimation(new Animation(this, "ATTACK", "Assets/Textures/Enemy/Attack.png", { 318, 294 }, 9));
	this->addAnimation(new Animation(this, "MOVE", "Assets/Textures/Enemy/Walk.png", { 288, 311 }, 17));

	this->setAnimation("IDLE");
}

void Enemy::animationControl(void) {
	if (this->getCurrentAnimation()->getName() == "ATTACK")
		return;

	this->setAnimation("MOVE");
}

void Enemy::moveControl(void) {
	this->animationControl();

	if (this->getCurrentAnimation()->getName() == "ATTACK")
		return;

	Vector2f playerPos = { this->m_GameManager->getPlayer()->getPosition().x + this->m_GameManager->getPlayer()->getGlobalBounds().width / 4.f,
	this->m_GameManager->getPlayer()->getPosition().y + this->m_GameManager->getPlayer()->getGlobalBounds().height / 4.f };
	Vector2f direction = playerPos - this->getPosition();
	float rotation = atan2(direction.y, direction.x) * 180.f / M_PI;

	sf::Vector2f position = { cos(rotation * M_PI / 180.f) * PLAYER_SPEED / 3.f, sin(rotation * M_PI / 180.f) * PLAYER_SPEED / 3.f };

	if (this->m_HealthBar->getPosition().y <= 0)
		this->move(0.f, PLAYER_SPEED);
	if (this->m_HealthBar->getPosition().y + this->m_HealthBar->getSize().y + this->getGlobalBounds().height >= WINDOW_Y)
		this->move(0.f, -PLAYER_SPEED);

	RectangleShape hitbox;
	FloatRect playerHitbox = this->m_GameManager->getPlayer()->getGlobalBounds();


	hitbox.setPosition(playerHitbox.left, playerHitbox.top);
	hitbox.setSize(Vector2f(playerHitbox.width, playerHitbox.height));


	hitbox.setOutlineColor(Color::Red);
	hitbox.setOutlineThickness(1.f);

	hitbox.setPosition(playerPos);
	hitbox.setSize({20, 20});

	this->m_GameManager->getWindow()->draw(hitbox);

	sf::Vector2f distanceVec = { abs(hitbox.getPosition().x - this->getPosition().x),
		abs(hitbox.getPosition().y - this->getPosition().y - this->getGlobalBounds().height / 2.f) };
	float distanceFloat = sqrt(distanceVec.x * distanceVec.x + distanceVec.y * distanceVec.y);

	if (distanceFloat > 50.f) {
		this->setRotation(rotation);
		this->move(position);
	} else dynamic_cast<Melee*>(this->m_Weapon)->attack(this->m_GameManager->getPlayer());
}

void Enemy::render(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_GameManager->getPlayer() == nullptr)
		return;

	this->moveControl();

	this->m_CurrentAnimation->render(this->m_GameManager->getClock()->restart().asSeconds() * 50000.f);
	this->m_GameManager->getWindow()->draw(*this);
	this->m_HealthBar->render();
	this->m_Weapon->update();
}
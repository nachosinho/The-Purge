#include "Player.h"
#include "GameManager.h"

Player::Player(GameManager* _gameManager) {
	this->m_GameManager = _gameManager;
	this->m_Weapons = new vector<Weapon*>{ new Pistol(this->m_GameManager, this), new Rifle(this->m_GameManager, this), new Shotgun(this->m_GameManager, this) };

	this->setScale(0.25f, 0.25f);
	this->setPosition(WINDOW_X / 2.f - this->getGlobalBounds().width / 2.f, WINDOW_Y / 2.f - this->getGlobalBounds().height / 2.f);

	this->m_HealthBar = new HealthBar(this, this->m_GameManager->getWindow());
	this->m_HealthBar->setColor(Color::Green);

	this->equipWeapon((*this->m_Weapons)[Weapon::WEAPONTYPE::RIFLE]);

	this->m_AmmoInfo = new AmmoInfo(dynamic_cast<Gun*>(this->m_Weapon), this->m_GameManager->getWindow());
	this->m_AmmoInfo->updateText();


	this->loadSFXs();
	this->loadAnimations();
}


void Player::loadSFXs(void) {
	this->addSFX(new SFX("PISTOL_ATTACK", "Assets/Sounds/SFX/Pistol_Attack.ogg"));
	this->addSFX(new SFX("PISTOL_RELOAD", "Assets/Sounds/SFX/Pistol_Reload.ogg"));
	this->addSFX(new SFX("PISTOL_SWITCH", "Assets/Sounds/SFX/Pistol_Switch.ogg"));

	this->addSFX(new SFX("RIFLE_ATTACK", "Assets/Sounds/SFX/Rifle_Attack.ogg"));
	this->addSFX(new SFX("RIFLE_RELOAD", "Assets/Sounds/SFX/Rifle_Reload.ogg"));
	this->addSFX(new SFX("RIFLE_SWITCH", "Assets/Sounds/SFX/Rifle_Switch.ogg"));

	this->addSFX(new SFX("SHOTGUN_ATTACK", "Assets/Sounds/SFX/Shotgun_Attack.ogg"));
	this->addSFX(new SFX("SHOTGUN_RELOAD", "Assets/Sounds/SFX/Shotgun_Reload.ogg"));
	this->addSFX(new SFX("SHOTGUN_SWITCH", "Assets/Sounds/SFX/Shotgun_Switch.ogg"));

	this->addSFX(new SFX("WEAPON_EMPTY", "Assets/Sounds/SFX/Weapon_Empty.ogg"));

	this->addSFX(new SFX("DEATH", "Assets/Sounds/SFX/Player_Death.ogg"));
}

void Player::loadAnimations(void) {
	this->addAnimation(new Animation(this, "RIFLE_IDLE", "Assets/Textures/Player/Rifle_Idle.png", { 313, 207 }, 20));
	this->addAnimation(new Animation(this, "RIFLE_ATTACK", "Assets/Textures/Player/Rifle_Attack.png", { 313, 207 }, 3));
	this->addAnimation(new Animation(this, "RIFLE_MOVE", "Assets/Textures/Player/Rifle_Move.png", { 313, 207 }, 20));
	this->addAnimation(new Animation(this, "RIFLE_RELOAD", "Assets/Textures/Player/Rifle_Reload.png", { 313, 207 }, 20));
	this->addAnimation(new Animation(this, "RIFLE_SWITCH", "Assets/Textures/Player/Rifle_Switch.png", { 313, 310 }, 15));

	this->addAnimation(new Animation(this, "PISTOL_IDLE", "Assets/Textures/Player/Pistol_Idle.png", { 253, 216 }, 20));
	this->addAnimation(new Animation(this, "PISTOL_ATTACK", "Assets/Textures/Player/Pistol_Attack.png", { 255, 215 }, 3));
	this->addAnimation(new Animation(this, "PISTOL_MOVE", "Assets/Textures/Player/Pistol_Move.png", { 258, 220 }, 20));
	this->addAnimation(new Animation(this, "PISTOL_RELOAD", "Assets/Textures/Player/Pistol_Reload.png", { 260, 230 }, 15));
	this->addAnimation(new Animation(this, "PISTOL_SWITCH", "Assets/Textures/Player/Pistol_Switch.png", { 291, 256 }, 15));

	this->addAnimation(new Animation(this, "SHOTGUN_IDLE", "Assets/Textures/Player/Shotgun_Idle.png", { 313, 207 }, 20));
	this->addAnimation(new Animation(this, "SHOTGUN_ATTACK", "Assets/Textures/Player/Shotgun_Attack.png", { 312, 206 }, 3));
	this->addAnimation(new Animation(this, "SHOTGUN_MOVE", "Assets/Textures/Player/Shotgun_Move.png", { 313, 206 }, 20));
	this->addAnimation(new Animation(this, "SHOTGUN_RELOAD", "Assets/Textures/Player/Shotgun_Reload.png", { 322, 217 }, 20));
	this->addAnimation(new Animation(this, "SHOTGUN_SWITCH", "Assets/Textures/Player/Shotgun_Switch.png", { 358, 353 }, 15));

	this->setAnimation(this->m_Weapon->getName() + "_IDLE");
}

void Player::animationControl(void) {
	if (this->getCurrentAnimation()->getName() == this->m_Weapon->getName() + "_ATTACK" ||
		this->getCurrentAnimation()->getName() == this->m_Weapon->getName() + "_RELOAD" ||
		this->getCurrentAnimation()->getName() == this->m_Weapon->getName() + "_SWITCH")
		return;

	if (Keyboard::isKeyPressed(Keyboard::W) ||
		Keyboard::isKeyPressed(Keyboard::S) ||
		Keyboard::isKeyPressed(Keyboard::A) ||
		Keyboard::isKeyPressed(Keyboard::D))
		this->setAnimation(this->m_Weapon->getName() + "_MOVE");
	else this->setAnimation(this->m_Weapon->getName() + "_IDLE");
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
		dynamic_cast<Gun*>(this->m_Weapon)->reload();

	else if (Mouse::isButtonPressed(Mouse::Left))
		dynamic_cast<Gun*>(this->m_Weapon)->shoot();

	else if (Keyboard::isKeyPressed(Keyboard::Num1)) {
		if (dynamic_cast<Gun*>(this->m_Weapon)->getName() != "PISTOL")
			dynamic_cast<Gun*>(this->m_Weapon)->switchWeapon(Weapon::WEAPONTYPE::PISTOL);
	}

	else if (Keyboard::isKeyPressed(Keyboard::Num2)) {
		if (dynamic_cast<Gun*>(this->m_Weapon)->getName() != "RIFLE")
			dynamic_cast<Gun*>(this->m_Weapon)->switchWeapon(Weapon::WEAPONTYPE::RIFLE);
	}

	else if (Keyboard::isKeyPressed(Keyboard::Num3)) {
		if (dynamic_cast<Gun*>(this->m_Weapon)->getName() != "SHOTGUN")
			dynamic_cast<Gun*>(this->m_Weapon)->switchWeapon(Weapon::WEAPONTYPE::SHOTGUN);
	}
}

void Player::reset(void) {
	if (this->m_GameManager == nullptr)
		return;

	this->setPosition(WINDOW_X / 2.f - this->getGlobalBounds().width / 2.f, WINDOW_Y / 2.f - this->getGlobalBounds().height / 2.f);
	this->setRotation(0.f);
	this->setMaxHealth(100);
	this->setVelocity(this->DEFAULT_VELOCITY);
	for (Weapon* _gun : (*this->getWeapons()))
		dynamic_cast<Gun*>(_gun)->reset();
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

		if (this->m_GameManager->getScoreBoard() == nullptr)
			return;

		if (this->m_GameManager->getKillCount() == nullptr)
			return;

		this->m_GameManager->getScoreBoard()->addScore(this->m_GameManager->getKillCount()->getScore());
		return;
	}

	this->m_CurrentAnimation->render(this->m_GameManager->getElapsedTime());
	this->m_GameManager->getWindow()->draw(*this);
	this->m_Weapon->update();
	this->m_HealthBar->render();
	this->m_AmmoInfo->render();
}
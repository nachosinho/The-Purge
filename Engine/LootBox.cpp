#include "LootBox.h"
#include "GameManager.h"

LootBox_Bonus::LootBox_Bonus(string _text, Color _color)
	: m_Text(_text), m_Color(_color) {}

LootBox::LootBox(GameManager* _gameManager)
	: m_RefreshTime(0.f), m_NotificationTime(0.f), m_IsPlaced(false), m_CurrentBonus(-1)
{
	this->m_GameManager = _gameManager;
	if (this->m_GameManager == nullptr)
		return;

	this->m_Player = this->m_GameManager->getPlayer();
	if (this->m_Player == nullptr)
		return;

	this->m_BonusDesc = {
		LootBox_Bonus("Damage boost", Color(255, 111, 15, 255)),
		LootBox_Bonus("Extra ammunition", Color(171, 217, 56, 255)),
		LootBox_Bonus("Faster bullets", Color(148, 251, 255, 255)),
		LootBox_Bonus("Faster reload", Color(223, 148, 255, 255)),
		LootBox_Bonus("Health boost", Color(219, 37, 52, 255)),
		LootBox_Bonus("Faster movement", Color(246, 255, 161, 255))
	};

	this->m_Texture = new Texture;
	if (!this->m_Texture->loadFromFile("Assets/Textures/Objects/LootBox.png"))
		return;

	this->setTexture(*this->m_Texture);
	this->setScale(0.75f, 0.75f);

	this->m_Font = new Font;
	if (!this->m_Font->loadFromFile("arial.ttf"))
		return;

	this->m_Text = new Text;
	this->m_Text->setFont(*this->m_Font);
	this->m_Text->setOutlineColor(Color::Black);
	this->m_Text->setOutlineThickness(1.f);
	this->m_Text->setCharacterSize(36);
	this->m_Text->setPosition(5.f, 5.f);
}

void LootBox::checkCollision(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Player == nullptr)
		return;

	if (this->m_Player->getGlobalBounds().intersects(this->getGlobalBounds())) {
		this->assignBonus();
		this->reset();
	}
}

void LootBox::rollBonus(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Player == nullptr)
		return;

	this->m_CurrentBonus = rand() % LootBox::BONUSTYPE::ENUMRANGE;
}

void LootBox::assignBonus(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Player == nullptr)
		return;

	Gun* playerWeapon = dynamic_cast<Gun*>(this->m_Player->getWeapon());
	if (playerWeapon == nullptr)
		return;

	switch (this->m_CurrentBonus) {
	case LootBox::BONUSTYPE::DAMAGE:
		playerWeapon->setDamage(playerWeapon->getDamage() + 5);
		break;
	case LootBox::BONUSTYPE::AMMUNITION:
		playerWeapon->setMaxAmmo(playerWeapon->getMaxAmmo() * 1.5f);
		this->m_Player->getAmmoInfo()->updateText();
		break;
	case LootBox::BONUSTYPE::BULLET_VELOCITY:
		playerWeapon->setBulletVelocity(playerWeapon->getBulletVelocity() * 1.1f);
		break;
	case LootBox::BONUSTYPE::RELOAD_TIME:
		playerWeapon->setDelay(playerWeapon->getDelay() / 1.1f);
		break;
	case LootBox::BONUSTYPE::HEALTH:
		this->m_Player->setMaxHealth(this->m_Player->getMaxHealth() * 1.1f);
		break;
	case LootBox::BONUSTYPE::MOVEMENT_VELOCITY:
		this->m_Player->setVelocity(this->m_Player->getVelocity() * 1.1f);
		break;
	default:
		break;
	}

	if (this->m_CurrentBonus != -1) {
		m_Text->setFillColor(this->m_BonusDesc[this->m_CurrentBonus].m_Color);
		m_Text->setString(this->m_BonusDesc[this->m_CurrentBonus].m_Text);
		this->m_NotificationTime = 1.4f;
	}

	std::cout << this->m_CurrentBonus << std::endl;
	this->reset();
}

void LootBox::spawn(void) {
	if (this->m_Texture == nullptr)
		return;

	this->rollBonus();
	this->setPosition(rand() % (int)(WINDOW_X - this->getGlobalBounds().width),
		rand() % (int)(WINDOW_Y - this->getGlobalBounds().height));
}

void LootBox::reset(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Player == nullptr)
		return;

	this->m_RefreshTime = 0.f;
	this->m_IsPlaced = false;
	this->m_CurrentBonus = -1;
}

void LootBox::render(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Texture == nullptr)
		return;

	if (this->m_Text == nullptr)
		return;

	this->m_RefreshTime += this->m_GameManager->getElapsedTime();

	if (this->m_RefreshTime >= REFRESH_TIME) {
		this->m_IsPlaced = !this->m_IsPlaced;
		this->m_RefreshTime = 0.f;

		if (this->m_IsPlaced)
			this->spawn();
	}	

	if (this->m_NotificationTime > 0.f) {
		this->m_NotificationTime -= this->m_GameManager->getElapsedTime();
			this->m_Text->setFillColor(Color(this->m_Text->getFillColor().r,
				this->m_Text->getFillColor().g,
				this->m_Text->getFillColor().b,
				this->m_Text->getFillColor().a - 2.5f));
		this->m_GameManager->getWindow()->draw(*this->m_Text);
	}

	if (this->m_IsPlaced) {
		this->m_GameManager->getWindow()->draw(*this);
		this->checkCollision();
	}
}
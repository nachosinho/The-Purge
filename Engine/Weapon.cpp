#include "GameManager.h"

#include "Melee.h"
#include "Pistol.h"
#include "Rifle.h"

Weapon::Weapon(GameManager* _gameManager, NPC* _player)
	: m_Damage(1), m_Name("NULL"), m_Delay(0.05f), m_Cooldown(0.05f), m_NextWeapon(-1), m_WeaponType(Weapon::WEAPONTYPE::NONE)
{
	this->m_GameManager = _gameManager;
	this->m_Owner = _player;

	if (m_GameManager == nullptr)
		return;

	if (this->getOwner() == nullptr)
		return;

}

void Weapon::equipNextWeapon(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Owner == nullptr)
		return;

	if (this->m_NextWeapon == -1)
		return;

	dynamic_cast<Player*>(this->m_Owner)->equipWeapon((*dynamic_cast<Player*>(this->m_Owner)->getWeapons())[this->m_NextWeapon]);
	this->m_NextWeapon = -1;
}

void Weapon::setDamage(int _value) {
	if (_value < 0) _value = 0;
	this->m_Damage = _value;
}

void Weapon::setCooldown(float _value) {
	if (_value < 0.f) _value = 0.f;
	this->m_Cooldown = _value;
}

void Weapon::setDelay(float _value) {
	if (_value < 0.f) _value = 0.f;
	this->m_Delay = _value;
	this->m_Cooldown = this->m_Delay;
}

void Weapon::switchWeapon(int _weaponType) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Owner == nullptr)
		return;

	Animation* anim = this->m_Owner->getCurrentAnimation();

	if (anim->getName() != this->getName() + "_MOVE" &&
		anim->getName() != this->getName() + "_IDLE")
		return;

	this->m_Owner->setAnimation(this->getName() + "_SWITCH");
	this->m_Owner->playSFX(this->getName() + "_SWITCH");
	this->m_NextWeapon = _weaponType;
}

void Weapon::reset(void) {
	if (this->m_GameManager == nullptr)
		return;

	switch (this->m_WeaponType) {
	case Weapon::WEAPONTYPE::PISTOL:
	case Weapon::WEAPONTYPE::RIFLE:
	case Weapon::WEAPONTYPE::SHOTGUN:
		dynamic_cast<Gun*>(this)->getBullets()->clear();
		dynamic_cast<Gun*>(this)->setBulletVelocity(this->DEFAULT_BULLET_VELOCITY[this->m_WeaponType]);
		dynamic_cast<Gun*>(this)->setMaxAmmo(this->DEFAULT_MAX_AMMO[this->m_WeaponType]);
	case Weapon::WEAPONTYPE::MELEE:
		this->setDamage(this->DEFAULT_DAMAGE[this->m_WeaponType]);
		this->setDelay(this->DEFAULT_DELAY[this->m_WeaponType]);
		break;
	case Weapon::WEAPONTYPE::NONE:
		break;
	default:break;
	}

}
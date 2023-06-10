#pragma once
#include "include.h"

class Bullet : public Sprite {
private:
	class Weapon* m_Weapon;
public:
	Bullet(class Weapon*) {};
};
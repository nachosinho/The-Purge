#pragma once
#include "include.h"

class Bullet : public Sprite {
private:
	Texture* m_Texture;
	class Weapon* m_Weapon;
public:
	Bullet(class Weapon*, int = 0);

	void update(RenderWindow*);
};
#pragma once
#include "include.h"

class Bullet : public Sprite {
private:
	Texture* m_Texture;
	float m_Velocity;
	class Weapon* m_Weapon;
public:
	Bullet(class Weapon*);

	void update(RenderWindow*);
};
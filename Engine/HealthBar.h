#pragma once
#include "include.h"

class HealthBar {
private:
	RectangleShape* m_HealthBarBack, *m_HealthBarFront;
	RenderWindow* m_RenderWindow;
	class NPC* m_NPC;
public:
	HealthBar(class NPC*, RenderWindow*);

	Vector2f getPosition(void) { return this->m_HealthBarBack->getPosition(); }
	Vector2f getSize(void) { return this->m_HealthBarBack->getSize(); }

	void setColor(Color);
	void setPercentage(float);
	void setPosition(float, float);
	void setPosition(Vector2f);

	void render(void);
};
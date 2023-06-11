#pragma once
#include "SFX.h"

class Level : public Sprite {
private:
	Texture* m_Texture;
	SFX* m_SFX;

	class GameManager* m_GameManager;
public:
	Level(class GameManager*);

	SFX* getSFX(void) { return this->m_SFX; }

	void setSFX(SFX*);

	void addTexture(string);
	void manageMusic(void);

	void render(void);
};
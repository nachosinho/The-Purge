#pragma once
#include "../Engine/Level.h"

class Cemetery : public Level {
public:
	Cemetery(class GameManager* _gameManager)
		: Level(_gameManager)
	{
		this->addTexture("Assets/Textures/Levels/Cemetery.png");
		this->setSFX(new SFX("SOUNDTRACK", "Assets/Sounds/Music/Cemetery.ogg"));
	}
};
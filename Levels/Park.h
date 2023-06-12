#pragma once
#include "../Engine/Level.h"

class Park : public Level {
public:
	Park(class GameManager* _gameManager)
		: Level(_gameManager)
	{
		this->addTexture("Assets/Textures/Levels/Park.png");
		this->setSFX(new SFX("SOUNDTRACK", "Assets/Sounds/Music/Park.ogg"));
	}
};
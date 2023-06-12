#pragma once
#include "../Engine/Level.h"

class Bunkers : public Level {
public:
	Bunkers(class GameManager* _gameManager)
		: Level(_gameManager)
	{
		this->addTexture("Assets/Textures/Levels/Bunkers.png");
		this->setSFX(new SFX("SOUNDTRACK", "Assets/Sounds/Music/Bunkers.ogg"));
	}
};
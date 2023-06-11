#include "Level.h"
#include "GameManager.h"

Level::Level(GameManager* _gameManager) {
	this->m_GameManager = _gameManager;

	this->m_Texture = new Texture;
	this->m_SFX = nullptr;
}

void Level::setSFX(SFX* _sfx) {
	this->m_SFX = _sfx;
}

void Level::addTexture(string _texture) {
	if (this->m_Texture == nullptr)
		return;

	if (!this->m_Texture->loadFromFile(_texture))
		return;

	this->setTexture(*this->m_Texture);
}

void Level::manageMusic(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_SFX == nullptr)
		return;

	if (this->m_GameManager->getGameStatus() == GameManager::GAMESTATE::PAUSED) {
		if (this->getSFX()->getVolume() == 100.f)
			this->getSFX()->setVolume(50.f);
	}
	else if (this->m_GameManager->getGameStatus() == GameManager::GAMESTATE::PLAYING) {
		if (this->getSFX()->getVolume() == 50.f)
			this->getSFX()->setVolume(100.f);
	}
}

void Level::render(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Texture == nullptr)
		return;

	this->m_GameManager->getWindow()->draw(*this);
}
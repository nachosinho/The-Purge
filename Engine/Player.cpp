#include "Player.h"
#include "GameManager.h"

Player::Player(GameManager* _gameManager) {
	this->m_GameManager = _gameManager;
}

void Player::render(void) {
	if (this->m_GameManager == nullptr)
		return;

	float deltaTime = this->m_GameManager->getClock()->restart().asSeconds();
	//std::cout << m_CurrentAnimation->getFrame().left << std::endl;
	//m_CurrentAnimation->render(deltaTime);
	this->m_GameManager->getWindow()->draw(*this);
}
#include "EnemySpawner.h"
#include "GameManager.h"

EnemySpawner::EnemySpawner(GameManager* _gameManager)
	: m_ElapsedTime(0.f)
{
	this->m_GameManager = _gameManager;
	this->m_Enemies = new vector<Enemy*>;
}

void EnemySpawner::addEnemy(Enemy* _enemy) {
	if (this->m_Enemies == nullptr)
		return;

	if (_enemy == nullptr)
		return;

	this->m_Enemies->push_back(_enemy);
}

void EnemySpawner::update(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Enemies == nullptr)
		return;

	for (int i = 0, end = this->m_Enemies->size(); i < end; i++) {
		Enemy* _enemy = (*this->m_Enemies)[i];
		if (_enemy == nullptr)
			continue;

		_enemy->render();
		if (_enemy->getHealth() <= 0) {
			_enemy->playSFX("DEATH");
			_enemy = nullptr;
			delete _enemy;
			this->m_Enemies->erase(this->m_Enemies->begin() + i);
			continue;
		}
	}

	this->m_ElapsedTime += this->m_GameManager->getClock()->restart().asSeconds() * 10.f;
	std::cout << m_ElapsedTime << " " << 0.0001f << std::endl;
	if (this->m_ElapsedTime >= 0.0001f) {
		this->addEnemy(new Enemy(this->m_GameManager));
		std::cout << "ENEMY\n";
		this->m_ElapsedTime = 0.f;
	}
}
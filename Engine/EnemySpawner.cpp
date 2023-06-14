#include "EnemySpawner.h"
#include "GameManager.h"

EnemySpawner::EnemySpawner(GameManager* _gameManager)
	: m_ElapsedTime(0.f)
{
	this->m_GameManager = _gameManager;
	this->m_Enemies = new vector<Enemy*>;

	if (this->m_GameManager == nullptr)
		return;

	for (int i = 0; i < 10; i++)
		this->addEnemy(new Enemy(this->m_GameManager));
}

void EnemySpawner::addEnemy(Enemy* _enemy) {
	if (this->m_Enemies == nullptr)
		return;

	if (_enemy == nullptr)
		return;

	this->m_Enemies->push_back(_enemy);
}

void EnemySpawner::reload(void) {
	if (this->m_Enemies == nullptr)
		return;

	for (Enemy* _enemy : *this->m_Enemies) {
		if (_enemy == nullptr)
			continue;
		_enemy->reset();
	}
}

void EnemySpawner::update(void) {
	if (this->m_GameManager == nullptr)
		return;

	if (this->m_Enemies == nullptr)
		return;

	if (this->m_GameManager->getKillCount() == nullptr)
		return;

	int score = this->m_GameManager->getKillCount()->getScore();

	for (Enemy* _enemy : *this->m_Enemies) {
		if (_enemy == nullptr)
			continue;

		_enemy->render();
		if (_enemy->getHealth() <= 0) {
			this->m_GameManager->getKillCount()->setScore(score + 1);
			_enemy->reset();
			_enemy->setMaxHealth(_enemy->getMaxHealth() + 10 * ((score / 5.f) - 1));
			_enemy->setVelocity(_enemy->getVelocity() + 0.1f * ((score / 10.f) - 1));
			continue;
		}
	}
}
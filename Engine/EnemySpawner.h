#pragma once
#include "Enemy.h"

class EnemySpawner {
private:
	vector<Enemy*>* m_Enemies;
	float m_ElapsedTime;

	class GameManager* m_GameManager;
public:
	EnemySpawner(class GameManager*);

	vector<Enemy*>* getEnemies(void) { return this->m_Enemies; }

	void addEnemy(Enemy*);

	void update(void);
};
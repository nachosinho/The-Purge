#include "GameManager.h"

GameManager::GameManager(void) {
	this->m_Window = new RenderWindow(VideoMode(WINDOW_X, WINDOW_Y), GAME_TITLE);
	this->m_Event = new Event;
	this->m_Clock = new Clock;
	this->m_WindowHandler = this->m_Window->getSystemHandle();
	this->m_ScoreBoard = new ScoreBoard;

	this->loadSettings();
	this->loadLevels();
	this->loadMenus();

	if (!DEBUGGING)
		this->setMenu("MAINMENU");
	else this->restartGame();

	this->render();
}

GameManager::~GameManager(void) {
	if (this->m_ScoreBoard == nullptr)
		return;

	if (this->m_ScoreBoard->getScore() == nullptr)
		return;

	this->m_ScoreBoard->saveScoreBoard();
}

void GameManager::loadSettings(void) {
	srand(time(NULL));

	this->m_Window->setFramerateLimit(FRAMERATE_LIMIT);
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, ENABLE_CONSOLE);

	if (DISABLE_TASKBAR) {
		HWND hwnd = m_WindowHandler;
		LONG style = GetWindowLong(hwnd, GWL_STYLE);
		style &= ~WS_SYSMENU;
		style &= ~WS_CAPTION;
		style &= ~WS_THICKFRAME;
		style &= ~WS_MINIMIZEBOX;
		style &= ~WS_MAXIMIZEBOX;
		SetWindowLong(hwnd, GWL_STYLE, style);
		SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
	}
}

void GameManager::loadMenus(void) {
	this->m_Menus = new map<string, Menu*>;
	this->addMenu(new MainMenu(this));
	this->addMenu(new PauseMenu(this));
	this->addMenu(new GameOverMenu(this));
}

void GameManager::loadLevels(void) {
	this->m_Levels = new vector<Level*> {
		new Bunkers(this),
		new Cemetery(this),
		new Park(this)
	};
}

void GameManager::eventManager(void) {
	if (this->getGameStatus() != GAMESTATE::PLAYING)
		return;

	while (this->m_Window->pollEvent(*this->m_Event))
		switch (this->m_Event->type) {
		case Event::Closed:
			this->m_Window->close();
			break;

		case Event::KeyPressed:
			if (this->m_Event->key.code == Keyboard::Escape &&
				this->getGameStatus() == GAMESTATE::PLAYING)
				this->setMenu("PAUSE");
			break;
		}
}

void GameManager::addMenu(Menu* _menu) {
	if (this->m_Menus->find(_menu->getName()) != this->m_Menus->end()) return;
	this->m_Menus->insert(pair<string, Menu*>(_menu->getName(), _menu));
}

void GameManager::setMenu(string _mapKey) {
	if (this->m_Menus->find(_mapKey) == this->m_Menus->end()) {
		this->m_Menu = nullptr;
		this->m_GameState = GameManager::GAMESTATE::PLAYING;
		return;
	}

	if (this->m_Menu == nullptr) {
		this->m_Menu = (*this->m_Menus)[_mapKey];

		this->m_Menu->reload();
		this->m_GameState = this->m_Menu->getGameState();

		if (this->m_Menu->getSFX() == nullptr)
			return;

		this->m_Menu->getSFX()->play();
	}

	else if (this->m_Menu->getName() != _mapKey) {
		this->m_Menu->reload();
		this->m_Menu = (*this->m_Menus)[_mapKey];
		this->m_Menu->reload();
		this->m_GameState = this->m_Menu->getGameState();

		if (this->m_Menu->getSFX() == nullptr)
			return;

		this->m_Menu->getSFX()->play();
	}
}

void GameManager::restartGame(void) {
	if (this->m_Level != nullptr)
		this->m_Level->getSFX()->stop();

	if (this->m_Menu != nullptr)
		this->m_Menu->reload();
	this->m_Menu = nullptr;

	this->m_GameState = GAMESTATE::PLAYING;

	if (this->m_EnemySpawner == nullptr) this->m_EnemySpawner = new EnemySpawner(this);
	else this->m_EnemySpawner->reload();

	if (this->m_Player == nullptr) this->m_Player = new Player(this);
	else this->m_Player->reset();

	if (this->m_KillCount == nullptr) this->m_KillCount = new KillCount(this);
	else this->m_KillCount->setScore(0);

	if (this->m_LootBox == nullptr) this->m_LootBox = new LootBox(this);
	else this->m_LootBox->reset();

	this->m_Level = (*this->m_Levels)[rand() % this->m_Levels->size()];
	this->m_Level->getSFX()->play();
}

void GameManager::exitGame(void) {
	this->m_ScoreBoard->saveScoreBoard();
	this->m_Window->close();
}

void GameManager::setElapsedTime(float _value) {
	if (_value <= 0.f) _value = 0.f;
	this->m_ElapsedTime = _value;
}

void GameManager::render() {
	while (this->m_Window->isOpen()) {

		if (this->getClock() != nullptr)
			this->setElapsedTime(this->getClock()->restart().asSeconds());

		this->eventManager();

		if (GetForegroundWindow() != this->m_WindowHandler &&
			this->getGameStatus() == GAMESTATE::PLAYING)
			this->setMenu("PAUSE");

		this->m_Window->clear(Color::Black);
		//
		if (this->getCurrentLevel() != nullptr)
			this->getCurrentLevel()->render();

		if (this->getMenu() != nullptr)
			this->getMenu()->render();

		if (this->getGameStatus() != GAMESTATE::PLAYING) {
			this->m_Window->display();
			continue;
		}

		if (this->m_LootBox != nullptr)
			this->m_LootBox->render();

		if (this->getEnemySpawner() != nullptr)
			this->getEnemySpawner()->update();

		if (this->getPlayer() != nullptr)
			this->getPlayer()->render();

		if (this->getKillCount() != nullptr)
			this->getKillCount()->render();
		//
		this->m_Window->display();
	}
}

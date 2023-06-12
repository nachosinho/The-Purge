#include "GameManager.h"

GameManager::GameManager(void) {
	this->m_Window = new RenderWindow(VideoMode(WINDOW_X, WINDOW_Y), GAME_TITLE);
	this->m_Event = new Event;
	this->m_Clock = new Clock;
	this->m_WindowHandler = this->m_Window->getSystemHandle();

	this->loadSettings();
	this->loadLevels();

	if (!DEBUGGING)
		this->setMenu(new MainMenu(this), GAMESTATE::MAINMENU);
	else this->restartGame();

	this->render();
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

void GameManager::loadLevels(void) {
	this->m_Levels = new vector<Level*> { new Bunkers(this), new Cemetery(this), new Park(this) };
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
				this->setMenu(new PauseMenu(this), GAMESTATE::PAUSED);
			break;
		}
}

void GameManager::setMenu(Menu* _menu, int _state) {
	this->m_GameState = _state;

	delete this->m_Menu;
	this->m_Menu = _menu;

	switch (this->m_GameState) {
	case GAMESTATE::MAINMENU:
	case GAMESTATE::OVER:
		this->m_Player = nullptr;
		this->m_KillCount = nullptr;
		this->m_Level = nullptr;
		break;
	}
}

void GameManager::restartGame(void) {
	delete this->m_Menu;
	this->m_Menu = nullptr;

	/*delete this->m_EnemySpawner;
	this->m_EnemySpawner = nullptr;

	delete this->m_Player;
	this->m_Player = nullptr;

	delete this->m_KillCount;
	this->m_KillCount = nullptr;

	delete this->m_Level;
	this->m_Level = nullptr;*/

	if (this->m_Level != nullptr)
		this->m_Level->getSFX()->stop();

	this->m_GameState = GAMESTATE::PLAYING;

	if (this->m_EnemySpawner == nullptr) this->m_EnemySpawner = new EnemySpawner(this);
	else this->m_EnemySpawner->reload();

	if (this->m_Player == nullptr) this->m_Player = new Player(this);
	else this->m_Player->reset();

	if (this->m_KillCount == nullptr) this->m_KillCount = new KillCount(this);
	else this->m_KillCount->setScore(0);

	this->m_Level = (*this->m_Levels)[rand() % this->m_Levels->size()];
	this->m_Level->getSFX()->play();
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
			this->setMenu(new PauseMenu(this), GAMESTATE::PAUSED);

		this->m_Window->clear(Color::Black);
		//
		if (this->getCurrentLevel() != nullptr)
			this->getCurrentLevel()->render();

		if (this->getMenu() != nullptr)
			this->getMenu()->render();

		if (this->getGameStatus() == GAMESTATE::PAUSED) {
			this->m_Window->display();
			continue;
		}

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

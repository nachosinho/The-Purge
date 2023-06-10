#include "GameManager.h"

GameManager::GameManager(void) {
	this->m_Window = new RenderWindow(VideoMode(WINDOW_X, WINDOW_Y), GAME_TITLE);
	this->m_Event = new Event;
	this->m_Clock = new Clock;
	this->m_WindowHandler = this->m_Window->getSystemHandle();

	if (!DEBUGGING) {
		//

		//
	} else this->restartGame();

	this->loadSettings();
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
				//this->setMenu(new PauseMenu(*this), GAMESTATE::PAUSED);
			break;
		}
}

void GameManager::restartGame(void) {
	//delete this->m_Menu;
	delete this->m_Player;
	this->m_Player = nullptr;
	//delete this->m_CurrentLevel;

	//this->m_Menu = nullptr;
	this->m_GameState = GAMESTATE::PLAYING;
	this->m_Player = new Player(this);
	//this->m_CurrentLevel = new TestLevel(this);
}

void GameManager::render() {
	while (this->m_Window->isOpen()) {

		this->eventManager();

		//if (GetForegroundWindow() != this->m_WindowHandler &&
			//this->getGameStatus() == GAMESTATE::PLAYING)
			//this->setMenu(new PauseMenu(*this), GAMESTATE::PAUSED);

		this->m_Window->clear(Color::White);
		//
		//if (this->m_CurrentLevel != nullptr) {
		//	this->m_CurrentLevel->render(this->m_Window);
		//	this->m_CurrentLevel->manageMusic();
		//}

		if (this->m_Player != nullptr) {
			this->m_Player->render();
		}

		//if (this->m_Menu != nullptr) {
		//	this->m_Menu->render(this->m_Window);
		//	this->m_Menu->handleInput(this->m_Window, this->m_Event);
		//}
		//
		this->m_Window->display();
	}
}
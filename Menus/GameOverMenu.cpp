#include "GameOverMenu.h"
#include "../Engine/Core/GameManager.h"

GameOverMenu::GameOverMenu(GameManager* _gameManager)
	: Menu("OVER", _gameManager), m_Timer(0)
{
	this->m_GameState = GameManager::GAMESTATE::OVER;
	this->m_GameManager = _gameManager;

	if (this->m_GameManager == nullptr)
		return;	

	this->m_ExitButton.setSize(Vector2f(200.f, 50.f));
	this->m_ExitButton.setPosition(WINDOW_X / 2 - this->m_ExitButton.getSize().x / 2, -this->m_ExitButton.getGlobalBounds().height);
	this->m_ExitButton.setFillColor(Color(255, 0, 0, 255));

	this->m_PlayButton.setSize(Vector2f(200.f, 50.f));
	this->m_PlayButton.setPosition(WINDOW_X / 2 - this->m_PlayButton.getSize().x / 2, this->m_ExitButton.getPosition().y - this->m_PlayButton.getGlobalBounds().height - 50.f);
	this->m_PlayButton.setFillColor(Color(0, 255, 0, 255));

	if (this->m_LogoTexture.loadFromFile("Assets/Textures/Interface/Logo.png"))
		this->m_LogoSprite.setTexture(this->m_LogoTexture);
	this->m_LogoSprite.setColor(Color(255, 255, 255, 255));
	this->m_LogoSprite.setPosition(WINDOW_X / 2 - this->m_LogoSprite.getGlobalBounds().width / 2, this->m_PlayButton.getPosition().y - this->m_LogoSprite.getGlobalBounds().height - 50.f);

	if (!this->m_Font.loadFromFile("Assets/Fonts/Sitka.ttc"))
		return;

	this->m_PlayText.setFont(this->m_Font);
	this->m_PlayText.setString("Start");
	this->m_PlayText.setFillColor(Color::Black);
	this->m_PlayText.setPosition(this->m_PlayButton.getPosition().x + this->m_PlayButton.getSize().x / 2 - this->m_PlayText.getGlobalBounds().width / 2,
		this->m_PlayButton.getPosition().y + this->m_PlayButton.getSize().y / 2 - this->m_PlayText.getGlobalBounds().height);

	this->m_ExitText.setFont(this->m_Font);
	this->m_ExitText.setString("Exit");
	this->m_ExitText.setFillColor(Color::Black);
	this->m_ExitText.setPosition(this->m_ExitButton.getPosition().x + this->m_ExitButton.getSize().x / 2 - this->m_ExitText.getGlobalBounds().width / 2,
		this->m_ExitButton.getPosition().y + this->m_ExitButton.getSize().y / 2 - this->m_ExitText.getGlobalBounds().height);

	this->m_ScoreBoardText.setFont(this->m_Font);
	this->m_ScoreBoardText.setString("Scoreboard");
	this->m_ScoreBoardText.setFillColor(Color(161, 0, 0));
	this->m_ScoreBoardText.setOutlineColor(Color::Black);
	this->m_ScoreBoardText.setOutlineThickness(1.f);
	this->m_ScoreBoardText.setPosition(5.f, 5.f);
}

void GameOverMenu::handleInput(void) {
	if (this->m_GameManager == nullptr)
		return;

	Event* _event = this->m_GameManager->getEvent();
	if (_event == nullptr)
		return;

	RenderWindow* _window = this->m_GameManager->getWindow();
	if (_window == nullptr)
		return;

	while (_window->pollEvent(*_event)) {
		switch (_event->type) {
		case Event::Closed:
			_window->close();
			break;

		case Event::MouseButtonPressed:
			if (_event->mouseButton.button == Mouse::Left) {

				if (this->m_Timer < 384)
					return;

				Vector2f mousePos = Vector2f(_event->mouseButton.x * 1.0f, _event->mouseButton.y * 1.0f);
				if (this->m_PlayButton.getGlobalBounds().contains(mousePos))
					this->m_GameManager->restartGame();

				else if (this->m_ExitButton.getGlobalBounds().contains(mousePos))
					this->m_GameManager->exitGame();
			} break;
		}
	}
}

void GameOverMenu::render(void) {
	if (this->m_GameManager == nullptr)
		return;

	this->update();
	this->m_GameManager->getWindow()->draw(this->m_LogoSprite);
	this->m_GameManager->getWindow()->draw(this->m_PlayButton);
	this->m_GameManager->getWindow()->draw(this->m_ExitButton);
	this->m_GameManager->getWindow()->draw(this->m_PlayText);
	this->m_GameManager->getWindow()->draw(this->m_ExitText);
	this->m_GameManager->getWindow()->draw(this->m_ScoreBoardText);

	int height = 0;
	for (Score _score : *this->m_GameManager->getScoreBoard()->getScore()) {
		Text scoreText;
		scoreText.setFont(this->m_Font);
		scoreText.setString(_score.m_Name + " : " + to_string(_score.m_Score));
		scoreText.setCharacterSize(24);
		scoreText.setFillColor(Color(250, 125, 0));
		scoreText.setOutlineColor(Color::Black);
		scoreText.setOutlineThickness(1.f);
		scoreText.setPosition(5.f, 5.f + 1.5f * scoreText.getGlobalBounds().height + (scoreText.getGlobalBounds().height + 5.f) * height);
		this->m_GameManager->getWindow()->draw(scoreText);
		height++;
	}

	this->handleInput();
}

void GameOverMenu::reload(void) {
	if (this->m_GameManager == nullptr)
		return;

	this->m_Timer = 0;

	if (this->m_SFX == nullptr)
		return;

	this->m_SFX->stop();
}

void GameOverMenu::update(void) {
	if (this->m_Timer >= 384)
		return;

	if (this->m_Timer <= 383) {
		this->m_ExitButton.setPosition(this->m_ExitButton.getPosition().x, -this->m_ExitButton.getGlobalBounds().height + this->m_Timer * 1.25f);
		this->m_PlayButton.setPosition(this->m_PlayButton.getPosition().x, this->m_ExitButton.getPosition().y - this->m_PlayButton.getGlobalBounds().height - 50.f);
		this->m_LogoSprite.setPosition(this->m_LogoSprite.getPosition().x, this->m_PlayButton.getPosition().y - this->m_LogoSprite.getGlobalBounds().height - 50.f);
		this->m_PlayText.setPosition(this->m_PlayButton.getPosition().x + this->m_PlayButton.getSize().x / 2 - this->m_PlayText.getGlobalBounds().width / 2,
			this->m_PlayButton.getPosition().y + this->m_PlayButton.getSize().y / 2 - this->m_PlayText.getGlobalBounds().height);
		this->m_ExitText.setPosition(this->m_ExitButton.getPosition().x + this->m_ExitButton.getSize().x / 2 - this->m_ExitText.getGlobalBounds().width / 2,
			this->m_ExitButton.getPosition().y + this->m_ExitButton.getSize().y / 2 - this->m_ExitText.getGlobalBounds().height);
	} this->m_Timer++;
}
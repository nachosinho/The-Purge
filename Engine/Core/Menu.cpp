#include "Menu.h"
#include "GameManager.h"

Menu::Menu(string _name, GameManager* _gameManager)
	: m_Name(_name), m_GameState(-1), m_SFX(nullptr)
{
	this->m_GameManager = _gameManager;
}
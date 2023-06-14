#pragma once
#include "../Engine/Menu.h"

class ScoreBoardMenu : public Menu {
private:
	Texture m_BackgroundTexture, m_LogoTexture;
	Sprite m_BackgroundSprite, m_LogoSprite;
	RectangleShape m_ReturnButton, m_ExitButton;
	Font m_TextFont;
	Text m_ReturnText, m_ExitText;

public:
	ScoreBoardMenu(class GameManager*);
	~ScoreBoardMenu(void) {}
	void handleInput(void);
	void update(void) {}
	void reload(void) {};
	void render(void);
};
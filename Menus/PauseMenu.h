#pragma once
#include "../Engine/Menu.h"

class PauseMenu : public Menu {
private:
	Texture m_BackgroundTexture, m_LogoTexture;
	Sprite m_BackgroundSprite, m_LogoSprite;
	RectangleShape m_ReturnButton, m_ExitButton;
	Font m_TextFont;
	Text m_ReturnText, m_ExitText;

public:
	PauseMenu(class GameManager*);
	~PauseMenu(void) {}
	void handleInput(void);
	void update(void) {}
	void render(void);
};
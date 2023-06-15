#pragma once
#include "../Engine/Core/Menu.h"

class MainMenu : public Menu {
private:
	Texture m_BackgroundTexture, m_LogoTexture;
	Sprite m_BackgroundSprite, m_LogoSprite;
	Font m_Font;
	Text m_PlayText, m_ExitText;
	RectangleShape m_PlayButton, m_ExitButton;
	int m_Timer;

public:
	MainMenu(class GameManager*);
	~MainMenu() {}
	void handleInput(void);
	void update(void);
	void reload(void);
	void render(void);
};
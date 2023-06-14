#pragma once
#include "../Engine/Menu.h"

class GameOverMenu : public Menu {
private:
	Texture m_LogoTexture;
	Sprite m_LogoSprite;
	Font m_Font;
	Text m_PlayText, m_ExitText;
	RectangleShape m_PlayButton, m_ExitButton;
	int m_Timer;

public:
	GameOverMenu(class GameManager*);
	~GameOverMenu() {}
	void handleInput(void);
	void update(void);
	void reload(void);
	void render(void);
};
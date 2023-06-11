#pragma once
#include "include.h"

class KillCount : public Sprite {
private:
	Texture* m_Texture;
	Font* m_Font;
	Text* m_Text;
	int m_Score;
	class GameManager* m_GameManager;

public:
	KillCount(class GameManager*);

	int getScore(void) { return this->m_Score; }

	void setScore(int);
	void updateText(void);

	void render(void);
};
#pragma once
#include "include.h"

class AmmoInfo : public Sprite {
private:
	RenderWindow* m_RenderWindow;
	Texture* m_AmmoTexture;
	Font* m_AmmoFont;
	Text* m_AmmoText;

	int m_Min, m_Max;
	
	class Rifle* m_Rifle;
public:
	AmmoInfo(class Rifle*, RenderWindow*);

	void updateText(void);

	void setMin(int);
	void setMax(int);

	void render(void);
};
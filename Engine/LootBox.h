#pragma once
#include "include.h"

struct LootBox_Bonus {
	LootBox_Bonus(string, Color);

	string m_Text;
	Color m_Color;
};

class LootBox : public Sprite {
private:
	enum BONUSTYPE { DAMAGE, AMMUNITION, BULLET_VELOCITY, RELOAD_TIME, HEALTH, MOVEMENT_VELOCITY, ENUMRANGE };
	vector<LootBox_Bonus> m_BonusDesc;

	Texture* m_Texture;
	Font* m_Font;
	Text* m_Text;
	float m_RefreshTime, m_NotificationTime;
	bool m_IsPlaced;
	int m_CurrentBonus;

	const float REFRESH_TIME = 10.f;

	class Player* m_Player;
	class GameManager* m_GameManager;
public:
	LootBox(class GameManager*);

	void checkCollision(void);
	void rollBonus(void);
	void assignBonus(void);

	void spawn(void);
	void reset(void);

	void render(void);
};
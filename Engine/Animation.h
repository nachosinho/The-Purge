#pragma once
#include "include.h"

class Animation {
private:
	Texture* m_Texture;
	int m_FramesCount,
		m_CurrentFrame;
	Vector2i m_FrameSize;
	const float m_SwitchTime = 0.3f;
	float m_TotalTime;
	string m_Name;
	class NPC* m_NPC;

public:
	Animation(class NPC*, string, Vector2i, int);

	string getName(void) { return this->m_Name; }
	int getCurrentFrame(void) { return this->m_CurrentFrame; }
	Texture* getTexture(void) { return this->m_Texture; }
	IntRect getFrame(void) {
		return { m_CurrentFrame % 8 * m_FrameSize.x, m_CurrentFrame / 8 * m_FrameSize.y,
								m_FrameSize.x, m_FrameSize.y };}

	void render(float);
};
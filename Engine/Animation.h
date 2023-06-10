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

public:
	Animation(string, Vector2i, int);

	Texture* getTexture(void) { return this->m_Texture; }
	IntRect getFrame(void) { return { m_CurrentFrame / 8 * m_FrameSize.x * m_CurrentFrame, m_CurrentFrame % 8 * m_FrameSize.y * m_CurrentFrame,
								m_FrameSize.x, m_FrameSize.y };}

	void render(void);
};
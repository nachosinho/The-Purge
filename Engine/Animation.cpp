#include "Animation.h"

Animation::Animation(string _filename, Vector2i _frameSize, int _frameCount)
	: m_FrameSize(_frameSize), m_CurrentFrame(0), m_FramesCount(_frameCount), m_TotalTime(0.f)
{
	this->m_Texture = new Texture;

	if (!this->m_Texture->loadFromFile(_filename))
		return;
}

void Animation::render(void) {
	m_TotalTime += 0.02f; // deltaTime;
	if (m_TotalTime >= m_SwitchTime) {
		m_CurrentFrame++;
		m_TotalTime = 0.f;
		if (m_CurrentFrame >= m_FramesCount)
			m_CurrentFrame = 0;
	}
}
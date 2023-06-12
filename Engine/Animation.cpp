#include "Animation.h"
#include "NPC.h"

Animation::Animation(NPC* _npc, string _name, string _filename, Vector2i _frameSize, int _frameCount)
	: m_Name(_name), m_FrameSize(_frameSize), m_CurrentFrame(0), m_FramesCount(_frameCount), m_TotalTime(0.f)
{
	this->m_NPC = _npc;
	this->m_Texture = new Texture;

	if (!this->m_Texture->loadFromFile(_filename))
		return;
}

void Animation::render(float _deltaTime) {
	if (this->m_NPC == nullptr)
		return;

	m_TotalTime += _deltaTime;

	if (m_TotalTime >= 0.05f) {
		m_CurrentFrame++;
		m_TotalTime = 0.f;
		if (m_CurrentFrame >= m_FramesCount)
			m_CurrentFrame = 0;
		this->m_NPC->setTextureRect(this->getFrameRect());
	}
}

void Animation::resetFrame(void) {
	this->m_CurrentFrame = 0;
}
#include "stdafx.h"
#include "AnimationSprite.h"
#include"Sprite.h"
#include"Texture.h"
AnimationSprite::AnimationSprite()
{

}


AnimationSprite::AnimationSprite(int frameSize, int frameDelay) : lastFrame(frameSize), currentFrame(0), frameDelay(frameDelay), autoNext(1)
{
	spriteList.reserve(frameSize);
}

AnimationSprite::~AnimationSprite()
{
	spriteList.clear();
}

void AnimationSprite::AddFrame(Sprite* sprite)
{
	sprite->SetParent(this);

	spriteList.push_back(sprite);

	if (GetTexture() == nullptr)
	{
		SetTexture(sprite->GetTexture());
		SetSize(sprite->GetSize());
	}
}

void AnimationSprite::SetCurrentFrane(int frame)
{
	this->currentFrame = frame;
}

void AnimationSprite::SetLastFrame(int frame)
{
	this->lastFrame = frame;
}

void AnimationSprite::SetDelay(int frame)
{
	this->frameDelay = frame;
}

void AnimationSprite::SetContinueFrame(int frame)
{
	this->continueFrame = frame;
}

void AnimationSprite::SetAutoNext(bool value)
{
	this->autoNext = value;
}

void AnimationSprite::FlipX()
{
	auto sprite = spriteList.at(0);

	scaleCenter = sprite->GetTexture()->GetCentor();
	
	scale.x *= -1.0f;
}

void AnimationSprite::NextFrame()
{
	currentFrame++;

	if (currentFrame > lastFrame)
		currentFrame = continueFrame;
}

void AnimationSprite::OnUpdate()
{
	if (frameDelay == 0 || !autoNext)
		return;

	if (GameTime::TotalFrame % frameDelay == 0)
		NextFrame();
}

void AnimationSprite::OnDraw()
{
	auto sprite = spriteList.at(currentFrame);

	sprite->Draw();
}
#pragma once

class AnimationSprite : public Sprite
{
private:

	std::vector<Sprite*> spriteList;

	int lastFrame;
	int currentFrame;

	int continueFrame;

	int frameDelay;
	bool autoNext;

public:
	AnimationSprite(int frameSize, int frameDelay);
	AnimationSprite();
	~AnimationSprite();

	//새 프레임 추가
	void AddFrame(Sprite* sprite);

	//현재 프레임이동 
	void SetCurrentFrane(int frame);

	//마지막 프레임 설정
	void SetLastFrame(int frame);

	//프레임 사이 간격시간 설정
	void SetDelay(int frame);

	//마지막 프레임에서 이어질 프레임 설정
	void SetContinueFrame(int frame);

	//업데이트할 때 자동으로 프레임이 넘어갈지 설정
	void SetAutoNext(bool value);

	void FlipX() override;

	void NextFrame();

	void OnUpdate();
	void OnDraw();

};


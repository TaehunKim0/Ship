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

	//�� ������ �߰�
	void AddFrame(Sprite* sprite);

	//���� �������̵� 
	void SetCurrentFrane(int frame);

	//������ ������ ����
	void SetLastFrame(int frame);

	//������ ���� ���ݽð� ����
	void SetDelay(int frame);

	//������ �����ӿ��� �̾��� ������ ����
	void SetContinueFrame(int frame);

	//������Ʈ�� �� �ڵ����� �������� �Ѿ�� ����
	void SetAutoNext(bool value);

	void FlipX() override;

	void NextFrame();

	void OnUpdate();
	void OnDraw();

};


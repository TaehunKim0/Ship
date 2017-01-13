#pragma once
class AnimationSprite;
class Intro_scene : public GameObject
{
private:
	AnimationSprite* Intro;

public:
	Intro_scene();
	~Intro_scene();

	void OnUpdate() override;
	void OnDraw() override;
};


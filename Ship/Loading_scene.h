#pragma once
class Loading_scene : public GameObject
{
private:
	Sprite* loadingBackground;
	Sprite* loadingTurtle;

public:
	Loading_scene();
	~Loading_scene();

	void OnUpdate();
	void OnDraw();
};
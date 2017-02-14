#pragma once
class Loading_scene : public Scene
{
private:
	Sprite* loadingBackground;
	Sprite* loadingTurtle;

	int load;
public:
	Loading_scene();
	~Loading_scene();

	void OnUpdate();
	void OnDraw();
};
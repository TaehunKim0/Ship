#pragma once
class Loading_scene : public GameObject
{
private:
	Sprite* loadingBackground;
	Sprite* loadingTurtle;

	int load;
public:
	Loading_scene(string load);
	~Loading_scene();

	void OnUpdate();
	void OnDraw();
};
#pragma once
class Sprite;
class Main_scene : public GameObject
{
private:
	AnimationSprite* selectMenu;
	Sprite* Main;

	int menuIndex;

public:
	Main_scene();
	~Main_scene();

	void OnUpdate() override;
	void OnDraw() override;
};
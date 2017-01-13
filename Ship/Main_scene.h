#pragma once

class AnimationSprite;
class Main_scene : public GameObject
{
private:
	AnimationSprite* selectMenu;

	int menuIndex;

public:
	Main_scene();
	~Main_scene();

	void OnUpdate() override;
	void OnDraw() override;

};


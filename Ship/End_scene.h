#pragma once
class AnimationSprite;
class End_scene : public Scene
{
private:
	AnimationSprite* end;


public:
	End_scene();
	~End_scene();

	void OnUpdate();
	void OnDraw();
};
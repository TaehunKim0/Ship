#pragma once
class HpBar : public GameObject
{
private:
	AnimationSprite* Hp;
	Sprite* Bar;


public:
	HpBar();
	~HpBar();

	void OnUpdate();
	void OnDraw();
};


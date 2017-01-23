#pragma once
class Item : public GameObject
{
private:
	Sprite* item;


public:
	Item(float x, float y);
	~Item();

	void OnUpdate();
	void OnDraw();

};


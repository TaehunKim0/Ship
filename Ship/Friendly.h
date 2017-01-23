#pragma once
#include"Unit.h"
class Bullet;
class Friendly : public Unit
{
private:
	Bullet* bullet;
	Sprite* friedly;
	
public:
	Friendly(string type);
	~Friendly();

	void Attack();
	void Move();

	void OnUpdate();
	void OnDraw();

	std::vector<Bullet*> bulletList;
};
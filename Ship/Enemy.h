#pragma once

#include"Unit.h"
class Bullet;
class Enemy  : public Unit
{
private:
	Bullet* bullet;

public:
	Enemy(string type);
	~Enemy();

	void Attack();
	void Move();

	void OnUpdate();
	void OnDraw();


	std::vector<Bullet*> bulletList;
};


#pragma once

#include"Unit.h"
class Bullet;
class Item;
class Enemy  : public Unit
{
private:
	Bullet* bullet;

	Item * item;


public:
	Enemy(string type);
	~Enemy();

	void Attack();
	void Move();

	void OnUpdate();
	void OnDraw();

	void DropItem();

	std::vector<Bullet*> bulletList;
};


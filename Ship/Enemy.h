#pragma once

#include"Unit.h"
class Enemy  : public Unit
{
private:


public:
	Enemy(string type);
	~Enemy();

	void Attack();
	void Move();

	void OnUpdate();
	void OnDraw();
};


#pragma once
#include"Unit.h"
class Friendly : public Unit
{
private:


	
public:
	Friendly(string type);
	~Friendly();

	void Attack();
	void Move();

	void OnUpdate();
	void OnDraw();
};
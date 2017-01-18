#pragma once

class Bullet;

class Enemy  : public Unit
{
private:


public:
	Enemy(string type);
	~Enemy();

	void Attack();
	void Move();

};


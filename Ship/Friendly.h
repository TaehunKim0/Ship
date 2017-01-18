#pragma once
class Bullet;
class Friendly : public Unit
{
private:


	
public:
	Friendly(string type);
	~Friendly();

	void Attack();
	void Move();
};


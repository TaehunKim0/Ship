#pragma once
class Unit : public GameObject
{
public:

	int life;
	int attack;
	float speed;

public:
	Unit();
	~Unit();

	virtual void Attack() = 0;
	virtual void Move() = 0;

};


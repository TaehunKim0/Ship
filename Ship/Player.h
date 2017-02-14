#pragma once

class Sprite;
class AnimationSprite;
class Bullet;

namespace PlayerState
{
	enum EnumType
	{
		stand =0,
		move = 1,
	};
}

namespace PlayerDirection
{
	enum EnumType
	{
		left = 1,
		right = 2,
		up=3,
		down =4
	};
}

class Player : public GameObject
{
private:
	AnimationSprite* right;
	AnimationSprite* left;

	int health;
	float speed;
	int attack;

public:
	Player();
	~Player();
	
	PlayerState::EnumType state;
	PlayerDirection::EnumType direction;

	//void FlipX(PlayerState::EnumType p);
	//�ڽ��� ����� �� ���� Get �Լ��� ����� ����.

	void OnUpdate();
	void OnDraw();
};


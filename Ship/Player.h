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
		notMove = 2
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
	Sprite* player;
	AnimationSprite* players;
	int health;
	float speed;
	int attack;

	

public:
	Player();
	~Player();
	Bullet* bullet;
	std::vector<Bullet*> bulletList;
	PlayerState::EnumType state;
	PlayerDirection::EnumType direction;

	//void FlipX(PlayerState::EnumType p);
	//자신의 재산을 쓸 때는 Get 함수를 만들어 쓰자.

	void OnUpdate();
	void OnDraw();
};


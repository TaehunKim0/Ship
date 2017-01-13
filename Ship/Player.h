#pragma once

class Sprite;
class AnimationSprite;

namespace PlayerState
{
	enum EnumType
	{

	};
}

class Player : public GameObject
{
private:
	
	int health;
	int speed;
	int attack;

	PlayerState::EnumType p_State;

public:
	Player();
	~Player();

	//자신의 재산을 쓸 때는 Get 함수를 만들어 쓴다.

	void OnUpdate();
	void OnDraw();
};


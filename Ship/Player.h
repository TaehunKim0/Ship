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

	//�ڽ��� ����� �� ���� Get �Լ��� ����� ����.

	void OnUpdate();
	void OnDraw();
};


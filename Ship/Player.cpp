#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"
#include"Sprite.h"
#include"Texture.h"

Player::Player() : speed(2.0f), health(5) , attack(1)
{

	right = new AnimationSprite(1, 10);
	right->parentObject = this;

	right->AddFrame(Sprite::Create("Resources/Player/Player_right1.png"));
	right->AddFrame(Sprite::Create("Resources/Player/Player_right2.png"));

	left = new AnimationSprite(1, 10);
	left->parentObject = this;

	left->AddFrame(Sprite::Create("Resources/Player/Player_left1.png"));
	left->AddFrame(Sprite::Create("Resources/Player/Player_left2.png"));

	SetState(PlayerState::stand);
	SetDirection(PlayerDirection::right);

	SetPosition(500, 100);
}

Player::~Player()
{
	
}

void Player::OnUpdate()
{
	if (InputMgr::GetInstance()->IsKeyDown(VK_LEFT))
	{
		position.x -= speed;

		SetState(PlayerState::move);
		SetDirection(PlayerDirection::left);

		//SceneMgr::GetInstance()->GetScene()->position.x -= 5;
	}

	else if (InputMgr::GetInstance()->IsKeyDown(VK_RIGHT))
	{
		position.x += speed;

		SetState(PlayerState::move);
		SetDirection(PlayerDirection::right);

		//SceneMgr::GetInstance()->GetScene()->position.x += 5;
	}


	if (InputMgr::GetInstance()->IsKeyDown(VK_UP))
	{
		position.y -= speed;

		SetState(PlayerState::move);
		SetDirection(PlayerDirection::up);
	}
	else if (InputMgr::GetInstance()->IsKeyDown(VK_DOWN))
	{
		position.y += speed;

		SetState(PlayerState::move);
		SetDirection(PlayerDirection::down);
	}


	
	//ÃÑ¾Ë °ø°Ý
	if (InputMgr::GetInstance()->IsKeyDown(VK_SPACE) & GameTime::CurrentFrame % 10 == 0)
	{
		auto bullet = new Bullet("Player");
		bullet->SetPosition(GetPosition() + (right->GetSize() / 2) - (bullet->bullet->GetSize() / 2));
		
		if (direction == PlayerDirection::left)
			bullet->direction = bulletDirection::left;

		else if (direction == PlayerDirection::right)
			bullet->direction = bulletDirection::right;

		else
			printf("Bullet ELSE \n");

		BulletMgr::GetInstance()->RegisterBullet(bullet);
	}

	if (state == PlayerState::move)
	{ 
		switch (direction)
		{

		case PlayerDirection::right:
			right->Update();
			break;

		case PlayerDirection::left:
			left->Update();
			break;
		}
	
	}

}

void Player::OnDraw()
{
	if (state == PlayerState::move)
	{
		switch (direction)
		{

		case PlayerDirection::right:
			right->Draw();
			break;

		case PlayerDirection::left:
			left->Draw();
			break;
		}

	}
}

void Player::SetState(PlayerState::EnumType state)
{
	this->state = state;
}

void Player::SetDirection(PlayerDirection::EnumType direction)
{
	this->direction = direction;
}

PlayerState::EnumType Player::GetState()
{
	return state;
}

PlayerDirection::EnumType Player::GetDirection()
{
	return direction;
}

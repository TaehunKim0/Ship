#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"
#include"Sprite.h"
#include"Texture.h"

Player::Player() : speed(2.0f), health(5) , attack(1)
{

	right = new AnimationSprite(0, 10);
	right->parentObject = this;

	right->AddFrame(Sprite::Create("Resources/Player/Player_right1.png"));

	left = new AnimationSprite(0, 10);
	left->parentObject = this;

	left->AddFrame(Sprite::Create("Resources/Player/Player_left1.png"));
	

	state = PlayerState::stand;

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
		direction = PlayerDirection::left;
		state = PlayerState::move;

		//SceneMgr::GetInstance()->GetScene()->position.x -= 5;
	}

	else if(InputMgr::GetInstance()->IsKeyDown(VK_RIGHT))
	{
		position.x += speed;
		direction = PlayerDirection::right;
		state = PlayerState::move;

		//SceneMgr::GetInstance()->GetScene()->position.x += 5;
	}
		

	if (InputMgr::GetInstance()->IsKeyDown(VK_UP))
	{
		position.y -= speed;
		direction = PlayerDirection::up;
		state = PlayerState::move;
	}
	else if (InputMgr::GetInstance()->IsKeyDown(VK_DOWN))
	{
		position.y += speed;
		direction = PlayerDirection::down;
		state = PlayerState::move;
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

void Player::OnDraw()
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

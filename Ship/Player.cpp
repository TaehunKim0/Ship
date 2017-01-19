#include "stdafx.h"
#include "Player.h"
#include"Bullet.h"
#include"Sprite.h"
#include"Texture.h"

Player::Player() : speed(5.0f), health(5)
{

	player = Sprite::Create("Resources/turtle.png");
	player->parentObject = this;

	state = PlayerState::stand;
	bullet = new Bullet();

}

Player::~Player()
{

}

void Player::OnUpdate()
{
	
	//플레이어가 move
	if (state == PlayerState::move)
	{
		if (InputMgr::GetInstance()->IsKeyDown(VK_RIGHT)) //우
		{
			this->position.x += speed;
			direction = PlayerDirection::right;
		}

		if (InputMgr::GetInstance()->IsKeyDown(VK_LEFT)) //좌
		{
			this->position.x -= speed;
			direction = PlayerDirection::left;
		}

		if (InputMgr::GetInstance()->IsKeyDown(VK_UP)) //상
		{
			this->position.y -= speed;
			direction = PlayerDirection::up;
		}

		if (InputMgr::GetInstance()->IsKeyDown(VK_DOWN)) //하
		{
			this->position.y += speed;
			direction = PlayerDirection::down;
		}
	}

	//플레이어가 stand
	if (state == PlayerState::middleStand)
	{
		if (InputMgr::GetInstance()->IsKeyDown(VK_RIGHT)) //우
		{
			direction = PlayerDirection::right;
			printf("우 \n");
		}

		else if (InputMgr::GetInstance()->IsKeyDown(VK_LEFT)) //좌
		{
			direction = PlayerDirection::left;
			printf("좌 \n");
		}

		if (InputMgr::GetInstance()->IsKeyDown(VK_UP)) //상
		{
			this->position.y -= speed;
			direction = PlayerDirection::up;
			printf("상 \n");
		}

		else if (InputMgr::GetInstance()->IsKeyDown(VK_DOWN)) //하
		{
			this->position.y += speed;
			direction = PlayerDirection::down;
			printf("하 \n");
		}
	}



	//맵 밖으로 못나감
	if (this->GetPositionX() <= 0)
		this->position.x = 0;

	if (this->GetPositionX() > 1100)
		this->position.x = 1100;

	if (this->GetPositionY() < 0)
		this->position.y = 0;

	if (this->GetPositionY() > 620)
		this->position.y = 620;


	//총알 공격
	if (InputMgr::GetInstance()->IsKeyDown(VK_SPACE) & GameTime::CurrentFrame % 10 == 0)
	{
		auto bullet = new Bullet();
		bullet->SetPosition(GetPosition() + (player->GetSize() / 2) - (bullet->bullet->GetSize() / 2));
		
		if (direction == PlayerDirection::left)
			bullet->direction = bulletDirection::left;

		else if (direction == PlayerDirection::right)
			bullet->direction = bulletDirection::right;

		else
			printf("Bullet ELSE \n");

		bulletList.push_back(bullet);
	}

	for (auto bullet : bulletList)
	{
		bullet->Update();
	}

}

void Player::OnDraw()
{
	for (auto bullet : bulletList)
	{
		bullet->Draw();
	}
	player->Draw();
}

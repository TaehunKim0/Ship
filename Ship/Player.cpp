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
	
	//�÷��̾ move
	if (state == PlayerState::move)
	{
		if (InputMgr::GetInstance()->IsKeyDown(VK_RIGHT)) //��
		{
			this->position.x += speed;
			direction = PlayerDirection::right;
		}

		if (InputMgr::GetInstance()->IsKeyDown(VK_LEFT)) //��
		{
			this->position.x -= speed;
			direction = PlayerDirection::left;
		}

		if (InputMgr::GetInstance()->IsKeyDown(VK_UP)) //��
		{
			this->position.y -= speed;
			direction = PlayerDirection::up;
		}

		if (InputMgr::GetInstance()->IsKeyDown(VK_DOWN)) //��
		{
			this->position.y += speed;
			direction = PlayerDirection::down;
		}
	}

	//�÷��̾ stand
	if (state == PlayerState::middleStand)
	{
		if (InputMgr::GetInstance()->IsKeyDown(VK_RIGHT)) //��
		{
			direction = PlayerDirection::right;
			printf("�� \n");
		}

		else if (InputMgr::GetInstance()->IsKeyDown(VK_LEFT)) //��
		{
			direction = PlayerDirection::left;
			printf("�� \n");
		}

		if (InputMgr::GetInstance()->IsKeyDown(VK_UP)) //��
		{
			this->position.y -= speed;
			direction = PlayerDirection::up;
			printf("�� \n");
		}

		else if (InputMgr::GetInstance()->IsKeyDown(VK_DOWN)) //��
		{
			this->position.y += speed;
			direction = PlayerDirection::down;
			printf("�� \n");
		}
	}



	//�� ������ ������
	if (this->GetPositionX() <= 0)
		this->position.x = 0;

	if (this->GetPositionX() > 1100)
		this->position.x = 1100;

	if (this->GetPositionY() < 0)
		this->position.y = 0;

	if (this->GetPositionY() > 620)
		this->position.y = 620;


	//�Ѿ� ����
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

#include "stdafx.h"
#include "Player.h"

#include"Bullet.h"
#include"Sprite.h"
#include"Texture.h"
#include"HpBar.h"

Player::Player() : speed(2.5f), health(4) , attack(1)
{
	m_hp = new HpBar();

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
	
	AddChild(m_hp);
	m_hp->parentObject = m_hp;

}

Player::~Player()
{
	
}

void Player::OnUpdate()
{
	bool checkInput = false;

	if (InputMgr::GetInstance()->IsKeyDown(VK_LEFT))
	{
		position.x -= speed;
		checkInput = true;

		SetState(PlayerState::move);
		SetDirection(PlayerDirection::left);

		//SceneMgr::GetInstance()->GetScene()->position.x -= 5;
	}

	else if (InputMgr::GetInstance()->IsKeyDown(VK_RIGHT))
	{
		position.x += speed;
		checkInput = true;

		SetState(PlayerState::move);
		SetDirection(PlayerDirection::right);

		//SceneMgr::GetInstance()->GetScene()->position.x += 5;
	}

	if (InputMgr::GetInstance()->IsKeyDown(VK_UP))
	{
		position.y -= speed;
		checkInput = true;

		SetState(PlayerState::move);
		
	}
	else if (InputMgr::GetInstance()->IsKeyDown(VK_DOWN))
	{
		position.y += speed;
		checkInput = true;

		SetState(PlayerState::move);
		
	}

	if (!checkInput)
	{
		// 아무것도 입력안됨
		SetState(PlayerState::stand);
	}
	
	//총알 공격
	if (InputMgr::GetInstance()->IsKeyDown(VK_SPACE) & GameTime::CurrentFrame % 10 == 0)
	{
		auto bullet = new Bullet("Player");
		bullet->SetPosition(this->GetPosition() + (right->GetSize() / 2) - (bullet->bullet->GetSize() / 2));
		
		if (direction == PlayerDirection::left)
			bullet->direction = bulletDirection::left;

		else if (direction == PlayerDirection::right)
			bullet->direction = bulletDirection::right;

		else
			printf("Bullet ELSE \n");

		BulletMgr::GetInstance()->RegisterBullet(bullet);
		//m_hp->Damaged();
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

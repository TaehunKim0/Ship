#include "stdafx.h"
#include "land_stage.h"
#include"Sprite.h"
#include"Player.h"
#include"Background.h"
#include"Loading_scene.h"

land_stage::land_stage()
{
	player = PlayerMgr::GetInstance()->GetPlayer();
	background = new Background("land");

	this->AddChild(background);
	this->AddChild(player);

	//���� �ð� �ʱ�ȭ
}

land_stage::~land_stage()
{
}

void land_stage::OnUpdate()
{
	//���� + ��ư�� ������ ���, Friendly ��ȯ


	//���ھ 600, 1�� �ϼ�


	//���ھ� 1200, 2�� �ϼ�


	//���ھ� 1800, 3�� �ϼ�


	//���ھ� 2000, �źϼ� ���� �Ϸ�
		//�ε� �� �� sea_stage
}

void land_stage::OnDraw()
{
}

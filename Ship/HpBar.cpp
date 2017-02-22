#include "stdafx.h"
#include "HpBar.h"


HpBar::HpBar()
{
	Bar = Sprite::Create("Resources/UI/Bar.png");

	Hp = new AnimationSprite(3, 2);
	Hp->AddFrame(Sprite::Create("Resources/UI/hp1.png"));
	Hp->AddFrame(Sprite::Create("Resources/UI/hp2.png"));
	Hp->AddFrame(Sprite::Create("Resources/UI/hp3.png"));
	Hp->AddFrame(Sprite::Create("Resources/UI/hp4.png"));

	Hp->parentObject = this;
	Hp->SetAutoNext(false);
	AddChild(Bar);
	AddChild(Hp);

	Bar->SetPosition(50, 30);
	Hp->SetPosition(100, 70);

}


HpBar::~HpBar()
{
}

void HpBar::OnUpdate()
{
}

void HpBar::OnDraw()
{
}

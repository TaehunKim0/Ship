#include "stdafx.h"
#include "ScoreMsg.h"


ScoreMsg::ScoreMsg(string stage)
{
	if (stage == "land")
	{
		start = Sprite::Create("Resources/start.png");
		first = Sprite::Create("Resources/first.png");
		second = Sprite::Create("Resources/second.png");
		third = Sprite::Create("Resources/third.png");
		end = Sprite::Create("Resources/end.png");
	}

	if (stage == "sea")
	{

	}
	
	ScoreMsgList.push_back(start);
	ScoreMsgList.push_back(first);
	ScoreMsgList.push_back(second);
	ScoreMsgList.push_back(third);
	ScoreMsgList.push_back(end);


	for (auto a : ScoreMsgList)
		a->position.y = a->GetSize().y * -1;
	
}


ScoreMsg::~ScoreMsg()
{
	SAFE_DELETE(start);
	SAFE_DELETE(first);
	SAFE_DELETE(second);
	SAFE_DELETE(third);
	SAFE_DELETE(end);
}

void ScoreMsg::OnUpdate()
{

	//게임 시작
	start->On = true;



	//엄청 느릴것 같은데
	for (auto a : ScoreMsgList)
	{
		if (a->On == true)
			a->position.y++;

		if (a->position.y == 240)
			a->position.y--;

		if (a->position.y == -250)
			a->On = false;
	}

}

void ScoreMsg::OnDraw()
{
	for (auto a : ScoreMsgList)
	{
		if (a->On == true)
			a->Draw();

	}

}

#pragma once
class ScoreMsg : public GameObject
{
private:

	Sprite * start;

	Sprite* first;
	Sprite* second;
	Sprite* third;

	Sprite* end;

	std::vector<Sprite*> ScoreMsgList;


public:
	ScoreMsg(string stage);
	~ScoreMsg();


	void OnUpdate();
	void OnDraw();

};
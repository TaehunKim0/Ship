#pragma once

namespace PlusState
{
	enum Enum
	{
		Hover,
		Press,
		Not
	};
}

class AddFriendly_Plus : public GameObject
{
private:
	Sprite* plus;

	bool IsPlused;

	PlusState::Enum plusState;
public:
	AddFriendly_Plus();
	~AddFriendly_Plus();

	void OnDraw();
	void OnUpdate();

	void SetIsPlused(bool plused);

	void SetPlusState(PlusState::Enum state);
	PlusState::Enum GetPlusState();
};


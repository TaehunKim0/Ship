#pragma once

namespace AddActivation
{
	enum Enum
	{
		Can,
		Cannot
	};
}

namespace UIState
{
	enum Enum
	{
		Hover,
		Press,
		Not
	};
}
class AddFriendly_Plus;
class AddFriendly : public GameObject
{
private:
	Sprite* CanPlus;
	Sprite* CannotPlus;
	AddFriendly_Plus* plus[4];

	AddActivation::Enum addActivation;
	UIState::Enum uiState;
	int p;
public:
	AddFriendly();
	~AddFriendly();

	void OnUpdate();
	void OnDraw();

public:
	void SetActivation(AddActivation::Enum activation);
	AddActivation::Enum GetActivation();

public:
	void SetUIState(UIState::Enum state);
	UIState::Enum GetUIState();

	void CheckState();
};


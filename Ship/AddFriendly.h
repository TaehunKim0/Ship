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
	AddFriendly_Plus* plus[3];

	AddActivation::Enum addActivation;
	UIState::Enum uiState;

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


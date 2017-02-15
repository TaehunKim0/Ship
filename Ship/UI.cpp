#include "stdafx.h"
#include "UI.h"

#include"AddFriendly.h"

UI::UI()
{
	addFriendly = new AddFriendly();

	AddChild(addFriendly);

}


UI::~UI()
{

}

void UI::OnUpdate()
{

}

void UI::OnDraw()
{

}

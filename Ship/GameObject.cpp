#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
	D3DXMatrixIdentity(&matrix); //���� ����� �����Ѵ�.

	position = { 0,0 };
	scale = { 1.0f, 1.0f };
	scaleCenter = { 0,0 };

	rotation = 0.0f;
	rotationCenter = { 0,0 };

	childrenObjects.reserve(16);

	visible = true;
}

GameObject::~GameObject()
{
	ClearChildren();
}

void GameObject::OnUpdate()
{
}

void GameObject::OnDraw()
{
}

void GameObject::Update()
{
	if (!visible)
		return;

	for (auto childObject : childrenObjects)
	{
		childObject->Update();
	}
	OnUpdate();
}

void GameObject::Draw()
{
	if (!visible)
		return;

	//2d ��ȯ ��� ����
	D3DXMatrixTransformation2D(&matrix, &scaleCenter, 0.0f, &scale, &rotationCenter, rotation, &position);
	//���� ��� ���, �������߽���, Ȯ�� ȸ����� ����, Ȯ���� ����, ȸ�� �߽���, ȸ�� ����, �����̵�)

	if (parentObject != NULL)
		matrix *= parentObject->matrix;

	for (auto childObject : childrenObjects)
	{
		childObject->Draw();
	}

	OnDraw();
}



D3DXVECTOR2 GameObject::GetPosition() const
{
	return this->position;
}

void GameObject::SetPosition(int x, int y)
{
	this->position.x = x;
	this->position.y = y;
}

void GameObject::SetPosition(D3DXVECTOR2 position)
{
	this->position = position;
}

void GameObject::AddChild(GameObject * object)
{
	object->parentObject = this;
	childrenObjects.push_back(object);
}

void GameObject::RemoveChild(GameObject * object)
{
	childrenObjects.erase(std::remove(childrenObjects.begin(), childrenObjects.end(), object));

	SAFE_DELETE(object);
}

void GameObject::ClearChildren()
{
	for (auto childObject : childrenObjects)
		SAFE_DELETE(childObject);

	childrenObjects.clear();


}

void GameObject::SetVisible(bool visible)
{
	this->visible = visible;
}

int GameObject::GetPositionX() const
{
	return this->position.x;
}

int GameObject::GetPositionY() const
{
	return this->position.y;
}

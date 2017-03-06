#pragma once
class CircleCollider;
class GameObject
{
protected:


public:
	D3DXMATRIX matrix; 

	D3DXVECTOR2 position;

	D3DXVECTOR2 center;
	D3DXVECTOR2 size;

	D3DXVECTOR2 scale;
	D3DXVECTOR2 scaleCenter;

	float rotation;
	D3DXVECTOR2 rotationCenter;

	GameObject* parentObject;
	std::vector<GameObject*> childrenObjects;

	bool visible;
public:

	void AddChild(GameObject* object);
	void RemoveChild(GameObject* object);
	void ClearChildren();

public:
	GameObject();
	~GameObject();

	virtual void OnUpdate();
	virtual void OnDraw();

	virtual void Update();
	virtual void Draw();

public:
	GameObject* GetParent() { return parentObject; }
	void SetParent(GameObject* obj) { parentObject = obj; }

public:
	D3DXVECTOR2 GetPosition() const;
	void SetPosition(int x, int y);
	void SetPosition(D3DXVECTOR2 position);

public:
	void SetCenter(D3DXVECTOR2 center) { this->center = center; };
	D3DXVECTOR2 GetCenter() { return scaleCenter; };

	D3DXVECTOR2 GetSize() { return size; };
	void SetSize(D3DXVECTOR2 size);

public:
	D3DXVECTOR2 GetScale() { return scale; };
	void SetScale(D3DXVECTOR2 scale) { this->scale = scale; };

public:
	bool GetVisisble() { return visible; }
	void SetVisible(bool visible);

	bool IsCollideWith(CircleCollider* other);
	
	void Translate(float x, float y);
};
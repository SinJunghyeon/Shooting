#pragma once

#include "Config.h"
#include "KeyManager.h"

class Image;

class GameObject
{
private:

protected:
	int elapsedCount;
	int frameX, frameY;

	enum class MoveDir { Left, Right, Up, Down };

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	GameObject();
	~GameObject();

};


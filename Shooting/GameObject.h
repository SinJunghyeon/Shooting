#pragma once

#include "Config.h"
#include "KeyManager.h"

class Image;

class GameObject
{
private:

protected:
	enum class MoveDir { Left, Right, Up, Down };
	enum class State { Idle, Move, Attack, Damaged };

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	GameObject();
	~GameObject();

};


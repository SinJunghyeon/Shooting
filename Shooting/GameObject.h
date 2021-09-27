#pragma once

#include "Config.h"

class GameObject
{
private:

protected:
	POINTFLOAT pos;
	RECT shape;
	int bodySize;
	float moveSpeed;
	enum class MoveDir { Left, Right, Up, Down };
	enum class State { Idle, Move, Attack, Damaged };

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	inline void SetPos(POINTFLOAT pos) { this->pos = pos; }
	inline POINTFLOAT GetPos() { return this->pos; }
	inline void SetMoveSpeed(float speed) { this->moveSpeed = speed; }

	GameObject();
	~GameObject();
};


#pragma once

#include "Config.h"
#include "GameObject.h"

class Image;

class ZombieLupin : public GameObject
{
private:
	Image* idle;
	Image* leftMove;
	Image* rightMove;
	Image* attack;
	Image* damaged;

	int frameX, frameY;
	int elapsedCount;

	MoveDir moveDir;
	State state;

protected:
	bool isAttack;
	bool isAlive;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	inline void SetIsAttack(bool isAttack) { this->isAttack = isAttack; }

	ZombieLupin();
	~ZombieLupin();
};


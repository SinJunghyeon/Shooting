#pragma once

#include "Config.h"
#include "Monster.h"

class Banana;

class ZombieLupin : public Monster
{
private:
	POINTFLOAT monsterPos;
	RECT monsterShape;
	int monsterBodySize;
	float monsterMoveSpeed;

protected:
	Banana* banana;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	ZombieLupin();
	~ZombieLupin();
};


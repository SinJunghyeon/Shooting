#pragma once

#include "Config.h"
#include "Monster.h"

class Banana;

class ZombieLupin : public Monster
{
private:
	Image* idle;				//오른쪽에서 대기
	Image* mirroringIdle;		//왼쪽에서 대기
	Image* rightMove;			//오른쪽으로 이동
	Image* leftMove;			//왼쪽으로 이동
	Image* attack;				//오른쪽으로 공격
	Image* mirroringAttack;		//왼쪽으로 공격
	Image* damaged;				//오른쪽에서 피격
	Image* mirroringDamaged;	//왼쪽에서 피격

	MoveDir moveDir;			//방향
	MonsterState state;			//상태

protected:
	Banana* banana;				//무기

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void InputKey();

	ZombieLupin();
	~ZombieLupin();
};


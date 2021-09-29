#pragma once

#include "Config.h"
#include "Weapon.h"

class Banana : public Weapon
{
private:
	POINTFLOAT weaponPos;	//위치
	RECT weaponShape;		//모양
	int weaponBodySize;		//크기
	float weaponMoveSpeed;	//이동속도

	Image* move;			//오른쪽으로 이동
	Image* mirroringMove;	//왼쪽으로 이동
	Image* hit;				//오른쪽에서 타격
	Image* mirroringHit;	//왼쪽에서 타격

protected:

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	Banana();
	~Banana();
};


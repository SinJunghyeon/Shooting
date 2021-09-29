#pragma once

#include "Config.h"
#include "Weapon.h"

class Banana : public Weapon
{
private:
	POINTFLOAT weaponPos;	//��ġ
	RECT weaponShape;		//���
	int weaponBodySize;		//ũ��
	float weaponMoveSpeed;	//�̵��ӵ�

	Image* move;			//���������� �̵�
	Image* mirroringMove;	//�������� �̵�
	Image* hit;				//�����ʿ��� Ÿ��
	Image* mirroringHit;	//���ʿ��� Ÿ��

protected:

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	Banana();
	~Banana();
};


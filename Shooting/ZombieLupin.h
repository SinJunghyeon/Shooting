#pragma once

#include "Config.h"
#include "Monster.h"

class Banana;

class ZombieLupin : public Monster
{
private:
	POINTFLOAT monsterPos;		//��ġ
	RECT monsterShape;			//���
	int monsterBodySize;		//ũ��
	float monsterMoveSpeed;		//�̵��ӵ�

	Image* idle;				//�����ʿ��� ���
	Image* mirroringIdle;		//���ʿ��� ���
	Image* rightMove;			//���������� �̵�
	Image* leftMove;			//�������� �̵�
	Image* attack;				//���������� ����
	Image* mirroringAttack;		//�������� ����
	Image* damaged;				//�����ʿ��� �ǰ�
	Image* mirroringDamaged;	//���ʿ��� �ǰ�

	MoveDir moveDir;			//����
	MonsterState state;			//����

	bool isShoot;				//�߻��ߴ���?

protected:
	Banana* banana;				//����

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void InputKey();

	ZombieLupin();
	~ZombieLupin();
};


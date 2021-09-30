#pragma once

#include "Config.h"
#include "GameObject.h"

class Monster : public GameObject
{
private:

protected:
	POINTFLOAT monsterPos;		//��ġ
	RECT monsterShape;			//���
	int monsterBodySize;		//ũ��
	float monsterMoveSpeed;		//�̵��ӵ�

	bool isShoot;				//�߻��ߴ���?

	enum class MonsterState { Idle, Move, Attack, Damaged, End };

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void ChangeSceneX(int maxElapsedCount, int maxFrameX);	//������X�� �ٲ� ��
	void ChangeSceneY(int maxElapsedCount, int maxFrameY);	//������Y�� �ٲ� ��

	inline void SetPos(POINTFLOAT pos) { this->monsterPos = pos; }
	inline POINTFLOAT GetPos() { return this->monsterPos; }

	inline void SetMoveSpeed(float speed) { this->monsterMoveSpeed = speed; }
	inline float GetMoveSpeed() { return this->monsterMoveSpeed; }

	inline void SetIsShoot(bool isShoot) { this->isShoot = isShoot; }
	inline bool GetIsShoot() { this->isShoot; }

	Monster();
	~Monster();

};


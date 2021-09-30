#pragma once

#include "Config.h"
#include "GameObject.h"

class Monster : public GameObject
{
private:

protected:
	POINTFLOAT monsterPos;		//위치
	RECT monsterShape;			//모양
	int monsterBodySize;		//크기
	float monsterMoveSpeed;		//이동속도

	bool isShoot;				//발사했는지?

	enum class MonsterState { Idle, Move, Attack, Damaged, End };

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void ChangeSceneX(int maxElapsedCount, int maxFrameX);	//프레임X가 바뀔 때
	void ChangeSceneY(int maxElapsedCount, int maxFrameY);	//프레임Y가 바뀔 때

	inline void SetPos(POINTFLOAT pos) { this->monsterPos = pos; }
	inline POINTFLOAT GetPos() { return this->monsterPos; }

	inline void SetMoveSpeed(float speed) { this->monsterMoveSpeed = speed; }
	inline float GetMoveSpeed() { return this->monsterMoveSpeed; }

	inline void SetIsShoot(bool isShoot) { this->isShoot = isShoot; }
	inline bool GetIsShoot() { this->isShoot; }

	Monster();
	~Monster();

};


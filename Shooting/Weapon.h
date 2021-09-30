#pragma once

#include "Config.h"
#include "GameObject.h"

class Weapon : public GameObject
{
private:

protected:
	POINTFLOAT weaponPos;	//��ġ
	RECT weaponShape;		//���
	int weaponBodySize;		//ũ��
	float weaponMoveSpeed;	//�̵��ӵ�

	bool isExistence;		//�����ϴ���?
	bool isFire;			//�߻��ߴ���?
	int weaponDelay;		//�߻�����

	enum class WeaponState { Move, Hit };

public:
	void Init();	
	void Update();
	void Render(HDC hdc);
	void Release();

	inline void SetPos(POINTFLOAT pos) { this->weaponPos = pos; }
	inline POINTFLOAT GetPos() { return this->weaponPos; }

	inline void SetBodySize(int weaponBodySize) { this->weaponBodySize = weaponBodySize; }
	inline int GetBodySize() { return this->weaponBodySize; }

	inline void SetMoveSpeed(float speed) { this->weaponMoveSpeed = speed; }
	inline float GetMoveSpeed() { return this->weaponMoveSpeed; }

	inline void SetIsExistence(bool isExistence) { this->isExistence = isExistence; }
	inline bool GetIsExistence() { return this->isExistence; }

	inline void SetIsFire(bool isFire) { this->isFire = isFire; }
	inline bool GetIsFire() { return this->isFire; }

	Weapon();
	~Weapon();
};


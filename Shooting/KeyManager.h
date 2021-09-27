#pragma once

#include "Config.h"
#include <bitset>
#include "Singleton.h"

class KeyManager : public Singleton<KeyManager>
{
private:
	// 키가 안 눌린 상태인지 아닌지
	bitset<KEY_MAX_COUNT>	keyUp;
	// 키가 눌린 상태인지 아닌지
	bitset<KEY_MAX_COUNT>	keyDown;

public:
	void Init();

	// 키가 첫번째로 눌렸는지 판단
	bool IsOnceKeyDown(int key);
	bool IsOnceKeyDown(char key);
	// 키가 첫번째로 눌렸다가 떨어졌는지 판단
	bool IsOnceKeyUp(int key);
	bool IsOnceKeyUp(char key);
	// 키가 눌려져 있는지 판단
	bool IsStayKeyDown(int key);
	bool IsStayKeyDown(char key);
};


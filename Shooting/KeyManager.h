#pragma once

#include "Config.h"
#include <bitset>
#include "Singleton.h"

class KeyManager : public Singleton<KeyManager>
{
private:
	// Ű�� �� ���� �������� �ƴ���
	bitset<KEY_MAX_COUNT>	keyUp;
	// Ű�� ���� �������� �ƴ���
	bitset<KEY_MAX_COUNT>	keyDown;

public:
	void Init();

	// Ű�� ù��°�� ���ȴ��� �Ǵ�
	bool IsOnceKeyDown(int key);
	bool IsOnceKeyDown(char key);
	// Ű�� ù��°�� ���ȴٰ� ���������� �Ǵ�
	bool IsOnceKeyUp(int key);
	bool IsOnceKeyUp(char key);
	// Ű�� ������ �ִ��� �Ǵ�
	bool IsStayKeyDown(int key);
	bool IsStayKeyDown(char key);
};


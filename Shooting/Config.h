#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

#include <bitset>

using namespace std;

/*
* ����
* ZombieLupin�� AŰ�� ��� ������ ��� ����
* Banana�� ZombieLupin�� isShoot�� ������Ѿ� �ϴ°� �ȵ�
*/

//ȭ��ũ��
#define WIN_START_POS_X			600
#define WIN_START_POS_Y			200
#define WIN_SIZE_X				600
#define WIN_SIZE_Y				300

//Ű�Է�
#define KEY_MAX_COUNT			256
#define MOVE_RIGHT				VK_RIGHT
#define MOVE_LEFT				VK_LEFT
#define BANANA_ATTACK			'A'

//����
//����SIZE
#define MONSTER_SIZE_LEFT		monsterPos.x - (monsterBodySize / 2)
#define MONSTER_SIZE_TOP		monsterPos.y - (monsterBodySize / 2)
#define MONSTER_SIZE_RIGHT		monsterPos.x + (monsterBodySize / 2)
#define MONSTER_SIZE_BOTTOM		monsterPos.y + (monsterBodySize / 2)
//���� �̹���(������(��)) ����
#define INSERT_MONSTER_IMAGE(p)	p->Render(hdc, monsterPos.x, monsterPos.y, frameX, frameY)
//�������
#define ZOMBIELUPIN_POX_X		WIN_SIZE_X / 4.0f
#define ZOMBIELUPIN_POX_Y		WIN_SIZE_Y - 115.0f
#define ZOMBIELUPIN_BODYSIZE	40
#define ZOMBIELUPIN_SPEED		5.0f

//����
//����SIZE
#define WEAPON_SIZE_LEFT		weaponPos.x - (weaponBodySize / 2)
#define WEAPON_SIZE_TOP			weaponPos.y - (weaponBodySize / 2)
#define WEAPON_SIZE_RIGHT		weaponPos.x + (weaponBodySize / 2)
#define WEAPON_SIZE_BOTTOM		weaponPos.y + (weaponBodySize / 2)
//���� �̹���(������(��)) ����
#define INSERT_WEAPON_IMAGE(p)	p->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY)
//�ٳ���
#define BANANA_POX_X			0.0f
#define BANANA_POX_Y			0.0f
#define BANANA_BODYSIZE			27
#define BANANA_SPEED			10.0f

//����
#define SAFE_DELETE(p) { if(p) { delete p; p=nullptr;} }
#define SAFE_RELEASE(p) { if(p) {p->Release(); delete p; p=nullptr;} }

//�ܺ�����
extern HINSTANCE	g_hInstance;
extern HWND			g_hWnd;
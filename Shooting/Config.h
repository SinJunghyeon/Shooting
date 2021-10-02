#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

#include <bitset>

using namespace std;

/*
* 버그
* ZombieLupin에 A키를 계속 누르면 계속 생성
* Banana에 ZombieLupin의 isShoot을 제어시켜야 하는게 안됨
*/

//화면크기
#define WIN_START_POS_X			600
#define WIN_START_POS_Y			200
#define WIN_SIZE_X				600
#define WIN_SIZE_Y				300

//키입력
#define KEY_MAX_COUNT			256
#define MOVE_RIGHT				VK_RIGHT
#define MOVE_LEFT				VK_LEFT
#define BANANA_ATTACK			'A'

//몬스터
//몬스터SIZE
#define MONSTER_SIZE_LEFT		monsterPos.x - (monsterBodySize / 2)
#define MONSTER_SIZE_TOP		monsterPos.y - (monsterBodySize / 2)
#define MONSTER_SIZE_RIGHT		monsterPos.x + (monsterBodySize / 2)
#define MONSTER_SIZE_BOTTOM		monsterPos.y + (monsterBodySize / 2)
//몬스터 이미지(프레임(유)) 삽입
#define INSERT_MONSTER_IMAGE(p)	p->Render(hdc, monsterPos.x, monsterPos.y, frameX, frameY)
//좀비루팡
#define ZOMBIELUPIN_POX_X		WIN_SIZE_X / 4.0f
#define ZOMBIELUPIN_POX_Y		WIN_SIZE_Y - 115.0f
#define ZOMBIELUPIN_BODYSIZE	40
#define ZOMBIELUPIN_SPEED		5.0f

//무기
//무기SIZE
#define WEAPON_SIZE_LEFT		weaponPos.x - (weaponBodySize / 2)
#define WEAPON_SIZE_TOP			weaponPos.y - (weaponBodySize / 2)
#define WEAPON_SIZE_RIGHT		weaponPos.x + (weaponBodySize / 2)
#define WEAPON_SIZE_BOTTOM		weaponPos.y + (weaponBodySize / 2)
//무기 이미지(프레임(유)) 삽입
#define INSERT_WEAPON_IMAGE(p)	p->Render(hdc, weaponPos.x, weaponPos.y, frameX, frameY)
//바나나
#define BANANA_POX_X			0.0f
#define BANANA_POX_Y			0.0f
#define BANANA_BODYSIZE			27
#define BANANA_SPEED			10.0f

//제거
#define SAFE_DELETE(p) { if(p) { delete p; p=nullptr;} }
#define SAFE_RELEASE(p) { if(p) {p->Release(); delete p; p=nullptr;} }

//외부참조
extern HINSTANCE	g_hInstance;
extern HWND			g_hWnd;
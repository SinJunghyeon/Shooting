#pragma once

#include <Windows.h>
#include <iostream>

using namespace std;

//화면크기
#define WIN_START_POS_X	200
#define WIN_START_POS_Y	100
#define WIN_SIZE_X		600
#define WIN_SIZE_Y		300

//키입력
#define KEY_MAX_COUNT	256
#define MOVE_RIGHT		VK_RIGHT
#define MOVE_LEFT		VK_LEFT
#define BANANA_ATTACK	'A'

//제거
#define SAFE_RELEASE(p) { if(p) {p->Release(); delete p; p=nullptr;} }

//외부참조
extern HINSTANCE	g_hInstance;
extern HWND			g_hWnd;
#pragma once

#include "Config.h"
#include "GameObject.h"

class Image;

class ZombieLupin;

class MainGame : public GameObject
{
private:
	// ≈∏¿Ã∏”
	HANDLE hTimer;
	//BackBuffer
	Image* backBuffer;
	//Background;
	Image* bG;
	//ZombieLupin
	ZombieLupin* zombieLupin;

protected:


public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

};


#include "MainGame.h"

#include "Image.h"
#include "ZombieLupin.h"

void MainGame::Init()
{
	//타이머 셋팅
	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);
	//BackBuffer
	backBuffer = new Image;
	backBuffer->Init(WIN_SIZE_X, WIN_SIZE_Y);
	//Background
	bG = new Image;
	bG->Init("Image/BackGround/Sample.bmp", WIN_SIZE_X, WIN_SIZE_Y, 1, 1, false, NULL);
	//ZombieLupin
	zombieLupin = new ZombieLupin;
	zombieLupin->Init();
}

void MainGame::Update()
{
	zombieLupin->Update();
	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();
	bG->Render(hBackBufferDC);
	zombieLupin->Render(hBackBufferDC);
	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	SAFE_RELEASE(zombieLupin);	//ZombieLupin 제거
	SAFE_RELEASE(bG);			//BackGround 제거
	KillTimer(g_hWnd, 0);		//타이머 객체 삭제
}

LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		}
		break;
	case WM_LBUTTONDOWN:
		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_MOUSEMOVE:
		break;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}

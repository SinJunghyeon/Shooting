//main.cpp

#include "Config.h"
#include "MainGame.h"

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

HINSTANCE	g_hInstance;
HWND		g_hWnd;
LPSTR		g_lpszClass = (LPSTR)TEXT("ZombieLupin");
MainGame	g_mainGame;

void SetWindowSize(int startX, int startY, int sizeX, int sizeY);

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpszCmdParam, int nCmdShow)
{
	g_hInstance = _hInstance;
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = _hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = g_lpszClass;
	wndClass.lpszMenuName = g_lpszClass;
	wndClass.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;

	RegisterClass(&wndClass);

	g_hWnd = CreateWindow(g_lpszClass, g_lpszClass, WS_OVERLAPPEDWINDOW, WIN_START_POS_X, WIN_START_POS_Y, WIN_SIZE_X, WIN_SIZE_Y, NULL, NULL, _hInstance, NULL);

	SetWindowSize(WIN_START_POS_X, WIN_START_POS_Y, WIN_SIZE_X, WIN_SIZE_Y);

	g_mainGame.Init();

	ShowWindow(g_hWnd, nCmdShow);

	MSG message;
	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	// 메인게임 해제
	g_mainGame.Release();

	return message.wParam;
}

void SetWindowSize(int startX, int startY, int sizeX, int sizeY)
{
	// 원하는 윈도우 작업영역 설정
	RECT rc;
	rc.left = 0; rc.top = 0;
	rc.right = sizeX;	rc.bottom = sizeY;

	// 스타일이 포함된 실제 윈도우 크기 계산
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);

	// 계산된 값으로 윈도우를 이동시키면서 크기도 함께 변환
	MoveWindow(g_hWnd, startX, startY,
		rc.right - rc.left, rc.bottom - rc.top, true);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static bool isUpdate = true;

	switch (iMessage)
	{
	case WM_CREATE:
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
			isUpdate = !isUpdate;
			break;
		}
		break;
	case WM_TIMER:
		if (isUpdate)
		{
			g_mainGame.Update();
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(g_hWnd, &ps);

		RECT rect;
		SetMapMode(hdc, MM_ANISOTROPIC);
		SetWindowExtEx(hdc, WIN_SIZE_X, WIN_SIZE_Y, NULL);
		GetClientRect(hWnd, &rect);
		SetViewportExtEx(hdc, rect.right, rect.bottom, NULL);

		g_mainGame.Render(hdc);

		EndPaint(g_hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return g_mainGame.MainProc(hWnd, iMessage, wParam, lParam);
}
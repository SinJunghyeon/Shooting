#pragma once

#include "Config.h"

class Image
{
public:
	enum ImageLoadType { Resource, File, Empty, End };
	typedef struct tagImageInfo
	{
		HDC hMemDc;
		HBITMAP hBitmap;
		HBITMAP hOldBit;
		int width;
		int height;
		BYTE loadType;

		int maxFrameX;
		int maxFrameY;
		int frameWidth;
		int frameHeight;
		int currFrameX;
		int currFrameY;

		tagImageInfo()
		{
			hMemDc = NULL;
			hBitmap = NULL;
			hOldBit = NULL;
			width = 0;
			height = 0;
			loadType = ImageLoadType::Empty;

			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			currFrameX = 0;
			currFrameY = 0;
		};
	} IMAGE_INFO, * LPIMAGE_INFO;

private:
	LPIMAGE_INFO imageInfo;
	COLORREF transColor;
	bool isTransparent;

protected:


public:
	HRESULT Init(int width, int height);																										//빈 비트맵 이미지 생성(Empty)
	HRESULT Init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = NULL);								//File 프레임 무
	HRESULT Init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = NULL);	//File 프레임 유

	void Release();														//메모리 해제

	void Render(HDC hdc);												//이미지 데이터를 화면에 복사
	void Render(HDC hdc, int destX, int destY);							//이미지 데이터를 화면에
	void Render(HDC hdc, int destX, int destY, int frameX, int framY);	//이미지 데이터를 화면에

	HDC GetMemDC() { if (imageInfo) return imageInfo->hMemDc; }
};


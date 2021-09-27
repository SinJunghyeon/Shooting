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
	HRESULT Init(int width, int height);																										//�� ��Ʈ�� �̹��� ����(Empty)
	HRESULT Init(const char* fileName, int width, int height, bool isTrans = false, COLORREF transColor = NULL);								//File ������ ��
	HRESULT Init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans = false, COLORREF transColor = NULL);	//File ������ ��

	void Release();														//�޸� ����

	void Render(HDC hdc);												//�̹��� �����͸� ȭ�鿡 ����
	void Render(HDC hdc, int destX, int destY);							//�̹��� �����͸� ȭ�鿡
	void Render(HDC hdc, int destX, int destY, int frameX, int framY);	//�̹��� �����͸� ȭ�鿡

	HDC GetMemDC() { if (imageInfo) return imageInfo->hMemDc; }
};


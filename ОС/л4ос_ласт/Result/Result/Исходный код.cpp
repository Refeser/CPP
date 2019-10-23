#include "windows.h"
/* ���������� ������� ����       */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "Lab4Group4233Var22Dallas";           // ��� "������" ���� 			
				/*       ������� �������          */
int x = -1, y = -1;
int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst,
	LPSTR lpszArgs, int nWinMode)
{
	HWND hWnd;                          // ���������� ����  
	MSG msg;                            // ���������        
	WNDCLASSEX wcl;                     // "�����" ����     							/*  ����������� "������" (�����) ���� */
	wcl.hInstance = hThisInst; /*���������� ������� ����������*/
	wcl.lpszClassName = (LPCSTR)szWinName;   // ��� "������" ����  
	wcl.lpfnWndProc = WindowFunc;       // ������� ����
	wcl.style = 0;                      // ����� �� ���������
	wcl.cbSize = sizeof(WNDCLASSEX);    // ������ ���������
	wcl.hIcon = LoadIcon(NULL, IDI_EXCLAMATION); //�����.������
	wcl.hIconSm = LoadIcon(NULL, IDI_APPLICATION); // ����� ������
	wcl.hCursor = LoadCursor(NULL, IDC_APPSTARTING); //����� �������
	wcl.lpszMenuName = NULL;      // ���� �� ������������
	wcl.cbClsExtra = 0;           // ��������. ���������� ���
	wcl.cbWndExtra = 0;
	/* ��� ���� �������� �����   */
	wcl.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	/* ����������� "������" ���� */
	if (!RegisterClassEx(&wcl))  return 0;
	/*     �������� ����         */
	hWnd = CreateWindowEx
	(0, (LPCSTR)szWinName,      	// ��� "������" ����
		(LPCSTR)"Videneeva Yulia 4233", 			// ���������
		WS_OVERLAPPED | WS_SYSMENU,   // ����������� ����
		100,         // ���������� � - �� ���������
		100,         // ���������� Y - �� ���������
		1024,         // ������       - �� ���������
		512,         // ������       - �� ���������
		HWND_DESKTOP,          // ������������� ���� ���
		NULL,                  // ���� ���  
		hThisInst, // ���������� ������� ���������� ����������
		NULL                  // �������������� ���������� ���
	);
	/*     ����������� ����       */
	ShowWindow(hWnd, nWinMode);
	/*     ���� ���������        */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
/*---------------------------------------------*/
/*               �������  ����                 */
/*---------------------------------------------*/
/* ��� ������� �������� Windows � �������� ��  */
/* �� ��������� ��������� �� ������� ��������� */
/*---------------------------------------------*/
HDC hdc, memdc;
HBITMAP hbit;
HBRUSH hbrush_1, hbrush_2, hbrush_3, hbrush_4;
HPEN hBluepen, hGreenpen;
HWND hWnd;
int xPosR, yPosR, a = 0, z = 10, xPos, yPos, n=0;
LRESULT CALLBACK WindowFunc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	char str[50] = "�������� ����������?";
	int xPosR, yPosR, maxX, maxY;
	PAINTSTRUCT paintstruct;
	switch (message)
	{

	case WM_CREATE:
	{
		maxX = GetSystemMetrics(SM_CXSCREEN);
		maxY = GetSystemMetrics(SM_CXSCREEN);
		hdc = GetDC(hWnd);
		memdc = CreateCompatibleDC(hdc);
		hbit = CreateCompatibleBitmap(hdc, maxX, maxY);
		SelectObject(memdc, hbit);
		hBluepen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
		hGreenpen = CreatePen(PS_SOLID, 4, RGB(0, 255, 0));
		hbrush_1 = CreateSolidBrush(RGB(255, 0, 0));
		hbrush_2 = CreateSolidBrush(RGB(128, 0, 255));
		hbrush_3 = CreateSolidBrush(RGB(0, 0, 255));
		hbrush_4 = CreateSolidBrush(RGB(132, 132, 132));
		PatBlt(memdc, 0, 0, maxX, maxY, PATCOPY);
		ReleaseDC(hWnd, hdc);
		break;
	}

	case WM_DESTROY:         /* "��������� ���������" */
	{
		DeleteObject(hBluepen);
		DeleteObject(hGreenpen);
		DeleteObject(hbit);
		DeleteDC(memdc);
		PostQuitMessage(0);
		break;
	}

	case WM_LBUTTONDOWN:
	{
		z = z - 5;
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);
		switch (n % 4)
		{
		case 0:
		{
			SelectObject(memdc, hBluepen);
			SelectObject(memdc, hbrush_3);
			Ellipse(memdc, xPos, yPos, xPos + 25, yPos + 25);
			break;
		}
		case 1:
		{
			SelectObject(memdc, hBluepen);
			SelectObject(memdc, hbrush_1);
			Rectangle(memdc, xPos, yPos, xPos + 25, yPos + 25);
			break;

		}
		case 2:
		{
			SelectObject(memdc, hGreenpen);
			SelectObject(memdc, hbrush_4);
			Ellipse(memdc, xPos, yPos, xPos + 25, yPos + 25);
			break;
		}
		case 3:
		{
			SelectObject(memdc, hGreenpen);
			SelectObject(memdc, hbrush_2);
			Rectangle(memdc, xPos, yPos, xPos + 25, yPos + 25);
			break;

		}
		}
		n++;
		InvalidateRect(hWnd, NULL, 1);
		break;
	}

	case WM_RBUTTONDOWN:
	{
		z = z + 5;
		xPosR = LOWORD(lParam);
		yPosR = HIWORD(lParam);
		SetTextColor(memdc, RGB(200, 200, 200));
		SetBkColor(memdc, RGB(120, 120, 120));
		a++;
		char b[15];
		int c = wsprintf(b, "%d", a);
		TextOut(memdc, xPosR, yPosR, (LPCSTR)b, c);
		MoveToEx(memdc, 0, 0, NULL);
		SelectObject(memdc, hGreenpen);
		LineTo(memdc, xPosR, yPosR);
		if (a>1)
		{
			SelectObject(memdc, hBluepen);
			LineTo(memdc, x, y);
		}
		InvalidateRect(hWnd, NULL, 0);
		x = xPosR;
		y = yPosR;
		break;
	}

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &paintstruct);
		BitBlt(hdc, paintstruct.rcPaint.left, paintstruct.rcPaint.top, paintstruct.rcPaint.right - paintstruct.rcPaint.left, paintstruct.rcPaint.bottom - paintstruct.rcPaint.top, memdc, paintstruct.rcPaint.left, paintstruct.rcPaint.top, SRCCOPY);
		HBRUSH hbrush_1 = CreateSolidBrush(RGB(123, 123, 123));
		HBRUSH hbrush_2 = CreateSolidBrush(RGB(23, 255, 0));
		SelectObject(hdc, hGreenpen);
		SelectObject(hdc, hbrush_1);
		Rectangle(hdc, z, 15, z + 50, 50);
		SelectObject(hdc, hBluepen);
		SelectObject(hdc, hbrush_2);
		Ellipse(hdc, z, 15, z + 25, 35);
		DeleteObject(hbrush_1);
		DeleteObject(hbrush_2);
		EndPaint(hWnd, &paintstruct);
		break;
	}

	default:




		/* ��������� ��������� ������������  */
		/* ������������ �������              */
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
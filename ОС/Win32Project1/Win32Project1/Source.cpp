#include "windows.h"
/* ���������� ������� ����       */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "Lab4Group4233Var22Dallas";           // ��� "������" ���� 			
														 /*       ������� �������          */
int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst,
	LPSTR lpszArgs, int nWinMode)
{
	HWND hWnd;                          // ���������� ����  
	MSG msg;                            // ���������        
	WNDCLASSEX wcl;                     // "�����" ����     							/*  ����������� "������" (�����) ���� */
	wcl.hInstance = hThisInst; /*���������� ������� ����������*/
	wcl.lpszClassName = (LPCWSTR)szWinName;   // ��� "������" ����  
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
	(0, (LPCWSTR)szWinName,      	// ��� "������" ����
		(LPCWSTR)"Videneeva Yulia 4233", 			// ���������
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
HBRUSH hbrush_1, hbrush_2, hbrush_3, hbrush_4, hbrush_5;
HPEN hpen_1, hpen_2, hpen_3, hpen_4, hpen_5;
HWND hWnd;
HDC hdc;
int xPosR = -1, yPosR = -1;
LRESULT CALLBACK WindowFunc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	char str[50] = "�������� ����������?";
	int xPos, yPos, res;
	PAINTSTRUCT paintstruct;
	switch (message)
	{
	case WM_LBUTTONDOWN:
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);
		res = MessageBox(hWnd, (LPCWSTR)str, (LPCWSTR)"�������� ����������?", MB_YESNO);
		if (res == IDYES)
		{
			wsprintf((LPWSTR)str, (LPCWSTR)"���������� ������� ����:\n x=%d; y=%d", xPos, yPos);
			MessageBox
			(hWnd, (LPCWSTR)str, (LPCWSTR)"����� ������", MB_OK | MB_ICONINFORMATION);
		}
		break;
	case WM_RBUTTONDOWN:
		xPosR = LOWORD(lParam);
		yPosR = HIWORD(lParam);

		InvalidateRect(hWnd, NULL, 1);
		break;
	case WM_PAINT: {
		hbrush_1 = CreateSolidBrush(RGB(0, 0, 0));
		hbrush_2 = CreateHatchBrush(HS_VERTICAL, RGB(255, 255, 255));
		hbrush_3 = CreateSolidBrush(RGB(255, 255, 255));
		hbrush_4 = CreateHatchBrush(HS_HORIZONTAL, RGB(231, 213, 134));
		hbrush_5 = CreateHatchBrush(HS_BDIAGONAL, RGB(255, 0, 123));
		hpen_1 = CreatePen(PS_DASH, 2, RGB(255, 0, 234));
		hpen_2 = CreatePen(PS_SOLID, 3, RGB(0, 255, 255));
		hpen_3 = CreatePen(PS_DOT, 2, RGB(0, 125, 212));
		hpen_4 = CreatePen(PS_SOLID, 1, RGB(220, 115, 35));
		hpen_5 = CreatePen(PS_DASH, 2, RGB(0, 212, 137));
		hdc = BeginPaint(hWnd, &paintstruct);
		SelectObject(hdc, hpen_1);
		Rectangle(hdc, 11, 11, 56, 56);
		SelectObject(hdc, hbrush_1);
		Rectangle(hdc, 10, 10, 55, 55);
		SelectObject(hdc, hpen_2);
		Rectangle(hdc, 31, 31, 67, 67);
		SelectObject(hdc, hbrush_2);
		Rectangle(hdc, 30, 30, 66, 66);
		SelectObject(hdc, hpen_3);
		Ellipse(hdc, 101, 101, 123, 123);
		SelectObject(hdc, hbrush_3);
		Ellipse(hdc, 100, 100, 122, 122);
		SelectObject(hdc, hpen_4);
		Ellipse(hdc, 252, 252, 182, 182);
		SelectObject(hdc, hbrush_4);
		Ellipse(hdc, 251, 251, 181, 181);
		SelectObject(hdc, hpen_5);
		Ellipse(hdc, 345, 345, 455, 455);
		SelectObject(hdc, hbrush_5);
		Ellipse(hdc, 344, 344, 454, 454);
		SetTextColor(hdc, RGB(255, 0, 123));
		SetBkColor(hdc, RGB(123, 255, 0));
		TextOut(hdc, 43, 34, (LPCWSTR)"��������� ���� 4233", 19);
		if (xPosR >= 0)
		{
			char text[] = "������ ������";
			SetTextColor(hdc, RGB(255, 0, 150));
			SetBkColor(hdc, RGB(136, 45, 0));
			TextOut(hdc, xPosR, yPosR, (LPCWSTR)text, 13);
		}


		EndPaint(hWnd, &paintstruct);
		DeleteObject(hbrush_1);
		DeleteObject(hbrush_2);
		DeleteObject(hbrush_3);
		DeleteObject(hbrush_4);
		DeleteObject(hbrush_5);
		DeleteObject(hpen_1);
		DeleteObject(hpen_3);
		DeleteObject(hpen_2);
		DeleteObject(hpen_4);
		DeleteObject(hpen_5);
		break;
	}
	case WM_DESTROY:         /* "��������� ���������" */
		PostQuitMessage(0);
		break;
	default:
		/* ��������� ��������� ������������  */
		/* ������������ �������              */
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
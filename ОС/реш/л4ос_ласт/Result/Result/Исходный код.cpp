#include "windows.h"

/* ���������� ������� ����       */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "Lab4Group4233Var12Tools";           // ��� "������" ���� 
														/*       ������� �������          */
int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst,
	LPSTR lpszArgs, int nWinMode)
{
	HWND hWnd;                          // ���������� ����  
	MSG msg;                            // ���������        
	WNDCLASSEX wcl;                     // "�����" ����     
										/*  ����������� "������" (�����) ���� */
	wcl.hInstance = hThisInst; /*���������� ������� ����������*/
	wcl.lpszClassName = (LPCSTR)szWinName;   // ��� "������" ����  
	wcl.lpfnWndProc = WindowFunc;       // ������� ����
	wcl.style = 0;                      // ����� �� ���������
	wcl.cbSize = sizeof(WNDCLASSEX);    // ������ ���������
	wcl.hIcon = LoadIcon(NULL, IDI_ASTERISK); //�����.������
	wcl.hIconSm = LoadIcon(NULL, IDI_HAND); // ����� ������
	wcl.hCursor = LoadCursor(NULL, IDC_WAIT); //����� �������
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
		(LPCSTR)"Khasanov_Almaz_4233", 			// ���������
		WS_OVERLAPPED | WS_SYSMENU,   // ����������� ����
		128,         // ���������� � - �� ���������
		256,         // ���������� Y - �� ���������
		780,         // ������       - �� ���������
		526,         // ������       - �� ���������
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
HPEN hRedpen, hGreenpen;
HWND hWnd;
int xPosR, yPosR;
LRESULT CALLBACK WindowFunc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	int xPosR, yPosR, maxX, maxY, m=0;
	PAINTSTRUCT paintstruct;
	switch (message)
	{

	case WM_CREATE:
	{
		HDC hdc, memdc;
		HBITMAP hbit;
		maxX = GetSystemMetrics(SM_CXSCREEN);
		maxY = GetSystemMetrics(SM_CXSCREEN);
		hdc = GetDC(hWnd);
		memdc = CreateCompatibleDC(hdc);
		hbit = CreateCompatibleBitmap(hdc, maxX, maxY);
		SelectObject(memdc, hbit);
		hRedpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		hGreenpen = CreatePen(PS_SOLID, 4, RGB(0, 255, 0));
		PatBlt(memdc, 0, 0, maxX, maxY, PATCOPY);
		ReleaseDC(hWnd, hdc);
		break;
	}

	case WM_PAINT: {
	case WM_RBUTTONDOWN:
	{
		m++;
		xPosR = LOWORD(lParam);
		yPosR = HIWORD(lParam);
		InvalidateRect(hWnd, NULL, 0);
		break;
	}
		HDC hdc = BeginPaint(hWnd, &paintstruct);
		SetTextColor(hdc, RGB(23,142,152));
		SetBkColor(hdc, RGB(142,251,14));
		TextOut(hdc, xPosR, yPosR, (LPCSTR)m, 1);
		EndPaint(hWnd, &paintstruct);
		break;
	}
	case WM_DESTROY:         /* "��������� ���������" */
	{
		DeleteObject(hRedpen);
		DeleteObject(hGreenpen);
		DeleteObject(hbit);
		DeleteDC(memdc);
		PostQuitMessage(0);
		break;
	}

	default:




		/* ��������� ��������� ������������  */
		/* ������������ �������              */
		return DefWindowProc(hWnd, message, wParam, lParam);
	}



	return 0;
}
#include "windows.h"
#include "resource.h"

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;    // ���������� ����������
HWND BtHWnd, BtHWnd2;            //    ������
HWND EdtHWnd, EdtHWnd2;            //    ��������
char szWinName[] = "MyWin";    // ��� ������ ����
char name[] = "�������� ������� 4233";
							   /*             ������� �������                     */
int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode) {
	HWND hWnd;
	MSG msg;
	WNDCLASSEX wcl;
	wcl.hInstance = hThisInst;
	wcl.lpszClassName = (LPCWSTR)szWinName;
	wcl.lpfnWndProc = WindowFunc;
	wcl.style = 0;
	wcl.cbSize = sizeof(WNDCLASSEX);
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	if (!RegisterClassEx(&wcl)) return 0;
	hWnd = CreateWindow(
		(LPCWSTR)szWinName,
		(LPCWSTR)name, // ���������
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		HWND_DESKTOP, NULL, hThisInst, NULL);
	/* ���������� ���������� ����������
	��� �������� �������� ��������� ���������� */
	hInstance = hThisInst;
	ShowWindow(hWnd, nWinMode);
	UpdateWindow(hWnd);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

/*                 ������� ����                */
LRESULT CALLBACK WindowFunc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	char msg[100];
	int r;
	switch (message) {
	case WM_DESTROY:            // ���������� ���������
		PostQuitMessage(0);
		break;
		/* ��������� �� ������� ���� � ��������� ���������� */
	case WM_COMMAND:
		if (LOWORD(wParam) == IDM_START) //����� ���� - Start
		{
			MessageBoxA(hWnd, "Timer started",
				"Generation started", MB_OK);
			SetTimer(hWnd, 1, 1000, NULL); // ��������� �������
		}
		if (LOWORD(wParam) == IDM_STOP) // ����� ���� - Stop
		{
			MessageBoxA(hWnd, "Timer stoped",
				"Generation stopped", MB_OK);
			KillTimer(hWnd, 1); // ���������� ������ �������
		}
		if (HWND(lParam) == BtHWnd) // ��������� �� ������
		{
			lstrcpy(msg, "0");
			/* ��������� ������ � ���� �����      		*/
			SendMessage(EdtHWnd, WM_SETTEXT, 0, (LPARAM)(LPCTSTR)msg);
		}
		if (HWND(lParam) == BtHWnd2)
		{
			lstrcpy(msg, "0");
			SendMessage(EdtHWnd2, WM_SETTEXT, 0, (LPARAM) "");
		}
		if (LOWORD(wParam) == IDM_START2)
		{
			MessageBoxA(hWnd, "Timer started",
				"Generation started", MB_OK);
			SetTimer(hWnd, 2, 2000, NULL);
		}
		if (LOWORD(wParam) == IDM_STOP2)
		{
			MessageBoxA(hWnd, "Timer stoped",
				"Generation stopped", MB_OK);
			KillTimer(hWnd, 2);
		}

		if (LOWORD(wParam) == IDM_EXIT)
			DestroyWindow(hWnd);
		break;

	case WM_TIMER:            // ��������� �� �������
		switch (wParam)
		{
		case 1:
		{
			int k;
			r = rand() % 20;
			/* ��������� ����� ������ � ���� ����� 		*/
			k = SendMessage(EdtHWnd, WM_GETTEXTLENGTH, 0, 0);
			/* ��������� ������ �� ���� ����� 			*/
			SendMessage(EdtHWnd, WM_GETTEXT, k + 1, (LPARAM)msg);
			/* ������� �������� �� ������ � ����� � ������������*/
			r += atoi(msg);
			/* ������� �� ����� � ������				*/
			wsprintfA(msg, "%d", r);
			/* ��������� ������ � ���� ����� 			*/
			SendMessage(EdtHWnd, WM_SETTEXT, 0, (LPARAM)(LPCTSTR)msg);
			break;
		}
		case 2:
		{
			int k;
			k = SendMessage(EdtHWnd, WM_GETTEXTLENGTH, 0, 0);
			SendMessage(EdtHWnd, WM_GETTEXT, k + 1, (LPARAM)msg);
			r = atoi(msg);
			wsprintfA(msg, "Timer %d", r);
			SendMessage(EdtHWnd2, WM_SETTEXT, 0, (LPARAM)(LPCTSTR)msg);
			break;
		}

		}
		break;

	case WM_CREATE:            // ��������� � �������� ����
							   /*                   �������� ������         	*/
		BtHWnd = CreateWindow(
			(LPCWSTR)"BUTTON",            // ��� ������ ����
			(LPCWSTR)"Reset",                // ���������
			WS_CHILD | WS_VISIBLE | WS_BORDER,    // �����
			5, 10, 50, 40,        // ���������� � �������
			hWnd,            // ���������� ������������� ����
			NULL,            // ���� ���
			hInstance,        // ���������� ����������
			NULL);

		/*        �������� ���������(���� �����)     	*/
		EdtHWnd = CreateWindow(
			(LPCWSTR)"EDIT",                // ��� ������ ����
			(LPCWSTR)"0",                // ���������
			WS_CHILD | WS_VISIBLE | WS_BORDER | WS_THICKFRAME,
			60, 10, 70, 70,        // ���������� � �������
			hWnd,            // ���������� ������������� ����
			NULL,            // ���� ���
			hInstance,        // ���������� ����������
			NULL);

		BtHWnd2 = CreateWindow(
			(LPCWSTR)"BUTTON",
			(LPCWSTR)"Reset2",
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			5, 100, 50, 40,
			hWnd,
			NULL,
			hInstance,
			NULL),

			EdtHWnd2 = CreateWindow(
				(LPCWSTR)"EDIT",
				(LPCWSTR)"",
				WS_CHILD | WS_VISIBLE | WS_BORDER | WS_THICKFRAME,
				60, 100, 70, 70,
				hWnd,
				NULL,
				hInstance,
				NULL);

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
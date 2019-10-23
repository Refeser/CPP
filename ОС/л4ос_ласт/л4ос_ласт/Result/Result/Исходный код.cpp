#include "windows.h"

/* объявление функции окна       */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "Lab4Group4233Var12Tools";           // Имя "класса" окна 
														/*       Главная функция          */
int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst,
	LPSTR lpszArgs, int nWinMode)
{
	HWND hWnd;                          // дескриптор окна  
	MSG msg;                            // сообщение        
	WNDCLASSEX wcl;                     // "класс" окна     
										/*  Определение "класса" (стиля) окна */
	wcl.hInstance = hThisInst; /*дескриптор данного экземпляра*/
	wcl.lpszClassName = (LPCSTR)szWinName;   // имя "класса" окна  
	wcl.lpfnWndProc = WindowFunc;       // функция окна
	wcl.style = 0;                      // стиль по умолчанию
	wcl.cbSize = sizeof(WNDCLASSEX);    // размер структуры
	wcl.hIcon = LoadIcon(NULL, IDI_ASTERISK); //больш.иконка
	wcl.hIconSm = LoadIcon(NULL, IDI_HAND); // малая иконка
	wcl.hCursor = LoadCursor(NULL, IDC_WAIT); //форма курсора
	wcl.lpszMenuName = NULL;      // меню не используется
	wcl.cbClsExtra = 0;           // дополнит. информации нет
	wcl.cbWndExtra = 0;
	/* Фон окна задается белым   */
	wcl.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	/* Регистрация "класса" окна */
	if (!RegisterClassEx(&wcl))  return 0;
	/*     Создание окна         */
	hWnd = CreateWindowEx
	(0, (LPCSTR)szWinName,      	// имя "класса" окна
		(LPCSTR)"Khasanov_Almaz_4233", 			// заголовок
		WS_OVERLAPPED | WS_SYSMENU,   // стандартное окно
		128,         // координата Х - по умолчанию
		256,         // координата Y - по умолчанию
		780,         // ширина       - по умолчанию
		526,         // высота       - по умолчанию
		HWND_DESKTOP,          // родительского окна нет
		NULL,                  // меню нет  
		hThisInst, // дескриптор данного экземпляра приложения
		NULL                  // дополнительных аргументов нет
	);
	/*     Отображение окна       */
	ShowWindow(hWnd, nWinMode);
	/*     Цикл сообщений        */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
/*---------------------------------------------*/
/*               Функция  окна                 */
/*---------------------------------------------*/
/* Эту функцию вызывает Windows и передает ей  */
/* на обработку сообщения из очереди сообщений */
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
	case WM_DESTROY:         /* "завершить программу" */
	{
		DeleteObject(hRedpen);
		DeleteObject(hGreenpen);
		DeleteObject(hbit);
		DeleteDC(memdc);
		PostQuitMessage(0);
		break;
	}

	default:




		/* Остальные сообщения обрабатывать  */
		/* операционной системе              */
		return DefWindowProc(hWnd, message, wParam, lParam);
	}



	return 0;
}
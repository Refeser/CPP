#include "windows.h"
#include "resource.h"

/*         объявление функции окна                */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "MyWin";       // Имя "класса" окна 
								  /*----------------------------------------------------*/
								  /*                 Главная функция                    */
								  /*----------------------------------------------------*/
int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst,
	LPSTR lpszArgs, int nWinMode)
{
	HWND hWnd;                      // дескриптор окна  
	MSG msg;                        //  сообщение   
	WNDCLASSEX wcl;                 // "класс" окна  
									/*  Определение элементов "класса"  окна */
	wcl.hInstance = hThisInst; 	//дескриптор данного экземпляра
	wcl.lpszClassName = (LPCWSTR)szWinName;	// имя "класса" окна  			*/
	wcl.lpfnWndProc = WindowFunc;	// функция окна       			*/
	wcl.style = 0;
	wcl.cbSize = sizeof(WNDCLASSEX);
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1); // меню
	wcl.cbClsExtra = 0; wcl.cbWndExtra = 0;
	/* Фон окна задается белым   */
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	/*         Регистрация "класса" окна        */
	if (!RegisterClassEx(&wcl))  return 0;
	/*         Создание окна                    */
	hWnd = CreateWindow
	((LPCWSTR)szWinName,
		(LPCWSTR)"Газизова Гульнур 4233",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		HWND_DESKTOP, NULL,
		hThisInst, NULL);
	/*              Отображение окна            */
	ShowWindow(hWnd, nWinMode);
	UpdateWindow(hWnd);
	/*              Цикл сообщений              */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
/*--------------------------------------------------*/
HDC memdc; 		// контекст устройства памяти 
HBITMAP hbit; 	// растр изображения в окне 
HBRUSH hbrush, hBrush;	// дескриптор текущей кисти 	  
HBRUSH hOldbrush; 		// дескриптор прежней кисти 
HPEN hRedpen, hBluepen; 	// дескрипторы перьев
HPEN hOldpen; 		// дескриптор прежнего пера 
int maxX, maxY;		// размеры экрана
					/*   массивы точек  - координаты вершин треугольников     */
POINT mp1[3] = { { 150,50 },{ 50,150 },{ 150,150 } };// 1-й треуг-к
POINT mp2[3] = { { 250,150 },{ 350,50 },{ 450,150 } };// 2-й треуг-к 
COLORREF color = RGB(255, 255, 0);   //  цвет кисти 
COLORREF color2 = RGB(0, 0, 0);
/*--------------------------------------------------------*/
/*                      Функция  окна                     */
/*--------------------------------------------------------*/
LRESULT CALLBACK WindowFunc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;			// контекст устройства окна
	PAINTSTRUCT paintstruct; 	// характеристики области перерисовки
	switch (message)
	{
	case WM_CREATE:
		/* получение размеров окна */
		maxX = GetSystemMetrics(SM_CXSCREEN);
		maxY = GetSystemMetrics(SM_CYSCREEN);
		/* создание контекста устройства окна 			*/
		hdc = GetDC(hWnd);
		/* создание совместимого контекста устройства памяти 	*/
		memdc = CreateCompatibleDC(hdc);
		/* создание совместимого растра               		*/
		hbit = CreateCompatibleBitmap(hdc, maxX, maxY);
		/* выбор растрового изображения в контекст устройства памяти */
		SelectObject(memdc, hbit);
		/* заполнение окна белой кистью 				*/
		PatBlt(memdc, 0, 0, maxX, maxY, PATCOPY);
		/* создание красного и синего перьев 			*/
		hRedpen = CreatePen(PS_SOLID, 2, RGB(200, 0, 0));
		hBluepen = CreatePen(PS_SOLID, 4, RGB(0, 0, 255));
		/* освобождение контекста устройства окна 		*/
		ReleaseDC(hWnd, hdc);
		break;
	case WM_COMMAND:   		// выбрана команда меню 
		switch (wParam)
		{
		case ID_TREUG:
		{
			PatBlt(memdc, 0, 0, maxX, maxY, PATCOPY);
			hbrush = CreateSolidBrush(color);
			hOldbrush = (HBRUSH)SelectObject(memdc, hbrush);
			hOldpen = (HPEN)SelectObject(memdc, hRedpen);
			Rectangle(memdc, 50, 50, 200, 200);
			SelectObject(memdc, hBluepen);
			RoundRect(memdc, 250, 50, 400, 150, 30, 30);
			SelectObject(memdc, hOldpen);
			SelectObject(memdc, hOldbrush);
			DeleteObject(hbrush);
			Polygon(memdc, mp1, 3);
			InvalidateRect(hWnd, NULL, 0);
			break;
		}

		case ID_RED:
			color = RGB(250, 0, 0);
			break;


		case ID_ELLIPSE:
		{
			PatBlt(memdc, 0, 0, maxX, maxY, PATCOPY);
			hBrush = CreateSolidBrush(color);
			HBRUSH hOldBrush = (HBRUSH)SelectObject(memdc, hBrush);
			HPEN hOldPen = (HPEN)SelectObject(memdc, hBluepen);
			Ellipse(memdc, 150, 150, 200, 200);
			SelectObject(memdc, hRedpen);
			Ellipse(memdc, 300, 300, 500, 500);
			SelectObject(memdc, hOldPen);
			SelectObject(memdc, hOldBrush);
			DeleteObject(hBrush);
			InvalidateRect(hWnd, NULL, 0);
			break;
		}

		case ID_BLACK:
			color = RGB(0, 0, 0);
			break;

		case ID_CLEAR:
			PatBlt(memdc, 0, 0, maxX, maxY, PATCOPY);
			InvalidateRect(hWnd, NULL, 0);
			break;

		}
		break;
	case WM_PAINT:       		//обновление окна
		hdc = BeginPaint(hWnd, &paintstruct);
		BitBlt(hdc, 0, 0, maxX, maxY, memdc, 0, 0, SRCCOPY);
		EndPaint(hWnd, &paintstruct);
		break;
	case  WM_DESTROY:         	// "завершить программу"
								/* удаление перьев */
		DeleteObject(hRedpen);
		DeleteObject(hBluepen);
		DeleteDC(memdc);          // удаление контекста памяти
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
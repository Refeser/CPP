#include "windows.h"
     
/* объявление функции окна       */
LRESULT CALLBACK WindowFunc (HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "Lab4Group4233Var12Tools";           // Имя "класса" окна 
    /*       Главная функция          */
int WINAPI WinMain (HINSTANCE hThisInst, HINSTANCE hPrevInst,
		    LPSTR lpszArgs, int nWinMode)
{ HWND hWnd;                          // дескриптор окна  
  MSG msg;                            // сообщение        
  WNDCLASSEX wcl;                     // "класс" окна     
      /*  Определение "класса" (стиля) окна */
  wcl.hInstance = hThisInst; /*дескриптор данного экземпляра*/
  wcl.lpszClassName = (LPCWSTR)szWinName;   // имя "класса" окна  
  wcl.lpfnWndProc = WindowFunc;       // функция окна
  wcl.style = 0;                      // стиль по умолчанию
  wcl.cbSize = sizeof(WNDCLASSEX);    // размер структуры
  wcl.hIcon = LoadIcon(NULL,IDI_APPLICATION); //больш.иконка
  wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO); // малая иконка
  wcl.hCursor = LoadCursor(NULL, IDC_ARROW); //форма курсора
  wcl.lpszMenuName = NULL;      // меню не используется
  wcl.cbClsExtra = 0;           // дополнит. информации нет
  wcl.cbWndExtra = 0;
      /* Фон окна задается белым   */
  wcl.hbrBackground = (HBRUSH) GetStockObject(GRAY_BRUSH);
      /* Регистрация "класса" окна */
  if (!RegisterClassEx(&wcl))  return 0;
      /*     Создание окна         */
  hWnd = CreateWindowEx
  (  0, (LPCWSTR)szWinName,      	// имя "класса" окна
     (LPCWSTR)"Laba_4_OC", 			// заголовок
     WS_OVERLAPPEDWINDOW,   // стандартное окно
     CW_USEDEFAULT,         // координата Х - по умолчанию
     CW_USEDEFAULT,         // координата Y - по умолчанию
     CW_USEDEFAULT,         // ширина       - по умолчанию
     CW_USEDEFAULT,         // высота       - по умолчанию
     HWND_DESKTOP,          // родительского окна нет
     NULL,                  // меню нет  
     hThisInst, // дескриптор данного экземпляра приложения
     NULL                  // дополнительных аргументов нет
  );
      /*     Отображение окна       */
  ShowWindow(hWnd, nWinMode);
      /*     Цикл сообщений        */
  while (GetMessage(&msg, NULL, 0, 0))
  { TranslateMessage(&msg);
    DispatchMessage (&msg);
  }
  return msg.wParam;
}
   /*---------------------------------------------*/
   /*               Функция  окна                 */
   /*---------------------------------------------*/
   /* Эту функцию вызывает Windows и передает ей  */
   /* на обработку сообщения из очереди сообщений */
   /*---------------------------------------------*/
LRESULT CALLBACK WindowFunc (HWND hWnd, UINT message,
			     WPARAM wParam, LPARAM lParam)
{   
  switch(message)
  { case WM_DESTROY:         /* "завершить программу" */
      PostQuitMessage(0);
      break;
    
    default:
      /* Остальные сообщения обрабатывать  */
      /* операционной системе              */
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

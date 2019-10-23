#include "windows.h"
     
/* ���������� ������� ����       */
LRESULT CALLBACK WindowFunc (HWND, UINT, WPARAM, LPARAM);
char szWinName[] = "Lab4Group4233Var12Tools";           // ��� "������" ���� 
    /*       ������� �������          */
int WINAPI WinMain (HINSTANCE hThisInst, HINSTANCE hPrevInst,
		    LPSTR lpszArgs, int nWinMode)
{ HWND hWnd;                          // ���������� ����  
  MSG msg;                            // ���������        
  WNDCLASSEX wcl;                     // "�����" ����     
      /*  ����������� "������" (�����) ���� */
  wcl.hInstance = hThisInst; /*���������� ������� ����������*/
  wcl.lpszClassName = (LPCWSTR)szWinName;   // ��� "������" ����  
  wcl.lpfnWndProc = WindowFunc;       // ������� ����
  wcl.style = 0;                      // ����� �� ���������
  wcl.cbSize = sizeof(WNDCLASSEX);    // ������ ���������
  wcl.hIcon = LoadIcon(NULL,IDI_APPLICATION); //�����.������
  wcl.hIconSm = LoadIcon(NULL, IDI_WINLOGO); // ����� ������
  wcl.hCursor = LoadCursor(NULL, IDC_ARROW); //����� �������
  wcl.lpszMenuName = NULL;      // ���� �� ������������
  wcl.cbClsExtra = 0;           // ��������. ���������� ���
  wcl.cbWndExtra = 0;
      /* ��� ���� �������� �����   */
  wcl.hbrBackground = (HBRUSH) GetStockObject(GRAY_BRUSH);
      /* ����������� "������" ���� */
  if (!RegisterClassEx(&wcl))  return 0;
      /*     �������� ����         */
  hWnd = CreateWindowEx
  (  0, (LPCWSTR)szWinName,      	// ��� "������" ����
     (LPCWSTR)"Laba_4_OC", 			// ���������
     WS_OVERLAPPEDWINDOW,   // ����������� ����
     CW_USEDEFAULT,         // ���������� � - �� ���������
     CW_USEDEFAULT,         // ���������� Y - �� ���������
     CW_USEDEFAULT,         // ������       - �� ���������
     CW_USEDEFAULT,         // ������       - �� ���������
     HWND_DESKTOP,          // ������������� ���� ���
     NULL,                  // ���� ���  
     hThisInst, // ���������� ������� ���������� ����������
     NULL                  // �������������� ���������� ���
  );
      /*     ����������� ����       */
  ShowWindow(hWnd, nWinMode);
      /*     ���� ���������        */
  while (GetMessage(&msg, NULL, 0, 0))
  { TranslateMessage(&msg);
    DispatchMessage (&msg);
  }
  return msg.wParam;
}
   /*---------------------------------------------*/
   /*               �������  ����                 */
   /*---------------------------------------------*/
   /* ��� ������� �������� Windows � �������� ��  */
   /* �� ��������� ��������� �� ������� ��������� */
   /*---------------------------------------------*/
LRESULT CALLBACK WindowFunc (HWND hWnd, UINT message,
			     WPARAM wParam, LPARAM lParam)
{   
  switch(message)
  { case WM_DESTROY:         /* "��������� ���������" */
      PostQuitMessage(0);
      break;
    
    default:
      /* ��������� ��������� ������������  */
      /* ������������ �������              */
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}

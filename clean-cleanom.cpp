// clean-cleanom.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "clean-cleanom.h"
#include "CommCtrl.h"

#define MAX_LOADSTRING 100
#define CLEAR_BUTTON 1488
#define ANALYSIS_BUTTON 1489
#define RESULT_TEXT 1490
#define PROGRESS_BAR 1491

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CLEANCLEANOM, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CLEANCLEANOM));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CLEANCLEANOM));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    //wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(251, 239, 202));
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_CLEANCLEANOM);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);


   if (!hWnd)
   {
      return FALSE;
   }
   HFONT hFont = CreateFont(
	   16,
	   0,
	   0,
	   0,
	   FW_DONTCARE,
	   FALSE,
	   FALSE,
	   FALSE,
	   DEFAULT_CHARSET,
	   OUT_OUTLINE_PRECIS,
	   CLIP_DEFAULT_PRECIS,
	   CLEARTYPE_QUALITY,
	   VARIABLE_PITCH,
	   TEXT("Roboto"));

	   HFONT hFont1 = CreateFont(
		   26,
		   0,
		   0,
		   0,
		   FW_DONTCARE,
		   FALSE,
		   FALSE,
		   FALSE,
		   DEFAULT_CHARSET,
		   OUT_OUTLINE_PRECIS,
		   CLIP_DEFAULT_PRECIS,
		   CLEARTYPE_QUALITY,
		   VARIABLE_PITCH,
		   TEXT("Roboto"));

   HWND clearButton = CreateWindow(
       L"BUTTON",  // Predefined class; Unicode assumed 
       L"Видалення тимчасових файлів",      // Button text 
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
       10,         // x position 
       10,         // y position 
       250,        // Button width
       20,        // Button height
       hWnd,     // Parent window
       (HMENU)CLEAR_BUTTON,       // No menu.
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);      // Pointer not needed.
   
   SendMessage(clearButton, WM_SETFONT, (WPARAM)hFont, 0L);

   HWND analyseButton = CreateWindow(
       L"BUTTON",  // Predefined class; Unicode assumed 
       L"Аналіз видалення тимчасових файлів",      // Button text 
       WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
       270,         // x position 
       10,         // y position 
       280,        // Button width
       20,        // Button height
       hWnd,     // Parent window
       (HMENU)ANALYSIS_BUTTON,       // No menu.
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);      // Pointer not needed.

   SendMessage(analyseButton, WM_SETFONT, (WPARAM)hFont, 0L);

       HWND textOut = CreateWindowEx(
           0, L"EDIT",   // predefined class 
           NULL,         // no window title 
           WS_CHILD | WS_VISIBLE | WS_VSCROLL |
           ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL | ES_READONLY,
           200,//x
           75, //y
           750, // width
           150, // height
           hWnd,         // parent window 
           (HMENU)RESULT_TEXT,   // edit control ID 
           (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
           NULL);        // pointer not needed 

	   //LPCWSTR to_write = L"Шлях до директорії: C:\\Users\\danac\\AppData\\Local\\Temp\\ \r\nВидалення файлу: C:\\ Users\\danac\\AppData\\Local\\Temp\\15cffdf7-be33-4656-a3d5-0b85efa81caa.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\2c694397 - 4fa8 - 4c85 - a725 - a54e5e338d0a.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\47657536 - 1b08 - 49cf - bdba - 97c9d16a3510.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\9696b143 - c8c9 - 4081 - ad21 - 089416937ad0.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\983b9503 - 0e83 - 45fa - 82c9 - b0839458bb24.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\9f615a5e - 0dd1 - 491e-8b51 - 2efd30fb4040.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\acb74e39 - ac23 - 49d9 - 9a21 - 0346971aa51f.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\aria - debug - 12700.log \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\aria - debug - 3924.log \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\b640e4bb - ff33 - 457b - 89b3 - eb9f846e45a3.tmp \r\nВидалено файлів: 16";
	   LPCWSTR to_write = L"Шлях до директорії: C:\\Users\\danac\\AppData\\Local\\Temp\\ \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\n \r\nВидалення файлу: C:\\ Users\\danac\\AppData\\Local\\Temp\\15cffdf7-be33-4656-a3d5-0b85efa81caa.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\2c694397 - 4fa8 - 4c85 - a725 - a54e5e338d0a.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\47657536 - 1b08 - 49cf - bdba - 97c9d16a3510.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\9696b143 - c8c9 - 4081 - ad21 - 089416937ad0.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\983b9503 - 0e83 - 45fa - 82c9 - b0839458bb24.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\9f615a5e - 0dd1 - 491e-8b51 - 2efd30fb4040.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\acb74e39 - ac23 - 49d9 - 9a21 - 0346971aa51f.tmp \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\aria - debug - 12700.log \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\aria - debug - 3924.log \r\nВидалення файлу : C:\\Users\\danac\\AppData\\Local\\Temp\\b640e4bb - ff33 - 457b - 89b3 - eb9f846e45a3.tmp \r\nВидалено файлів: 935 \r\nОчищено 137 мб (0,212%)";
   
   SendMessage(textOut, WM_SETTEXT, 0, (LPARAM)to_write);
   SendMessage(textOut, WM_SETFONT, (WPARAM)hFont, 0L);

   HWND progressBar = CreateWindowEx(
       0,
       PROGRESS_CLASS, (LPTSTR)NULL,
       WS_CHILD | WS_VISIBLE,
       1000, //x
       500, // y
       100, // width
       20, // height
       hWnd, 
       (HMENU)PROGRESS_BAR, 
       (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
       NULL);


   SendMessage(progressBar, PBM_SETRANGE, 0, MAKELPARAM(0, 2));

   SendMessage(progressBar, PBM_SETSTEP, (WPARAM)1, 0);
   
   SendMessage(progressBar, PBM_STEPIT, 0, 0);
    
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            
            LPCWSTR describeText = L"DESCRIBE #13";

            TextOut(hdc, 550, 350, describeText, wcslen(describeText));


            LPCWSTR resultText = L"All time: 1488MB \r\nLast time: 228MB";
            RECT rect;
            rect.left = 750; //x
            rect.top = 350; //y
            rect.right = rect.left + 200; //width
            rect.bottom = rect.top + 100; // height
            DrawText(hdc, resultText, wcslen(resultText), &rect, DT_WORDBREAK);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

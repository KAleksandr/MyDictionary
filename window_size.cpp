#include <windows.h>
//#include <conio.h>
//#include <iostream>
#include "window_size.h"
//using namespace std;

//Без можливості змінити розмір консолі
/*
void window_size2()
{
    //функцію GetLargestConsoleWindowSize , витягує розмір найбільшого можливого консольного вікна,
    //заснованого на поточному шрифті та розмірі дисплея.
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD crd = {65, 35};
        SMALL_RECT src = {0, 0, crd.X-1, crd.Y-1};
        SetConsoleWindowInfo (out_handle, true, &src);
        SetConsoleScreenBufferSize (out_handle, crd);
//-----------------------------------------------------------
        //получаем дескриптор
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        //Выводим текст разными цветами
        SetConsoleTextAttribute(hStdOut, 2);
}
*/
//Без можливості змінити розмір консолі
#include  <stdio.h>
#include  <windows.h>
void window_size()
{
  HWND hWnd;
  HMENU hm;
  if ((hWnd = GetConsoleWindow ()) == NULL)
  {
    printf ("No console window!? \n");
    return;
  }
  hm = GetSystemMenu (hWnd, FALSE);
  RemoveMenu (hm, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);
  RemoveMenu (hm, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);
  DrawMenuBar (hWnd);

}

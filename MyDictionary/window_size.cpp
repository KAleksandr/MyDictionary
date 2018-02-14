#include <windows.h>
//#include <conio.h>
//#include <iostream>
#include "window_size.h"
//using namespace std;

//��� ��������� ������ ����� ������
// No ability to change the size of the console
/*
void window_size2()
{
    //������� GetLargestConsoleWindowSize , ������ ����� ���������� ��������� ����������� ����,
    //����������� �� ��������� ����� �� ����� �������.
    // the GetLargestConsoleWindowSize function, extracts the size of the largest possible console window,
     // based on the current font and size of the display.
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD crd = {65, 35};
        SMALL_RECT src = {0, 0, crd.X-1, crd.Y-1};
        SetConsoleWindowInfo (out_handle, true, &src);
        SetConsoleScreenBufferSize (out_handle, crd);
//-----------------------------------------------------------
        //�������� ����������
        // get a handle
        HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
        //�������� ����� ������ ���������
        // We print the text in different colors
        SetConsoleTextAttribute(hStdOut, 2);
}
*/
//��� ��������� ������ ����� ������
// No ability to change the size of the console
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

#include <iostream>
#include <windows.h>
#include "error_open.h"
using namespace std;

void error_open(){
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hStdOut, 4);
    cout << "\n\n\n\t\tDictionary isn't found!!!\n\n";
    SetConsoleTextAttribute(hStdOut, 7);
    cout << "\t\tNew dictionary creating... Ok\n\n";
    SetConsoleTextAttribute(hStdOut, 2);
    cout << "\tYou can only found  words what you add new.\n";
    cout  << "\tAlso you can write down it to dictionary.\n\n\n";
}

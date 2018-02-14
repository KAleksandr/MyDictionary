#ifndef ABOUT_H
#define ABOUT_H
#include<windows.h>
#include <iostream>

using namespace std;
void info(){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, 1);
       cout << "  /************************************************\\" <<endl;
       cout << "  *            Aleksandr Kuzmenko                   *"<<endl;
       cout << "  *                 02/13/2018                      *"<<endl;
       cout << "  *                                                 *"<<endl;
       cout << "  *                 IT ACADEMY                      *"<<endl;
       cout << "  *               PROGRAM FUTURE!                   *"<<endl;
       cout << "  *                                                 *"<<endl;
       cout << "  *   Course: Algorithmization and                  *"<<endl;
       cout << "  *           programming in the language of C.     *"<<endl;
       cout << "  *           Date:   Tuesday 13nd February 2018    *"<<endl;
       cout << "  *                                                 *"<<endl;
       cout << "  *   A program that searches for a word in a       *"<<endl;
       cout << "  *   dictionary.                                   *"<<endl;SetConsoleTextAttribute(hStdOut, 14);
       cout << "  *     - Create a dictionary of strings            *"<<endl;
       cout << "  *     - Translation in two directions             *"<<endl;
       cout << "  *     - Create an interface for user to search    *"<<endl;
       cout << "  *       for a word in the dictionary              *"<<endl;
       cout << "  *                                                 *"<<endl;
       cout << "  *       If the word is not found, the word        *"<<endl;
       cout << "  *       is added to the dictionary.               *"<<endl;
       cout << "  *       The dictionary has 3000+ words            *"<<endl;
       cout << "  *                  (English/Ukraine)              *"<<endl;
       cout << "  *                    Version 2.1                  *"<<endl;
       cout << "  \\************************************************/"<<endl;
       SetConsoleTextAttribute(hStdOut, 2);
       system("pause");
}
#endif // ABOUT_H

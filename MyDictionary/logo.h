#ifndef LOGO_H
#define LOGO_H
#include<windows.h>
#include <iostream>
#include "color.h"
using namespace std;
void logo(){
    cout << "\t\t    ";
    flagUa();
    cout <<"\n\n\n\n\n\n";
    colorText("\t\t    MyDictionary ver 2.2\n\n\n\n\n");

    /*
       __                __
      / /  _____  ____  / /_
     / /_ /  __ \/ __ \/ __/
    / /_\\\ / /_/ / /_/ /__
    \____/ \____/\____/\__/
    */
    Sleep(2000);
}


#endif // LOGO_H

#include <iostream>
#include <windows.h>
#include "color.h"
using namespace std;

void colorText(char buffer[]){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, 7);
    cout << buffer << endl;
    SetConsoleTextAttribute(hStdOut, 2);

}
void colorText(string buffer){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, 7);
    cout << buffer << endl;
    SetConsoleTextAttribute(hStdOut, 2);
}
void colorTextW(string buffer){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, 7);
    cout << buffer;
    SetConsoleTextAttribute(hStdOut, 2);
}
void colorTextR(string buffer){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, 4);
    cout << buffer << endl;
    SetConsoleTextAttribute(hStdOut, 2);
}
void logoText(bool typeDic){

    string en = "\t   Mode: English - Ukrainian dictionary \n\t(search is done according to English word)";
    string ua = "\t   Режим: Українсько-английский словник \n\t(пошук здійснюється по українському слову)";
    string numberEn = "\t Number of words in the dictionary: ";
    string numberUa = "\t Кількість слів у словнику: ";
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
       if(typeDic){
        SetConsoleTextAttribute(hStdOut, 7);
        cout << endl << en << endl;
        cout << numberEn << i << endl;
        SetConsoleTextAttribute(hStdOut, 2);
    }
    else{
        SetConsoleTextAttribute(hStdOut, 7);
        cout << endl << ua << endl;
        cout << numberUa << i << endl;
        SetConsoleTextAttribute(hStdOut, 2);
    }

}
void flagUa(){
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut,
    BACKGROUND_BLUE | BACKGROUND_INTENSITY |
    FOREGROUND_RED | FOREGROUND_GREEN |
    FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    string str1 = " English-Ukrainian dictionary";
    string str2 = " Українсько-англійський словник";
    cout << "\n\t    "<< "       " ;
    colorText(str1);
    SetConsoleTextAttribute(hStdOut,
//                            цветом текста управляет всего 4 бита, из которых мы можем
//                            получить 16 разных комбинаций.
    BACKGROUND_INTENSITY|BACKGROUND_RED | BACKGROUND_GREEN |//BACKGROUND yellow
    FOREGROUND_RED | FOREGROUND_GREEN |
    FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Text white
    cout << "\t    "<< "       ";
    colorText(str2);
    SetConsoleTextAttribute(hStdOut, 2);
}



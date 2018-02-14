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
    string ua = "\t   �����: ���������-���������� ������� \n\t(����� ����������� �� ����������� �����)";
    string numberEn = "\t Number of words in the dictionary: ";
    string numberUa = "\t ʳ������ ��� � ��������: ";
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
    string str2 = " ���������-���������� �������";
    cout << "\n\t    "<< "       " ;
    colorText(str1);
    SetConsoleTextAttribute(hStdOut,
//                            ������ ������ ��������� ����� 4 ����, �� ������� �� �����
//                            �������� 16 ������ ����������.
    BACKGROUND_INTENSITY|BACKGROUND_RED | BACKGROUND_GREEN |//BACKGROUND yellow
    FOREGROUND_RED | FOREGROUND_GREEN |
    FOREGROUND_BLUE | FOREGROUND_INTENSITY);//Text white
    cout << "\t    "<< "       ";
    colorText(str2);
    SetConsoleTextAttribute(hStdOut, 2);
}



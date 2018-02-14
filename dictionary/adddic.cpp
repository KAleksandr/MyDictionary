#include <iostream>
#include "time_chrono.h"
#include <fstream>
#include <string.h>
#include <cctype>
#include <conio.h>
#include <cstdlib>//��� ������� exit
#include "error_open.h"
#include "color.h"
#include "hash.h"
#include "about.h"
using namespace std;
bool found;//��������� ����������� �����
bool menuRun(char buffer[], char buffer2[], bool typeDic);
void addWord(char buffer[], char buffer2[],bool typeDic);
void translation(char buffer[], char buffer2[],bool typeDic);
void AddWords(char buffer[], char buffer2[],bool typeDic);
int i=0;
int flag=0;
struct node
{
    size_t hashEn;
    size_t hashUa;
    char uaWord[50];
    char engWord[50];
    node *left, *right;
};

node * root = NULL;



void addDic(char uaWord[], char engWord[])//����� ����� � ����(��������)
{
    ofstream file("dictionary.txt",ios_base::app);//������� � ����� �����
    file  << endl << engWord <<' ';
    file << uaWord ;
    file.close();

}

void createNode(char uaWord[], char engWord[], node **tree)
{
    size_t hashEn;
    size_t hashUa;

    hashEn = hashWord(engWord);
    hashUa = hashWord(uaWord);

    if ((*tree) == NULL) // ��������� �����
    {
        i++;
        (*tree) = new node;
        (*tree)->hashEn= hashEn;
        (*tree)->hashUa= hashUa;
        strcpy((*tree)->engWord, engWord);
        strcpy((*tree)->uaWord, uaWord);
        (*tree)->left = (*tree)->right = NULL;
        return;
    }

    if ((*tree)->hashEn > hashEn)//(���������)
        createNode(uaWord, engWord, &(*tree)->right); // to right ���� >0
    else
        createNode(uaWord, engWord, &(*tree)->left);//  to left if <0
}

// ������� found = true ���� �������� ����� � �������� � false ���� � (��� �������� �� ��� ��������� new word)
void find(node *tree, bool typeDic, char findWord[])//����� �����
{
    start_chrono();//start �������� ����
    size_t hashT;

        hashT =hashWord(findWord);

   if (tree == NULL) return;
    else
    {
        if (!found)
            find(tree->left, typeDic, findWord);
        else
            return;
        if (typeDic)
        {
            if (tree->hashEn == hashT)
            {
                colorText("\n\t   Word        Translation");
                cout << "\n\t    "<< tree->engWord << "    -    "; //Output on screen
                colorText(tree->uaWord);
                found = true;
                cout << "\n\n\t\ttime: " << elapsed() << endl;
                return;

            }
        }
        else
            if (tree->hashUa == hashT)
            {
                colorText("\n\t   �����        ��������");
                cout << "\n\t   "<< tree->uaWord <<   "   -   "; //
                colorText(tree->engWord);
                found = true;
                cout << "\n\n\t\ttime: " << elapsed() << endl;
               return;

        }
    }
    if (!found)
        find(tree->right, typeDic, findWord);
    else
        return;

}

void Load(node **tree)//������������ � ����� ���
{
    int max_lenght=1024;
    char buffer[50];
    char buffer2[max_lenght];


    ifstream file("dictionary.txt");
    if (!file.is_open()){ // ���� ���� �� ��������
           // ��������� ��� ��
           file.open("dictionary.txt", ios_base::out| ios_base::trunc);//���� ���������
            error_open();

            system("pause");
                   //getch();
    }

    while (!file.eof())
    {
        file >> buffer;
        //file >> engWordT;
        char ch; file.get(ch);//��������� ������ �� �����
        file.getline(buffer2, max_lenght);
        if (strlen(buffer)>0)
            createNode(buffer2, buffer, tree);


    }
    file.close();
}


void menu(){
    bool typeDic = true;//�� ���������� English

    char buffer[30] ,buffer2[30];
    Load(&root);
    while (true)
    {
            system("cls");//������� ������
        if (typeDic){
            logoText(typeDic);
            colorText("\n\n\t\tSelect an action");
            cout << "\t\t1. Translation" << endl;
            cout << "\t\t2. Add a word" << endl;
            cout << "\t\t3. Change the Language of the menu " << endl;
            cout << "\t\t4. About MyDictionary"<< endl;
            cout << "\t\t0. Exit" << endl;

        }
        else{
            logoText(typeDic);
            colorText("\n\n\t\t������� ��");
            cout << "\t\t1. ��������" << endl;
            cout << "\t\t2. ������ �����" << endl;
            cout << "\t\t3. ������ ���� ���������" << endl;
            cout << "\t\t4. ��� MyDictionary"<< endl;
            cout << "\t\t0. �����" << endl;
        }
       typeDic = menuRun(buffer, buffer2,typeDic);//������� ������ ����
    }
}

bool menuRun(char buffer[], char buffer2[], bool typeDic){

    int menu,count=0;
    do{
        char c;
        cout <<'\t';
        cin >> c;
        menu = c - '0';
         if(!(isdigit(c)) || menu >4){//�������� �� �������� �������
             colorTextR("\t\tError of choice!");
            count++;
        }
         if(count==5)
             menu=0;
    }
    while(!(menu>=0 && menu <=4));

 system("cls");//������� ������
    switch (menu)
    {
    case 1:
        if (typeDic){
            while(1){
                translation(buffer,buffer2,typeDic);
                 colorText("\n\t\tTranslation next (y/n)?");
                char c = getch();
                if(!(c == 'y' || c == 'Y'))
                    break;
                system("cls");//������� ������
            }
        }
        else{
            while(1){
                translation(buffer,buffer2,typeDic);
                colorText("\n\t\t��������� �������� (y/n)?");
                char c = getch();
                if(!(c == 'y' || c == 'Y'))
                    break;
                system("cls");//������� ������
            }
        }

        break;
    case 2:
        if (typeDic){
            while (1) {
                flag =0;
                if (typeDic)
                {
                    AddWords(buffer, buffer2, typeDic);

                    colorText("\n\t\tIs add next word (y/n)?");
                    char c = getch();
                    if(!(c == 'y' || c == 'Y'))
                        break;
                    system("cls");//������� ������
                }
}
        }
        else{
            while (1) {
                addWord(buffer, buffer2, typeDic);
                colorText("\n\t\t������ �������� ����� (y/n)?");
                char c = getch();
                if(!(c == 'y' || c == 'Y'))
                    break;
                system("cls");//������� ������
            }
        }
        break;
    case 3://the change on Ukraine
        typeDic = !(typeDic);
        break;
    case 4:
        info();
        break;
    case 0:
            break;
         default:
        colorTextR("������� ������");
            getch( ) ;
            break;
        }
    if (menu == 0){
        flagUa();
        colorText("\n\n\n\n\n\t\t\tG o o d b a y!\n\n\n\n");
        cout <<"\n\n\n";
        colorText("\t\t    MyDictionary ver 2.1\n\n\n\n\n");
        exit(1);

    }
    return typeDic;
}
void translation(char buffer[], char buffer2[],bool typeDic){

    if (typeDic)
        {
        logoText(typeDic);
        cout << "\n\n\t\tEnter word:  ";
        cin >> buffer;//������ �����
        found = false;
        find(root, typeDic, buffer);
        if (!found){
            colorTextR("\n\t\tTranslation not found.");
                cout << "\a";
            colorText("\n\t\tAdd word (y/n)? ");
            char c=getch();
            if(c == 'y' || c == 'Y'){// add word
                addWord(buffer, buffer2, typeDic);
            }
        }

    }
    else{
        logoText(typeDic);
        cout << "\n\n\t\t������ ����� ";
        cin >>  buffer2;
        found = false;
        find(root, typeDic, buffer2);
        if (!found){
            colorTextR("\n\n\t\t�������� �� ���������.");
             cout << "\a";
            colorText("\n\t\t������ ����� (y/n)? ");
            char c=getch();
            if(c == 'y' || c == 'Y' || c == '�'){// add word
                addWord(buffer, buffer2, typeDic);
            }
        }
    }
}
void addWord(char buffer[], char buffer2[],bool typeDic){

    if (typeDic)
    {
        cout << "\n\n\t\tAdd a word:" <<endl;
        colorTextW( "\tEnter word (Eng) ");
        cout << buffer;
        colorTextW("\nEnter the translator (Uk) ");
        fflush(stdin);
        gets(buffer2);
    }
    else
    {
        cout << "\n\n\t\t������ �����:" <<endl;
        colorTextW("\t������ ����� (ua)     ");
        cin >> buffer2;
        colorTextW("\t ������ �������� (Eng) ");
            cin >> buffer;
    }

        createNode(buffer2, buffer,&root);
        addDic(buffer2, buffer);


}
void AddWords(char buffer[], char buffer2[],bool typeDic){
    char engWordT[50];
       if (typeDic)
        {
        logoText(typeDic);
        cout << "\n\n\t\tAdd a word:" <<endl;
        colorTextW( "\t       Enter word (Eng) ");
        cin >> buffer;//������ �����

        colorTextW("\nEnter a transcription: ");
        fflush(stdin);
        gets(engWordT);
        found = false;
        find(root, typeDic, buffer);
        if (!found){
            colorTextW("      Enter the translator (Uk) ");
            fflush(stdin);
            gets(buffer2);
            colorText("\n\t\tAdd word (y/n)? ");
            char c=getch();
            if(c == 'y' || c == 'Y'){// add word
                addWord(buffer, buffer2, typeDic);
            }
        }
        else{
            colorTextR("\t\tThis word is in the dictionary.");
             cout << "\a";
        }

    }
    else{
        logoText(typeDic);
        cout << "\n\n\t\t������ �����:" <<endl;
        colorTextW("\t������ ����� (ua)     ");
        //cin >>  buffer2;
        gets(buffer2);
        found = false;
        find(root, typeDic, buffer2);
        if (!found){
            colorTextW("      ������ �������� (Eng) ");
             cin >> buffer;
            colorText("\n\t\t������ ����� (y/n)? ");
            char c=getch();
            if(c == 'y' || c == 'Y' || c == '�'){// add word
                addWord(buffer, buffer2, typeDic);
            }
        }
        else{
            colorTextR("\t\t�� ����� � � ��������.");
             cout << "\a";
        }

    }
    if (!found){
    createNode(buffer2, buffer, &root);
    addDic(buffer2, buffer);
    }
}

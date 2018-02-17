#include <iostream>
#include "time_chrono.h"
#include <ctime>//TIME
#define ESC 27
#include "error_open.h"
#include "about.h"
#include "treeoption.h"
using namespace std;
bool found;//��������� ����������� ����� //the result of finding the word

int i=0;//count words
int iter=0;
int flag=0;

node * root = NULL;
void show(node *tree);
void del(node *tree);

//create a new node for a tree
void createNode(char uaWord[], char engWord[], node **tree)
{
    size_t hashEn;
    size_t hashUa;

    hashEn = hashWord(engWord);//create hash number word
    hashUa = hashWord(uaWord);

    if ((*tree) == NULL) // ��������� �����
    {
        i++;//count word count in dictionary
        (*tree) = new node;
        (*tree)->hashEn= hashEn;//has number word Eng
        (*tree)->hashUa= hashUa;//has number word Ua
        strcpy((*tree)->engWord, engWord);
        strcpy((*tree)->uaWord, uaWord);
        (*tree)->left = (*tree)->right = NULL;
        return;
    }

    if ((*tree)->hashEn > hashEn)//(���������)
        createNode(uaWord, engWord, &(*tree)->right); // to right if >
    else if((*tree)->hashEn == hashEn){//������� �� �������� � ��������
        return;
    }
    else
        createNode(uaWord, engWord, &(*tree)->left);//  to left if <
}


void Load(node **tree)//download from the word file
{
    int max_lenght=1024;
    char buffer[50];
    char buffer2[max_lenght];


    ifstream file("dictionary.txt");
    if (!file.is_open()){ // ���� ���� �� ��������//if the file is not open
           // ��������� ��� ��//report it
           file.open("dictionary.txt", ios_base::out| ios_base::trunc);//���� ���������//// will be created
            error_open();

            system("pause");
                   //getch();
    }

    while (!file.eof())
    {
        file >> buffer;
        char ch; file.get(ch);//������ ������ ����� �� �����!!!//Read the character space from the file !!!
        file.getline(buffer2, max_lenght);
        if (strlen(buffer)>0)
            createNode(buffer2, buffer, tree);


    }
    file.close();
}

//menu
void menu(){
    bool typeDic = true;//by default English

    char buffer[30] ,buffer2[30];
    Load(&root);
    while (true)
    {
            system("cls");//������� ������//cleaning the screen
        if (typeDic){
            logoText(typeDic);
            colorText("\n\n\t\tSelect an action");
            cout << "\t\t1. Translation" << endl;
            cout << "\t\t2. Add a word" << endl;
            cout << "\t\t3. Change the Language of the menu " << endl;
            cout << "\t\t4. Options"<< endl;
            //cout << "\t\t5. Find substrings"<< endl;
            cout << "\t\t0. Exit" << endl;

        }
        else{
            logoText(typeDic);
            colorText("\n\n\t\t������� ��");
            cout << "\t\t1. ��������" << endl;
            cout << "\t\t2. ������ �����" << endl;
            cout << "\t\t3. ������ ���� ���������" << endl;
            cout << "\t\t4. ���������" <<endl;
            //cout << "\t\t5. ����� ��������"<< endl;
            cout << "\t\t0. �����" << endl;
        }
       typeDic = menuRun(buffer, buffer2,typeDic);//������� ������ ����//processing menu request
    }
}
//performing menu actions
bool menuRun(char buffer[], char buffer2[], bool typeDic){
    int menu,count=0;
    do{
        char c;
        cout <<"\n\t\t";
        cin >> c;
        menu = c - '0';
         if(!(isdigit(c)) || menu >4){//�������� �� �������� �������//checking for a team entry
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

                iter=0;
               translationFast(buffer,buffer2,typeDic);
                cout << "\t\tcount iteration: "<< iter<< endl;
                colorTextW("\n\t\tTranslation next (y/n)?");
                char c = getch();
                if(!(c == 'y' || c == 'Y'))
                    break;
                system("cls");//������� ������
            }
        }
        else{
            while(1){
               // iter=0;
                //translation(buffer,buffer2,typeDic);

                iter=0;
                translationFast(buffer,buffer2,typeDic);
                cout << "\t\tʳ������ ��������: "<< iter<< endl;
                colorTextW("\n\t\t��������� �������� (y/n)?");
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
                //if (typeDic)
                //{
                    AddWords(buffer, buffer2, typeDic);

                    colorText("\n\t\tIs add next word (y/n)?");
                    char c = getch();
                    if(!(c == 'y' || c == 'Y'))
                        break;
                    system("cls");//������� ������
                //}
            }
        }
        else{
            while (1) {
                //flag =0;
               // if (typeDic)
                //{
                    AddWords(buffer, buffer2, typeDic);
                colorText("\n\t\t������ �������� ����� (y/n)?");
                char c = getch();
                if(!(c == 'y' || c == 'Y'))
                    break;
                system("cls");//������� ������
               // }
            }
        }
        break;
    case 3://the change on Ukraine
        typeDic = !(typeDic);
        break;
    case 4:
        Options(typeDic);
        //show(root);
        //system("pause");
        break;
    case 5:
        //todo
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
        del(root);
        exit(1);

    }
    return typeDic;
}


//menu
void Options(bool typeDic){
    system("cls");//������� ������//cleaning the screen
    while (true){
        if(typeDic){
            logoText(typeDic);
            colorTextB("\n\t\tOPTIONS");
            colorText("\n\n\t\tSelect an action:");
            cout << "\t\t1. �omparison of search functions" << endl;
            cout << "\t\t2. Save to file" << endl;
            cout << "\t\t3. About MyDictionary" << endl;
            cout << "\t\t4. �ome back" << endl;
        }
        else{
            logoText(typeDic);
            colorTextB("\n\t\t���������");
            colorText("\n\n\t\t������� ��:");
            cout << "\t\t1. ��������� ������� ������" << endl;
            cout << "\t\t2. �������� � ����" << endl;
            cout << "\t\t3. ��� MyDictionary" << endl;
            cout << "\t\t4. �����������" << endl;
        }
        optionRun(typeDic);
    }
}
void optionRun(bool typeDic){
     int menuN,count=0;
     char buffer[30] ,buffer2[30];
     do{
        char c;
        cout <<"\n\t\t";
        cin >> c;
        menuN = c - '0';
         if(!(isdigit(c)) || menuN >4){//�������� �� �������� �������//checking for a team entry
             colorTextR("\t\tError of choice!");
            count++;
        }
         if(count==5)
             menuN=4;
    }
      while(!(menuN>0 && menuN <=4));
       system("cls");//������� ������
       switch (menuN)
       {
           case 1:
               while(1){

                   //iter=0;
                   compareFind(buffer,buffer2,typeDic);
                   //cout << "\t\tcount iteration: "<< iter<< endl;
                   colorTextW("\n\t\tTranslation next (y/n)?");
                   char c = getch();
                   if(!(c == 'y' || c == 'Y'))
                       break;
                   system("cls");//������� ������
               }
            system("cls");//������� ������
           break;
           case 2: {//���� ��������� will be created//save to the file
                 ofstream outFile("dictionaryB.txt",ios_base::out| ios_base::trunc);
                treePrint(root, outFile);
                colorText("\tThe record is complete.");
                system("pause");
                system("cls");//������� ������
                outFile.close();
               break;
            }
           case 3: info();
           system("cls");//������� ������//cleaning the screen
               break;
           case 4:menu();
               break;
       }

}

//searching words in dictionary
double translation(char buffer[], char buffer2[],bool typeDic){
    double time;
    if (typeDic)
        {
        logoText(typeDic);
        cout << "\n\n\t\tEnter word:  ";
        SetColor(9,14);
        cin >> buffer;//������ �����//read the word
        found = false;
        start_chrono();

        find(root, typeDic, buffer);
        time =elapsed();
        cout << "\n\n\t\tSearch time chrono: " << elapsed() << endl;//���� ����

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
        cout << "\n\n\t\t������ �����: ";
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
    return time;
}

//I use when not found word during translation
void addWord(char buffer[], char buffer2[],bool typeDic){

    if (typeDic)
    {
        cout << "\n\n\t\tAdd a word:" <<endl;
        colorTextW( "\t Enter word (Eng) ");
        cout << buffer;
        colorTextW("\nEnter the translator (Uk) ");
        fflush(stdin);
        gets(buffer2);
    }
    else
    {
        cout << "\n\n\t\t������ �����:" <<endl;
        colorTextW("\t    ������ ����� (Uk)   ");
        fflush(stdin);
        cout << buffer<<endl;
        colorTextW("\t������ �������� (Eng)   ");
            cin >> buffer2;
    }

        createNode(buffer2, buffer,&root);
        addDic(buffer2, buffer);


}
//adding words with menu
void AddWords(char buffer[], char buffer2[],bool typeDic){

       if (typeDic)
        {
        logoText(typeDic);
        cout << "\n\n\t\tAdd a word:" <<endl;
        colorTextW( "\t       Enter word (Eng) ");
        cin >> buffer;//������ �����
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
        colorTextW("\t\t������ ����� (Ua)     ");
        cin >>  buffer2;
        //gets(buffer2);
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
//����� �� �������� fundHash �������
double translationFast(char buffer[], char buffer2[],bool typeDic){
    double timeFast;
    if (typeDic)
        {
        logoText(typeDic);
        cout << "\n\n\t\tEnter word:  ";
        cin >> buffer;//������ �����//read the word
        found = false;

        start_chrono();
        findHash(root, typeDic, buffer); //Sleep(1000);
        colorTextB("\n\n\t\tFast search time (mls): ");
        timeFast = elapsed();
        cout<< elapsed() << endl;//���� ����

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
    //����� ���������� �� ���, ��� �� ���� ��� ���
    else{
        logoText(typeDic);
        cout << "\n\n\t\t������ �����: ";
        cin >>  buffer2;
        found = false;
        start_chrono();
        find(root, typeDic, buffer2);
        colorTextB("\n\n\t\tFast search time (mls): ");
        timeFast = elapsed();
        cout<< elapsed() << endl;//���� ����
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
    return timeFast;
}

//Comparison of search functions//��������� ������� ������
double compareFind(char buffer[], char buffer2[],bool typeDic){
    double timeFast;
        logoText(typeDic);
        colorTextB("\t\tCOMPARISON OF SEARCH FUNCTIONS");
        cout << "\n\t\tEnter word:  ";
        cin >> buffer;//������ �����//read the word
 //---------------------------------------------------------
        iter=0;
        found = false;
        colorText("\t\tSearch by hash (comparison): ");
        start_chrono();
        findHash(root, typeDic, buffer); //Sleep(1000);
        timeFast = elapsed();
        colorTextB("\n\n\t\tSearch time (mls): ");
        cout<< elapsed() << endl;//���� ����
         cout << "\t\tcount iteration: "<< iter<< endl;
        colorTextB("\t---------------------------------------------");cout <<endl;
 //---------------------------------------------------------
        iter=0;
        found = false;
        colorText("\tSearch by hash (In-order):");
        start_chrono();
        find(root, typeDic, buffer);
        timeFast = elapsed();
        colorTextB("\n\n\t\tSearch time (mls): ");
        cout<< elapsed() << endl;//���� ����
        cout << "\t\tcount iteration: "<< iter<< endl;
        colorTextB("\t---------------------------------------------");cout <<endl;
 //---------------------------------------------------------
        iter=0;
        found = false;
        colorText("\tSearch by word (In-order):");
        start_chrono();
        findW(root, typeDic, buffer);
        timeFast = elapsed();
        colorTextB("\n\n\t\tSearch time (mls): ");
        cout<< elapsed() << endl;//���� ����
        cout << "\t\tcount iteration: "<< iter<< endl;
        colorTextB("\t---------------------------------------------");cout <<endl;
 //---------------------------------------------------------
        if (!found){
            colorTextR("\n\t\tTranslation not found.");
            cout << "\a";
            colorText("\n\t\tAdd word (y/n)? ");
            char c=getch();
            if(c == 'y' || c == 'Y'){// add word
                addWord(buffer, buffer2, typeDic);
            }
        }
    return timeFast;
}



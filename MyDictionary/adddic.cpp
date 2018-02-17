#include <iostream>
#include "time_chrono.h"
#include <ctime>//TIME
#include <fstream>
#include <string.h>
#include <cctype>
#include <conio.h>
#include <cstdlib>//for exit
#include "error_open.h"
//#include "color.h"
//#include "hash.h"
#include "about.h"
#include "treeoption.h"
using namespace std;
bool found;//результат знаходження слова //the result of finding the word
bool menuRun(char buffer[], char buffer2[], bool typeDic);
void addWord(char buffer[], char buffer2[],bool typeDic);
double translation(char buffer[], char buffer2[],bool typeDic);
double translationFast(char buffer[], char buffer2[],bool typeDic);
void AddWords(char buffer[], char buffer2[],bool typeDic);
void menu();
void optionRun();


int i=0;//count words
int iter=0;
int flag=0;
//struct node
//{
//    size_t hashEn;
//    size_t hashUa;
//    char uaWord[50];
//    char engWord[50];
//    node *left, *right;
//};

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

    if ((*tree) == NULL) // створюємо вузол
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

    if ((*tree)->hashEn > hashEn)//(порівняння)
        createNode(uaWord, engWord, &(*tree)->right); // to right if >
    else if((*tree)->hashEn == hashEn){//відкидаю всі дублікати в словнику
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
    if (!file.is_open()){ // якщо файл не відкритий//if the file is not open
           // повідомити про це//report it
           file.open("dictionary.txt", ios_base::out| ios_base::trunc);//буде створений//// will be created
            error_open();

            system("pause");
                   //getch();
    }

    while (!file.eof())
    {
        file >> buffer;
        //file >> engWordT;
        char ch; file.get(ch);//Зчитую символ пробіл із файла!!!//Read the character space from the file !!!
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
            system("cls");//очистка екрану//cleaning the screen
        if (typeDic){
            logoText(typeDic);
            colorText("\n\n\t\tSelect an action");
            cout << "\t\t1. Translation" << endl;
            cout << "\t\t2. Add a word" << endl;
            cout << "\t\t3. Change the Language of the menu " << endl;
            cout << "\t\t4. Options"<< endl;
            cout << "\t\t5. Find substrings"<< endl;
            cout << "\t\t0. Exit" << endl;

        }
        else{
            logoText(typeDic);
            colorText("\n\n\t\tВиберіть дію");
            cout << "\t\t1. Переклад" << endl;
            cout << "\t\t2. Додати слово" << endl;
            cout << "\t\t3. Змінити мову перекладу" << endl;
            cout << "\t\t4. Параметри" <<endl;
            cout << "\t\t5. Пошук підстроки"<< endl;
            cout << "\t\t0. Вихід" << endl;
        }
       typeDic = menuRun(buffer, buffer2,typeDic);//обробка запиту меню//processing menu request
    }
}
void Options(bool typeDic){
    system("cls");//очистка екрану//cleaning the screen
    while (true){
        if(typeDic){
            logoText(typeDic);
            colorTextB("\n\t\tOPTIONS");
            colorText("\n\n\t\tSelect an action:");
            cout << "\t\t1. Save to file" << endl;
            cout << "\t\t2. About MyDictionary" << endl;
            cout << "\t\t3. Сome back" << endl;
        }
        else{
            logoText(typeDic);
            colorTextB("\n\t\tПАРАМЕТРИ");
            colorText("\n\n\t\tВиберіть дію:");
            cout << "\t\t1. Зберегти у файл" << endl;
            cout << "\t\t2. Про MyDictionary" << endl;
            cout << "\t\t3. Повернутись" << endl;
        }
        optionRun();
    }
}
void optionRun(){
     int menuN,count=0;
     do{
        char c;
        cout <<"\n\t\t";
        cin >> c;
        menuN = c - '0';
         if(!(isdigit(c)) || menuN >3){//перевірка на введення команди//checking for a team entry
             colorTextR("\t\tError of choice!");
            count++;
        }
         if(count==5)
             menuN=3;
    }
      while(!(menuN>0 && menuN <=3));
       system("cls");//очистка екрану
       switch (menuN)
       {
           case 1: {//буде створений will be created//save to the file
                 ofstream outFile("dictionaryB.txt",ios_base::out| ios_base::trunc);
                treePrint(root, outFile);
                colorText("\tThe record is complete.");
                system("pause");
                system("cls");//очистка екрану
                outFile.close();
               break;
            }
           case 2: info();
           system("cls");//очистка екрану//cleaning the screen
               break;
           case 3:menu();
               break;
       }

}
//performing menu actions
bool menuRun(char buffer[], char buffer2[], bool typeDic){
    double time;
    double timeFast;
    int menu,count=0;
    do{
        char c;
        cout <<"\n\t\t";
        cin >> c;
        menu = c - '0';
         if(!(isdigit(c)) || menu >5){//перевірка на введення команди//checking for a team entry
             colorTextR("\t\tError of choice!");
            count++;
        }
         if(count==5)
             menu=0;
    }
    while(!(menu>=0 && menu <=5));

 system("cls");//очистка екрану
    switch (menu)
    {
    case 1:
        if (typeDic){
            while(1){
                iter=0;
                time = translation(buffer,buffer2,typeDic);
                cout << "\t\tcount iteration: "<< iter<< endl;
                iter=0;
               timeFast = translationFast(buffer,buffer2,typeDic);
                cout << "\t\tcount iteration: "<< iter<< endl;
                colorTextW("\t\tTime difference: ");
                cout <<  (time - timeFast) <<endl;
                colorTextW("\n\t\tTranslation next (y/n)?");
                char c = getch();
                if(!(c == 'y' || c == 'Y'))
                    break;
                system("cls");//очистка екрану
            }
        }
        else{
            while(1){
                iter=0;
                translation(buffer,buffer2,typeDic);
                cout << "\t\tcount iteration: "<< iter<< endl;
                iter=0;
                translationFast(buffer,buffer2,typeDic);
                cout << "\t\tcount iteration: "<< iter<< endl;
                colorTextW("\n\t\tНаступний переклад (y/n)?");
                char c = getch();
                if(!(c == 'y' || c == 'Y'))
                    break;
                system("cls");//очистка екрану
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
                    system("cls");//очистка екрану
                }
}
        }
        else{
            while (1) {
                addWord(buffer, buffer2, typeDic);
                colorText("\n\t\tДодати наступне слово (y/n)?");
                char c = getch();
                if(!(c == 'y' || c == 'Y'))
                    break;
                system("cls");//очистка екрану
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
        colorTextR("Помилка вибору");
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
//searching words in dictionary
double translation(char buffer[], char buffer2[],bool typeDic){
    double time;
    if (typeDic)
        {
        logoText(typeDic);
        cout << "\n\n\t\tEnter word:  ";
        SetColor(9,14);
        cin >> buffer;//зчитую слово//read the word
        found = false;
        start_chrono();
        //unsigned int start_time=  clock();//start time
        find(root, typeDic, buffer);
        time =elapsed();
        cout << "\n\n\t\tSearch time chrono 1: " << elapsed() << endl;//вивід часу
        //unsigned int end_time =  clock();
        //unsigned search_time =(float) (end_time - start_time);
        //cout << "\n\n\t\tNew search time (mls): " << search_time << endl;//вивід часу
        if (!found){
            colorTextR("\n\t\tTranslation not found.");
             cout << "\a";
//            colorText("\n\t\tAdd word (y/n)? ");
//            char c=getch();
//            if(c == 'y' || c == 'Y'){// add word
//                addWord(buffer, buffer2, typeDic);
            //}
        }

    }
    else{
        logoText(typeDic);
        cout << "\n\n\t\tВведіть слово: ";
        cin >>  buffer2;
        found = false;
        find(root, typeDic, buffer2);
        if (!found){
            colorTextR("\n\n\t\tПереклад не знайдений.");
             cout << "\a";

            colorText("\n\t\tДодати слово (y/n)? ");
            char c=getch();
            if(c == 'y' || c == 'Y' || c == 'т'){// add word
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
        cout << "\n\n\t\tДодати слово:" <<endl;
        colorTextW("\tВведіть слово (ua)     ");
        cout << buffer2;
        colorTextW("\tВведіть переклад (Eng) ");
            cin >> buffer;
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
        cin >> buffer;//зчитую слово
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
        cout << "\n\n\t\tДодати слово:" <<endl;
        colorTextW("\tВведіть слово (ua)     ");
        //cin >>  buffer2;
        gets(buffer2);
        found = false;
        find(root, typeDic, buffer2);
        if (!found){
            colorTextW("      Введіть переклад (Eng) ");
             cin >> buffer;
            colorText("\n\t\tДодати слово (y/n)? ");
            char c=getch();
            if(c == 'y' || c == 'Y' || c == 'т'){// add word
                addWord(buffer, buffer2, typeDic);
            }
        }
        else{
            colorTextR("\t\tЦе слово є в словнику.");
             cout << "\a";
        }

    }
    if (!found){
    createNode(buffer2, buffer, &root);
    addDic(buffer2, buffer);
    }
}
//пошук за функцією fundHash
double translationFast(char buffer[], char buffer2[],bool typeDic){
    double timeFast;
    if (typeDic)
        {
        //logoText(typeDic);
        //cout << "\n\n\t\tEnter word:  ";
        //cin >> buffer;//зчитую слово//read the word
        found = false;
        //unsigned int start_time=  clock();//start time
        start_chrono();

       // timer.start();
        findHash(root, typeDic, buffer); //Sleep(1000);
         //timer.stop();

       // cout << "\n\n\t\tsearch time chrono: " << elapsed() << endl;//вивід часу
        //unsigned int end_time=  clock();//end time
        //unsigned search_time =(float) (end_time - start_time);
        colorTextB("\n\n\t\tFast search time (mls): ");
        timeFast = elapsed();
        cout<< elapsed() << endl;//вивід часу

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
        //logoText(typeDic);
        cout << "\n\n\t\tВведіть слово: ";
        cin >>  buffer2;
        found = false;
        findHash(root, typeDic, buffer2);
        if (!found){
            colorTextR("\n\n\t\tПереклад не знайдений.");
             cout << "\a";

            colorText("\n\t\tДодати слово (y/n)? ");
            char c=getch();
            if(c == 'y' || c == 'Y' || c == 'т'){// add word
                addWord(buffer, buffer2, typeDic);
            }
        }
    }
    return timeFast;
}





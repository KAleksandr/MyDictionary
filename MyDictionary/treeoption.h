#ifndef TREEOPTION_H
#define TREEOPTION_H
#include <fstream>
#include <iostream>
#include "hash.h"
#include "color.h"
#include <functional>
#include <string.h>
#include <fstream>
#include <string.h>
#include <cctype>
#include <conio.h>
#include <cstdlib>//for exit
using namespace std;
struct node
{
    size_t hashEn;
    size_t hashUa;
    char uaWord[50];
    char engWord[50];
    node *left, *right;
};
extern int iter;
extern node * root;
extern bool found;//результат знаходження слова //the result of finding the word
void treePrint(node *tree, ofstream& outFile);
void addDic(char uaWord[], char engWord[]);
void del(node *tree);
void show(node *tree);
size_t hashWord (string str );//hash

void findHash(node *tree, bool typeDic, char findWord[]);//hash
void find(node *tree, bool typeDic, char findWord[]);//Found word обхід ЛКП hash
void findW(node *tree, bool typeDic, char findWord[]);//



bool menuRun(char buffer[], char buffer2[], bool typeDic);
void addWord(char buffer[], char buffer2[],bool typeDic);
double translation(char buffer[], char buffer2[],bool typeDic);
double translationFast(char buffer[], char buffer2[],bool typeDic);
void AddWords(char buffer[], char buffer2[],bool typeDic);
void menu();
void optionRun(bool typeDic);
void Options(bool typeDic);
double compareFind(char buffer[], char buffer2[],bool typeDic);
#endif // TREEOPTION_H

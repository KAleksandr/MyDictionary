#include "treeoption.h"
int count=0;
void treePrint(node *tree, ofstream& outFile)
{
     if (tree != NULL)
    {
        treePrint( tree->left, outFile);
        outFile << tree->engWord << " " << tree->uaWord << endl;
        treePrint( tree->right, outFile);
    }
     cout << "\tRecord....."<< count++/2 <<endl;
}
// write data to a file (dictionary)
void addDic(char uaWord[], char engWord[])//запис даних у файл(словника)
{
    ofstream file("dictionary.txt",ios_base::app);//appends to the end of the file
    file  << endl << engWord <<' ';
    file << uaWord ;
    file.close();

}
/*Звільняю память*/
void del(node *tree){
   if (tree!=NULL) //Поки не зустрінеться порожнє
    {
       del(tree->left); //Рекурсивна функція проходу по лівому Піддереву
       del(tree->right); //Рекурсивна функція для проходу по правому піддереву
       delete tree; //Обнулюємо кінцевий елемент дерева
       tree = NULL; //підстраховка
    }

}
void show(node *tree) //Функція проходження дерева
{
    if (tree!=NULL) //Поки не зустрінеться порожнє
    {
       show(tree->left); //Рекурсивна функція для виведення лівого піддерева
       cout<<tree->engWord << " - " << tree->uaWord << endl; //Відобразити корінь дерева

       show(tree->right); //Рекурсивна функція для виведення правого піддерева
    }

}

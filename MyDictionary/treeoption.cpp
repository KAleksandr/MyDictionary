#include "treeoption.h"
int count=0;
void treePrint(node *tree, ofstream& outFile)
{
     if (tree != NULL)
    {
        treePrint( tree->left, outFile);
        outFile << tree->hashEn << " "<< tree->engWord << " " << tree->uaWord << " " << tree->hashUa<< endl;
        treePrint( tree->right, outFile);
    }
     cout << "\tRecord....."<< count++/2 <<endl;
}
// write data to a file (dictionary)
void addDic(char uaWord[], char engWord[])//����� ����� � ����(��������)
{
    ofstream file("dictionary.txt",ios_base::app);//appends to the end of the file
    file  << endl << engWord <<' ';
    file << uaWord ;
    file.close();

}
/*������� ������*/
void del(node *tree){
   if (tree!=NULL) //���� �� ����������� ������
    {
       del(tree->left); //���������� ������� ������� �� ����� ϳ�������
       del(tree->right); //���������� ������� ��� ������� �� ������� ��������
       delete tree; //��������� ������� ������� ������
       tree = NULL; //�����������
    }

}
void show(node *tree) //������� ����������� ������
{
    if (tree!=NULL) //���� �� ����������� ������
    {
       show(tree->left); //���������� ������� ��� ��������� ����� ��������
       cout<<tree->engWord << " - " << tree->uaWord << endl; //³��������� ����� ������

       show(tree->right); //���������� ������� ��� ��������� ������� ��������
    }

}

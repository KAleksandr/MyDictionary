# include "treeoption.h"


size_t hashWord (string str )
{
    hash < string > hash_fn ;
    size_t str_hash = hash_fn ( str ) ;
    return str_hash;
}

//хешування рядків використовується для швидкого пошуку слова в дереві
void findHash(node *tree, bool typeDic, char findWord[]){
    size_t hashT;
    iter++;
        hashT =hashWord(findWord);//create hash number word user
    if(typeDic){
        if (tree == NULL) return;
        if (tree->hashEn == hashT){
            colorText("\n\t\t   Word        Translation");
            cout << "\n\t\t   "<<tree->engWord << "   -   "; //Output on screen
            colorText(tree->uaWord);
            found = true;
             return;
        }

        if (tree->hashEn > hashT)//(порівняння)
            findHash(tree->right, typeDic, findWord); // to right if >
        else
            findHash(tree->left, typeDic, findWord);//  to left if <
    }
    //Дана частина коду буде працювати якщо створити ще одне дерево і ключем буде укр хаш код
    else{
        if (tree == NULL) return;
        if (tree->hashUa == hashT){
            colorText("\n\t\t   Слово        Переклад");
            cout << "\n\t\t   "<<tree->uaWord << "   -   "; //Output on screen
            colorText(tree->engWord);
            found = true;
             return;
        }

        if (tree->hashUa > hashT)//(порівняння)
            findHash(tree->right, typeDic, findWord); // to right if >
        else
            findHash(tree->left, typeDic, findWord);//  to left if <
    }
}
// return found = true if the word is found in the dictionary and false if no (to check when adding a new word)
void find(node *tree, bool typeDic, char findWord[])//Found word
{
    size_t hashT;
    iter++;
        hashT =hashWord(findWord);//create hash number word user

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
                colorText("\n\t\t   Word        Translation");
                cout << "\n\t\t   "<<tree->engWord << "   -   "; //Output on screen
                colorText(tree->uaWord);
                found = true;

                return;

            }
        }
        else
            if (tree->hashUa == hashT)
            {
                colorText("\n\t\tСлово        Переклад");
                cout << "\n\t\t"<< tree->uaWord <<   "   -   "; //
                colorText(tree->engWord);
                found = true;

               return;

        }
    }
    if (!found)
        find(tree->right, typeDic, findWord);
    else
        return;

}


void findW(node *tree, bool typeDic, char findWord[])//Пошук слова
{
    if (tree == NULL) return;
    else
    {
        if (!found)
            find(tree->left, typeDic, findWord);
        else
            return;
        if (typeDic)
        {
            if (strcmp(tree->engWord, findWord) == 0)
            {
                colorText("\n\t\t   Слово        Переклад");
                cout << "\n\t\t   "<<tree->uaWord << "   -   "; //Output on screen
                colorText(tree->engWord);
                found = true;
                return;
            }
        }
        else
            if (strcmp(tree->uaWord, findWord) == 0)
            {
                cout << tree->engWord << endl;
                found = true;
                return;
            }
    }
    if (!found)
        find(tree->right, typeDic, findWord);
    else
        return;
    return;
}

/*
 *//**********************************************************************\
 *                   Aleksandr Kuzmenko                                   *
 *                   02/13/2018                                           *
 *                                                                        *
 *                   IT ACADEMY                                           *
 *                   PROGRAM FUTURE!                                      *
 *                                                                        *
 *                   Course: Algorithmization and                         *
 *                           programming in the language of C.            *
 *                   Date:   Tuesday 13nd February 2018                   *
 *                                                                        *
 *                   A program that searches for a word in a              *
 *                   dictionary.                                          *
 *                         - Create a       dictionary of strings         *
 *                   	   - Translation in two directions                *
 *                   	   - Create an interface for user to search       *
 *                           for a word in the dictionary                 *
 *                                                                        *
 *                   If the word is not found, the word is added to       *
 *                   the dictionary.                                      *
 *                   The dictionary has 3000+ words (English/Ukraine)     *
 *                                                                        *
 *                    Version 2.1                                         *
 \************************************************************************/

#include "adddic.h"
#include "window_size.h"
#include"logo.h"


int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);//local ukr
    logo();
    window_size();
    //window_size2();
    menu();
}

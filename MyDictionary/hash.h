#ifndef HASH_H
#define HASH_H
#include <string>
#include <iostream>
#include <functional>
using namespace std;
//��������� ����� ��������������� ��� �������� ������ ����� � �����

size_t hashWord (string str )
{
    hash < string > hash_fn ;
    size_t str_hash = hash_fn ( str ) ;
    return str_hash;
}
#endif // HASH_H

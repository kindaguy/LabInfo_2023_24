#include <iostream>
//La libreria cstring implementa funzioni legate alle c-stringhe
//(da distinguersi dalle string, che sono una classe del C++)
//Tra le funzioni definite ce n'è una molto interessante
//void * memcpy ( void * destination, const void * source, size_t num )
#include <cstring>

using namespace std;

#ifndef LIB_SORTING
#define LIB_SORTING

void merge(int [],int,int,int);
void merge_sort(int[],int, int);

void sel_sort(int [], int );
int pos_min(int [], int,int);

void scambia(int *, int *);

#endif
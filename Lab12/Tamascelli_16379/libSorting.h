#ifndef LIB_SORTING
#define LIB_SORTING

#include <iostream>
//La libreria cstring implementa funzioni legate alle c-stringhe
//(da distinguersi dalle string, che sono una classe del C++)
//Tra le funzioni definite ce n'è una molto interessante
//void * memcpy ( void * destination, const void * source, size_t num )
#include <cstring>

using namespace std;

#include "sfera.h"

void merge(sfera [],int,int,int);
void merge_sort(sfera[],int, int);

void sel_sort(sfera [], int );
int pos_min(sfera [], int,int);

void scambia(sfera *, sfera *);

#endif
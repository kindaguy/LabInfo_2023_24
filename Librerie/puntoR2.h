#ifndef _PUNTO_R2_H_
#define _PUNTO_R2_H_

#include <fstream>
#include <iostream>

using namespace std;

struct puntoR2{
   double x;
   double y;
};

//Aggiungo le funzionalità di base (lettura/stampa)

bool leggiDato(puntoR2& rdato);

bool leggiDato(ifstream& file, puntoR2& rdato);

void stampa(ofstream& file, puntoR2 dato);

void stampa(puntoR2 dato);

#endif
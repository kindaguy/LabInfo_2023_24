
#ifndef SFERA_H

#define SFERA_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Dichiaro tipo t-upla sfera

struct sfera{
   float diam;
   char col;
};

//Stampa a video
void stampa(sfera s);
//Stampa su ofstream
void stampa(sfera s, ofstream &fileout);


//Questa(e) funzione(i) legge(ono) un dato dallo stream (passato per riferimento o per indirizzo)
//e lo registra in una variabile esterna (passata per riferimento/indirizzo)
//Restituisce:
//true: lettura andata a buon fine.
//false: altrimenti

//Legge dato da ifstream in una variabile esterna passata per reference
bool leggiDato(ifstream& file, sfera &rdato);


//Legge dato da ifstream in una variabile esterna passata per indirizzo
bool leggiDato(ifstream& file, sfera *pdato);


#endif
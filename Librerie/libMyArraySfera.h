#include <fstream>
#include <iostream>

//Costrutto di fencing: evita che l'header venga importato da un altro programma se
//e` gia` stato in qualche modo importato....
#ifndef LIB_MY_ARRAY_SFERA
#define LIB_MY_ARRAY_SFERA

using namespace std;

struct sfera{
   float diam;
   char col;
};

struct myArraySfera{

   int size;
   int used;
   sfera *raw;
};





//Questa(e) funzione(i) legge(ono) un dato dallo stream (passato per riferimento o per indirizzo)
//e lo registra in una variabile esterna (passata per riferimento/indirizzo)
//Restituisce:
//true: lettura andata a buon fine.
//false: altrimenti

bool leggiDato(ifstream& file, sfera &rdato);


bool leggiDato(ifstream& file, sfera *pdato);

//Con queste funzioni posso definire una funzione di caricamento da file 
//leggermente modificata, e "universale".
//La funzione, questa volta, restituisce il codice di errore invece di esportarlo usando un riferimento.

int caricaMyArrayFile(char nomefile[], myArraySfera& rMyArray);
int caricaMyArrayFile(char nomefile[], myArraySfera *pMyArray);


#endif
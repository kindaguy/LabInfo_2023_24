#include <fstream>
#include <iostream>

//Costrutto di fencing: evita che l'header venga importato da un altro programma se
//e` gia` stato in qualche modo importato....
#ifndef LIB_MY_ARRAY_INT
#define LIB_MY_ARRAY_INT

using namespace std;

struct myArrayInt{

   int size;
   int used;
   int *raw;
};


//Carica un vettore di interi in una t-upla myArrayInt
//che restituisce. 
//Codice errore:
//0: se è andato tutto bene
//-1: se ci sono stati problemi con lo stream
//-2: se ci sono stati problemi con l'allocazione.

myArrayInt caricaInteriFile(char nomefile[], int &errcode);


//Questa(e) funzione(i) legge(ono) un dato dallo stream (passato per riferimento o per indirizzo)
//e lo registra in una variabile esterna (passata per riferimento/indirizzo)
//Restituisce:
//true: lettura andata a buon fine.
//false: altrimenti

bool leggiDato(ifstream& file, int &rdato);
bool leggiDato(ifstream *pfile, int *pdato);

//Con queste funzioni posso definire una funzione di caricamento da file 
//leggermente modificata, e "universale".
//La funzione, questa volta, restituisce il codice di errore invece di esportarlo usando un riferimento.

int caricaMyArrayFile(char nomefile[], myArrayInt& rMyArray);
int caricaMyArrayFile(char nomefile[], myArrayInt *pMyArray);


#endif
#include <fstream>
#include <iostream>
//NOTA: Il meccanismo di fencing esemplificato sotto viene
//implementato naturalmente nelle librerie standard: non abbiamo 
//mai riscontrato problemi quando includevamo, ad esempio, <iostream> nel
//programma e in una o piu` librerie.

#include "sfera.h"

//Costrutto di fencing: evita che l'header venga importato da un altro programma se
//e` gia` stato in qualche modo importato....
#ifndef LIB_MY_ARRAY_SFERA
#define LIB_MY_ARRAY_SFERA

using namespace std;


struct myArraySfera{
   int size;
   int used;
   sfera *raw;
};








//Con queste funzioni posso definire una funzione di caricamento da file 
//leggermente modificata, e "universale".
//La funzione, questa volta, restituisce il codice di errore invece di esportarlo usando un riferimento.

int caricaMyArrayFile(char nomefile[], myArraySfera& rMyArray);
int caricaMyArrayFile(char nomefile[], myArraySfera *pMyArray);

//Queste funzioni stampano
//a video
void stampa(myArraySfera  vsfera);
//su file
void stampa(myArraySfera  vsfera, ofstream& fileout);

//NOTA: il nome della funzione e` sovraccaricato (overload): e` il numero/tipo di parametri
//che determina quale funzione verra` chiamata.




#endif
#include "puntoR2.h"


bool leggiDato(puntoR2& rdato){
   cin >> rdato.x >> rdato.y;
   return true;
}

bool leggiDato(ifstream& file, puntoR2& rdato){
   //Variabile di appoggio
   puntoR2 appo;

   //Leggo da stream e registro in variabile di appoggio
   file >> appo.x >> appo.y;

   //Controllo stato dello stream: se in fail() o lo stream è in eof, restituisco false
   //in questo modo il programma chiamante potrà accorgersi che il dato manca.
   if(file.eof() || file.fail()){
      return false;
   }
   else{
      //Il dato effettivamente c'e`. Lo salvo nella variabile "che esporta il valore dalla funzione"
      rdato = appo;
      //Tutto a posto: il dato c'e`: restutuisco true
      return true;
   }

}

void stampa(ofstream& stream,puntoR2 dato){

   stream << endl << setw(12)<< dato.x << setw(12) << dato.y;

}

void stampa(puntoR2 dato){
   cout<< endl << setw(12)<< dato.x << setw(12) << dato.y;
}
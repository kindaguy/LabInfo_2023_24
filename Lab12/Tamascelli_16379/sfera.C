#include "sfera.h"


bool leggiDato(ifstream& file /*ifstream * pstream*/, sfera &rdato){
   
   //Variabile di appoggio
   sfera appo;

   //Leggo da stream e registro in variabile di appoggio
   file >> appo.diam >> appo.col;
   appo.exact = 0.f;
   appo.atoll = 0.f;
   appo.discr = 0.f;
   //(*pstream) >> appo.diam >> appo.col;

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


//Praticamente idendica alla funzione definita sopra, tranne per il fatto che
//genero il voluto side effect usando un puntatore.

bool leggiDato(ifstream& file, sfera *pdato){
   
   //Variabile di appoggio
   sfera appo;

   //Leggo da stream e registro in variabile di appoggio
   file >> appo.diam >> appo.col;
   appo.exact = 0.f;
   appo.atoll = 0.f;
   appo.discr = 0.f;
   //Controllo stato dello stream: se in fail() o lo stream è in eof, restituisco false
   //in questo modo il programma chiamante potrà accorgersi che il dato manca.
   if(file.eof() || file.fail()){
      return false;
   }
   else{
      //Il dato effettivamente c'e`. Lo salvo nella variabile "che esporta il valore dalla funzione"
      *pdato = appo;
      //Tutto a posto: il dato c'e`: restutuisco true
      return true;
   }


}

void stampa(sfera s){

   cout << endl << setw(12)<< "diametro: " << setw(12) << s.diam;
   cout << endl << setw(12) << "colore: " << setw(12) << s.col;
   cout << endl << setw(12)<< "nominale: " << setw(12) << s.exact;
   cout << endl << setw(12) << "tolleranza: " << setw(12) << s.atoll;
   cout << endl << setw(12) << "discrepanza: " << setw(12) << s.discr;
   cout << endl;
}

void stampa(sfera s, ofstream &fileout){

   fileout << endl << setw(12)<< "diametro: " << setw(12) << s.diam;
   fileout << endl << setw(12) << "colore: " << setw(12) << s.col;
   fileout << endl << setw(12)<< "nominale: " << setw(12) << s.exact;
   fileout << endl << setw(12) << "tolleranza: " << setw(12) << s.atoll;
   fileout << endl << setw(12) << "discrepanza: " << setw(12) << s.discr;
   fileout << endl;
}
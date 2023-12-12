#include "../Librerie/sfera.h"
#include "../Librerie/libMyArraySfera.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(){


   myArraySfera vdati;

   int status;

   
   
   //Qui usiamo la versione con reference a vdati;
   //status = caricaMyArrayFile("interi.dat",vdati);

   //Qui usiamo la versione con puntatore a vdati;
   status = caricaMyArrayFile("sfere.dat",&vdati);

   stampa(vdati.raw[0]);


   // if(status == 0 )
   // cout << endl << "Dati caricati correttamente:  " << endl;
   // cout << "Dimensione array: " << vdati.size << endl;
   // cout << "Numero dati: " << vdati.used << endl;
   // cout << "Primi 3 dati: " << endl;
   // for(int i =0; i <  3; i++)
   //    cout << endl << vdati.raw[i] << endl;

   // cout << "Ultimi 3 dati: " << endl;
   // for(int i = vdati.used - 3; i < vdati.used; i++)
   //    cout << endl << vdati.raw[i] << endl ;



   return 0;
}
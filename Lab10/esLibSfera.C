#include "../Librerie/sfera.h"
#include "../Librerie/libMyArraySfera.h"

#include <iostream>
#include <fstream>

using namespace std;

int main(){


   myArraySfera vdati;

   int status;

   ofstream fileout;
   
   //Qui usiamo la versione con reference a vdati;
   //status = caricaMyArrayFile("interi.dat",vdati);

   //Qui usiamo la versione con puntatore a vdati;
   status = caricaMyArrayFile("sfere.dat",&vdati);
   if (status !=0){
      switch(status) {
         case -1:
            cout << endl << "Problema apertura file."<< endl;
            return -1;
            break;
         case -2:
            cout << endl << "Problema allocazione memoria." << endl;
            return -2;
            break;
         default:
            cout << endl << "Error code not recognized. Exiting with status -3";
            return -3;
      }
   }

   fileout.open("provaSfere.dat");
   stampa(vdati.raw[0]);
   stampa(vdati.raw[0],fileout);
   fileout.close();

   fileout.open("sfereAppo.dat");
   stampa(vdati);
   stampa(vdati,fileout);


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
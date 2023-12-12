#include <iostream>
#include <fstream>
#include <cstring>

#include "../Librerie/libMyArrayInt.h"

using namespace std;

int resizeMyArray(myArrayInt * myA, int newDim);

int main(){

   myArrayInt arr;
   int err;

   err = caricaMyArrayFile("interi.dat",arr);

   cout << endl << "Size: " << arr.size;
   cout << endl << "Used: " << arr.used;
   cout << endl << "contenuto: " << endl;
   stampaMyArray(arr,0,4);
   cout << endl << "indirizzo prima: " << arr.raw << endl;

   resizeMyArray(&arr, 30);

   cout << endl << "Size: " << arr.size;
   cout << endl << "Used: " << arr.used;
   cout << endl << "contenuto: " << endl;
   stampaMyArray(arr,0,4);
   cout << endl << "indirizzo dopo: " << arr.raw << endl;



   




   return 0;
}



int resizeMyArray(myArrayInt * myA, int newDim){

   int *appo;
   //Alloco dinamicamente il nuovo vettore
   appo = new int[newDim];
   if(appo == NULL){
      cout<< endl << "ahia: qualcosa e` andato storto" << endl;
      return -1;
   }
   //Se va tutto bene
   //Distinguiamo 2 casi

   //myA->size === (*myA).size
   //*myA.size
   if(newDim > myA->size){
      // for(int i=0; i<myA->size; i++){
      //    appo[i] = myA->raw[i];
      // }
      memcpy(appo, myA->raw, myA->size * sizeof(int));
      //Aggiorno size
      myA->size = newDim;
      //used rimane invariato
      //Rimuovo da heap vecchio array
      delete [] myA->raw;
      //Assegno a raw l'indirizzo del nuovo array
      myA->raw = appo;
      return 0;

   }

   else if(newDim < myA->size){

      // for(int i=0; i<newDim; i++){
      //    appo[i] = myA->raw[i];
      // }
      memcpy(appo, myA->raw, newDim * sizeof(int));

      //Aggiorno size
      myA->size = newDim;
      //used...

      if(myA->used > newDim)
         myA->used = newDim;

      //Rimuovo da heap vecchio array
      delete [] myA->raw;
      //Assegno a raw l'indirizzo del nuovo array
      myA->raw = appo;
      return 0;

   }

   //else: non fare nulla: newDim ==  myArray->size: non va ridimensionato
   return 0;



}
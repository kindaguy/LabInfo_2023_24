#include <iostream>
#include <fstream>
#include <cstring>

#include "../Librerie/libMyArrayInt.h"

using namespace std;

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


 cout << endl << "Ciao mondo" << endl;
   




   return 0;
}



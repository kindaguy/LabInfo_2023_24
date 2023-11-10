#include "libreria.h"


int caricaDatiFile(char nomefile[], float vdati[], int maxdati){

   float appo;
   ifstream filedati;
   int conta = 0;

   filedati.open(nomefile);

   if(filedati.fail()){

      cout << endl << "ERRORE apertura file:  " << nomefile <<"!!!" << endl;

      cout << endl <<"Sicuro che il file si trovi nella stessa cartella del programma????" << endl; 

      return -1;

   }
   else{ //Flusso dati da file aperto con successo

      filedati >> appo;

      while (!filedati.eof() and conta < maxdati ){

         vdati[conta] = appo;
         conta ++;
         filedati >> appo;
      }

   }

   filedati.close();

   return conta;

}


int eliminaSwap(float v[], int pos, int ndati){

   if(pos >=0 and pos < ndati){

      v[pos] = v[ndati-1];
      return ndati-1;

   }
   else{
      cout << endl << "Eliminaswap: posizione fuori range!\n";  
      return -1;
   }
}

int eliminaShift(float v[], int pos, int ndati){
   if(pos >=0 and pos < ndati){
      for(int i = pos; i<ndati-1; i++){
         //Sposto tutti gli elementi a dx di pos di una posizione a sx.
         //v[pos] = v[pos+1];
         //v[pos+1] = v[pos+2]
         //...
         //v[ndati-2] = v[ndati-1]
         v[i] = v[i+1];
      }
      
      return ndati-1;

   }
   else{
      cout << endl << "Eliminaswap: posizione fuori range!\n";  
      return -1;
   }

}


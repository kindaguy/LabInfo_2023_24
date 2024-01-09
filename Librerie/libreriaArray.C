#include "libreriaArray.h"


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


int *caricaDatiFile(char nomefile[], int *np){

   int *v=NULL;
   ifstream ifile;

   int appo;
   int conta = 0;

   ifile.open(nomefile);
   if(ifile.fail()){
      cout << "\nProblema apertura file " << nomefile <<". Esco!" << endl;
      *np = -1;
      return NULL;
   }
   //Se tutto a posto...
   //Prima lettura file: conto i dati
   ifile >> appo;
   while(!ifile.eof()){
      conta++;
      ifile >> appo;
   }
   
   //Si puo` fare cosi`  invece di 
   //chiudere e riaprire lo stream...
   ifile.clear();
   ifile.seekg(0,ios::beg);
   //"Nastro riavvolto...."

   v = new int[conta];
   if(v==NULL){
      cout << endl << "Problema allocazione! Esco."<< endl;
      *np = 0;
      return v;
   }
   //Se tutto a posto
   //Carico dati nell'array
   for(int i=0; i<conta; i++)
      ifile >> v[i];

   ifile.close();
   
   *np = conta;
   
   return v;

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


int pos_min(float v[], int ind_min, int ind_max){
    
    int pos_min = ind_min;
    float min = v[ind_min];
    //Determino minimo in array v[ind_min],...v[ind_max]
    for(int i = ind_min+1; i<=ind_max; i++){
        //Se incontro elemento piu`  piccolo del minimo
        //attuale aggiorno minimo e posizione minimo
        if (v[i]<min){
            pos_min = i;
            min = v[i];
        }
    }
    return pos_min;
}



int pos_min(char v[], int ind_min, int ind_max){
    
    int pos_min = ind_min;
    char min = v[ind_min];
    //Determino minimo in array v[ind_min],...v[ind_max]
    for(int i = ind_min+1; i<=ind_max; i++){
        //Se incontro elemento piu`  piccolo del minimo
        //attuale aggiorno minimo e posizione minimo
        if (v[i]<min){
            pos_min = i;
            min = v[i];
        }
    }
    return pos_min;
}



void selsort(float v[], int used){
    int pmin;
    
    for(int i=0; i<used; i++){
        pmin = pos_min(v,i,used-1);
        scambia(v,i,pmin);
    }
}

void scambia(float v[],int p1, int p2){
    float appo;
    appo = v[p1];
    v[p1] = v[p2];
    v[p2]=appo;
}

void scambia(char v[],int p1, int p2){
    char appo;
    appo = v[p1];
    v[p1] = v[p2];
    v[p2]=appo;
}
#include "libMyArrayInt.h"

//Carica un vettore di interi in una t-upla myArrayInt
//che restituisce. 
//Codice errore:
//0: se è andato tutto bene
//-1: se ci sono stati problemi con lo stream
//-2: se ci sono stati problemi con l'allocazione.

myArrayInt caricaInteriFile(char nomefile[], int &errcode){

   //Valore da restituire
   myArrayInt tupla;

   //Contatore: INIZIALIZZARE A zero!
   int conta = 0;
   int appo;
   //Gestore flusso da file
   ifstream filein;

   //Pignoleria/igiene
   tupla.size = 0;
   tupla.used = 0;
   tupla.raw = NULL;

   //Dichiarazione e inizializzazione finita

   filein.open(nomefile);
   
   if(filein.fail()){
      errcode = -1;
      return tupla;
   }

   //NOTA: la funzione non gestisce l'errore: si limita a segnalarlo in uscita.

   //Ciclo Spoletini
   filein>> appo;
   while(!filein.eof()){
      conta++;
      filein >> appo;
   }

   //Dati su file contati
   
   //Reset dello stream
   filein.clear();
   filein.seekg(0, ios::beg);
   //oppure
   //filein.close();
   //filein.open(nomefile);


   
   tupla.raw = new int[conta];

   if(tupla.raw == NULL){

      errcode = -2;
      return tupla;
   }
   //NOTA: anche qui non gestiamo l'eccezione, ci limitiamo a segnalarla...

   tupla.size = conta;
   
   //N.B.: uso direttamente used per indicizzare l'array
   //quindi: non ho bisogno di inizializzare (gia` fatto sopra)

   for( ; tupla.used < conta; tupla.used++){

      filein >> tupla.raw[tupla.used];
   }

   filein.close();

   errcode = 0;


   return tupla;

}


bool leggiDato(ifstream& file, int &rdato){
   
   //Variabile di appoggio
   int appo;

   //Leggo da stream e registro in variabile di appoggio
   file >> appo;

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

bool leggiDato(ifstream& file, int *pdato){
   
   //Variabile di appoggio
   int appo;

   //Leggo da stream e registro in variabile di appoggio
   file >> appo;

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



int caricaMyArrayFile(char nomefile[], myArrayInt& rMyArray){
   

   //Contatore: INIZIALIZZARE A zero!
   int conta = 0;
   int appo;
   //Gestore flusso da file
   ifstream filein;

   //Variabile per controllare status stream
   bool status = true;

   //Pignoleria/igiene
   rMyArray.size = 0;
   rMyArray.used = 0;
   rMyArray.raw = NULL;

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }
   //NOTA: la funzione non gestisce l'errore: si limita a segnalarlo in uscita.

   status = leggiDato(filein,appo);

   while(status == true){
      conta++;
      status = leggiDato(filein,appo);
   }

   //Reset dello stream
   filein.clear();
   filein.seekg(0, ios::beg);
   //oppure
   //filein.close();
   //filein.open(nomefile);


   
   rMyArray.raw = new int[conta];

   if(rMyArray.raw == NULL){

      return -2;

   }
   //NOTA: anche qui non gestiamo l'eccezione, ci limitiamo a segnalarla...

   rMyArray.size = conta;
   
   //N.B.: uso direttamente used per indicizzare l'array
   //quindi: non ho bisogno di inizializzare (gia` fatto sopra)

   for( ; rMyArray.used < conta; rMyArray.used++){

      leggiDato(filein, rMyArray.raw[rMyArray.used]);
      //NOTA: ignoro il valore restituito...
   }

   filein.close();

   //Dati caricati correttamente nella variabile esterna
   return 0;

}



int caricaMyArrayFile(char nomefile[], myArrayInt *pMyArray){

  //Contatore: INIZIALIZZARE A zero!
   int conta = 0;
   int appo;
   //Gestore flusso da file
   ifstream filein;

   //Variabile per controllare status stream
   bool status = true;

   //Pignoleria/igiene
   // (*pMyArray).size  = 0;
   pMyArray->size = 0;
   pMyArray->used = 0;
   pMyArray->raw = NULL;

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }
   //NOTA: la funzione non gestisce l'errore: si limita a segnalarlo in uscita.

   status = leggiDato(filein,appo);

   while(status == true){
      conta++;
      status = leggiDato(filein,appo);
   }

   //Reset dello stream
   filein.clear();
   filein.seekg(0, ios::beg);
   //oppure
   //filein.close();
   //filein.open(nomefile);


   
   pMyArray->raw = new int[conta];

   if(pMyArray->raw == NULL){

      return -2;

   }
   //NOTA: anche qui non gestiamo l'eccezione, ci limitiamo a segnalarla...

   pMyArray->size = conta;
   
   //N.B.: uso direttamente used per indicizzare l'array
   //quindi: non ho bisogno di inizializzare (gia` fatto sopra)

   for( ; pMyArray->used < conta; pMyArray->used++){

      leggiDato(filein, pMyArray->raw[pMyArray->used]);
      //NOTA: ignoro il valore restituito...
   }

   filein.close();

   //Dati caricati correttamente nella variabile esterna
   return 0;

}

void stampaMyArray(myArrayInt& rMyArray,int from, int to){

   for(int i=from; i<=to; i++){
      cout << endl <<rMyArray.raw[i] ;
   }
   cout << endl;
}

void stampaMyArray(myArrayInt& rMyArray){

   for(int i=0; i<rMyArray.used; i++){
      cout << endl <<rMyArray.raw[i] ;
   }
   cout << endl;


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

int caricaMyArrayFileResize(char nomefile[], myArrayInt& rMyArray){

   //Contatore: INIZIALIZZARE A zero!
   int conta = 0;
   int appo;
   //Gestore flusso da file
   ifstream filein;

   int dim0 = 20;
   int incrDim = 10;
   int err;

   //Variabile per controllare status stream
   bool status = true;

   //Inizializzo array di dim0 elementi
   rMyArray.size = dim0;
   rMyArray.used = 0;
   rMyArray.raw = new int[dim0];

   if(rMyArray.raw == NULL){

      return -2;

   }

   filein.open(nomefile);
   
   if(filein.fail()){
      return -1;
   }
   //NOTA: la funzione non gestisce l'errore: si limita a segnalarlo in uscita.

   status = leggiDato(filein,appo);
   while(status == true){
      //Se non c'e` piu` posto
      if(rMyArray.used == rMyArray.size){
         err = resizeMyArray(&rMyArray,rMyArray.size+incrDim);
      }

      rMyArray.raw[rMyArray.used] = appo;
      rMyArray.used++;
      status = leggiDato(filein,appo);
   }

   filein.close();

   //Dati caricati correttamente nella variabile esterna
   return 0;


}

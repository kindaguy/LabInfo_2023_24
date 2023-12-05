#include "libMyArraySfera.h"




bool leggiDato(ifstream& file, sfera &rdato){
   
   //Variabile di appoggio
   sfera appo;

   //Leggo da stream e registro in variabile di appoggio
   file >> appo.diam >> appo.col;

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



int caricaMyArrayFile(char nomefile[], myArraySfera& rMyArray){
   

   //Contatore: INIZIALIZZARE A zero!
   int conta = 0;
   sfera appo;
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


   
   rMyArray.raw = new sfera[conta];

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



int caricaMyArrayFile(char nomefile[], myArraySfera *pMyArray){

  //Contatore: INIZIALIZZARE A zero!
   int conta = 0;
   sfera appo;
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


   
   pMyArray->raw = new sfera[conta];

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






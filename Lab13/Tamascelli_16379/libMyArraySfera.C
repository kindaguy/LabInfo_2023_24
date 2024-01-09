#include "libMyArraySfera.h"

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



//Queste funzioni stampano
//a video
void stampa(myArraySfera  vsfera){
   cout << endl << "size: " << vsfera.size << endl;
   cout << endl << "used: " << vsfera.used << endl;

   for(int i=0; i<vsfera.used;i++)
      stampa(vsfera.raw[i]);
}
//su file
void stampa(myArraySfera  vsfera, ofstream& fileout){
   fileout << endl << "size: " << vsfera.size << endl;
   fileout << endl << "used: " << vsfera.used << endl;


   for(int i=0; i<vsfera.used; i++)
      stampa(vsfera.raw[i],fileout);

}





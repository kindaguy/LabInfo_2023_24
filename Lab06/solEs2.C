#include <iostream>
#include <fstream>
#include <cmath>

//Libreria per la formattazione delle stampe (a video o su file)
#include <iomanip>

#include "../Librerie/libreriaArray.h"


using namespace std;

#define NN 150
#define SPACE 20



void selSortAllineato(char vc[], float vf[], int used);

int main(){

   int conta = 0;
   
   
   int contablu = 0;
   int contagialli = 0;
   int contarossi = 0;

   float accublu = 0.f;
   float accugialli = 0.f;
   float accurossi = 0.f;

   float accublu2 = 0.f;
   float accugialli2 = 0.f;
   float accurossi2 = 0.f;
   


   float appof;
   char appoc;

   float vdiams[NN];
   char vcols[NN];

   ifstream file_in;

   //Apro file

   file_in.open("sfere.dat");
   //Solito controllo.
   if(file_in.fail()){
      cout << "\n Problema apertura file dati! Esco" << endl;
      return -1;
   }

   //Stream aperto correttamente: proseguo


   //Ciclo Spoletini
   //Prima lettura fuori ciclo

   //Attenzione: il "dato" e` la coppia (diametro,colore) quindi una lettura di "dato" 
   //significa leggere entrambi i valori.

   file_in >> appof >> appoc;

   while(!file_in.eof()){
      vdiams[conta] = appof;
      vcols[conta] = appoc;
      conta++;
      file_in >> appof >> appoc;
   }

   file_in.close();

   //Dati caricati

   //Calcolo medie e deviazioni standard: processo dato per dato
   //e incremento accumulatori/contatori per colore corrispondente.

   for(int i=0; i<conta; i++){

      if(vcols[i] == 'b'){
         contablu++;
         accublu = vdiams[i];
         accublu2 = pow(vdiams[i],2);
      }
      else if(vcols[i] == 'g'){  
         contagialli++;
         accugialli = vdiams[i];
         accugialli2 = pow(vdiams[i],2);

      }
      else{ //rimane solo caso 'r'
         contarossi++;
         accurossi = vdiams[i];
         accurossi2 = pow(vdiams[i],2);
      }

   }

   cout << endl << "Statistiche per colore: " << endl << endl;

   //Attenzione alla formattazione:
   //left/right: allinea testo a sx o a dx
   //setw(N): scrive il dato in un campo di N caratteri
   //Il risultato e` la stampa "formattata che vedete a video"

   cout << "Sfere blu: "<< endl;
   cout << endl  << left << setw(SPACE) << "Numero: "<< right << setw(SPACE) << contablu;
   cout << endl  << left << setw(SPACE) << "Diametro medio: " << right  << setw(SPACE) << right << accublu/contablu;
   cout << endl  << left << setw(SPACE) << "Stddev diametro: " << right << setw(SPACE) << sqrt(accublu2/contablu - pow(accublu/contablu,2));
   cout << endl << endl;
   
   cout << "Sfere gialle: "<< endl;
   cout << endl  << left << setw(SPACE) << "Numero: "<< right << setw(SPACE) << contagialli;
   cout << endl  << left << setw(SPACE) << "Diametro medio: " << right  << setw(SPACE) << right << accugialli/contagialli;
   cout << endl  << left << setw(SPACE) << "Stddev diametro: " << right << setw(SPACE) << sqrt(accugialli2/contagialli - pow(accugialli/contagialli,2));
   cout << endl << endl;

   cout << "Sfere rosse: "<< endl;
   cout << endl  << left << setw(SPACE) << "Numero: "<< right << setw(SPACE) << contarossi;
   cout << endl  << left << setw(SPACE) << "Diametro medio: " << right  << setw(SPACE) << right << accurossi/contarossi;
   cout << endl  << left << setw(SPACE) << "Stddev diametro: " << right << setw(SPACE) << sqrt(accurossi2/contarossi - pow(accurossi/contarossi,2));
   cout << endl << endl;

   //Ordinamento
   selSortAllineato(vcols,vdiams,conta);
   for(int i=0; i< 3; i++){
      cout << endl << setw(10) << vdiams[i] << setw(10) << vcols[i];
   }

    for(int i=conta-3 ; i< conta; i++){
      cout << endl << setw(10) << vdiams[i] << setw(10) << vcols[i];
   }
   return 0;
}





void selSortAllineato(char vc[],float vf[], int used){
    int pmin;
    
    for(int i=0; i<used; i++){
      //Determino il minimo dell'array dei colori
      pmin = pos_min(vc,i,used-1);
      //Sposto minimo in testa...
      scambia(vc,i,pmin);
      //Mantengo secondo array allineato.
      scambia(vf,i,pmin);
    }
}
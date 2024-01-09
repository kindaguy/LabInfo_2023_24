#include <iostream>
#include <fstream>
#include <iomanip>

#include "sfera.h"
#include "libMyArraySfera.h"
#include "libSorting.h"


using namespace std;


int main(){
  
  myArraySfera v;
  int err;

  int nsfere;
  //Conteggio per colore
  //posizione 0: blu
  //posizione 1: giallo
  //posizione 2: rosso

  int ncol[3] = {0,0,0};
  char cols[3] = {'b','g','r'};
  float exdiam[3];
  float tolls[3];
  ifstream filein;
  char appo;
  err = caricaMyArrayFile("sfere.dat",v);

  //Debug
  //stampa(v);
  //
  
  nsfere = v.used;

  cout << endl << " Numero di sfere:" << nsfere << endl;

  //Conteggio sfere per colore.
  for(int i=0; i<nsfere; i++){
    if(v.raw[i].col == 'b') ncol[0]++;
    else if(v.raw[i].col == 'g') ncol[1]++;
    else ncol[2]++;
  }

  cout << endl << "Conteggio per colore:";
  cout << endl << setw(10) << left << "blu:" << right << ncol[0];
  cout << endl << setw(10) << left << "gialle:" << right<< ncol[1] ;
  cout << endl << setw(10) << left << "rosse:" << right << ncol[2];
  cout << endl;



  //Completamento dei dati
  //Carico diametri nominali e tolleranze.
  filein.open("tolleranze.dat");
  
  if(filein.fail()){
    cout << endl << "errore apertura file tolleranze" << endl;
    return -1;
  }
  //Atrimenti tutto a posto e continuo
  for(int i=0; i<3; i++)
    filein >> cols[i] >> exdiam[i] >> tolls[i];

  filein.close();

  cout << endl << "Da tolleranze.dat:" << endl;
   cout << endl << setw(10) << "colore"  << setw(10) << "nominale" << setw(15)<< "tolleranza";
  for(int i=0; i<3; i++)
    cout << endl << setw(10) << cols[i] << setw(10) << exdiam[i] << setw(15)<< tolls[i];

  cout << endl;

  //Completamento descrizione sfere

  for(int i=0; i<nsfere; i++){
    if(v.raw[i].col == 'b'){
      v.raw[i].exact = exdiam[0];
      v.raw[i].atoll = tolls[0];
      v.raw[i].discr = v.raw[i].diam-v.raw[i].exact;
    }
    else if(v.raw[i].col == 'g'){
      v.raw[i].exact = exdiam[1];
      v.raw[i].atoll = tolls[1];
      v.raw[i].discr = v.raw[i].diam-v.raw[i].exact;
    }
    else {
      v.raw[i].exact = exdiam[2];
      v.raw[i].atoll = tolls[2];
      v.raw[i].discr = v.raw[i].diam-v.raw[i].exact;
    }
  }

  stampa(v);

  merge_sort(v.raw,0, v.used-1);

  cout << endl << "Dopo ordinamento...." << endl;
  stampa(v);

  return 0;
}



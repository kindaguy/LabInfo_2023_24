//File header

//Includo le librerie che servono alle funzioni
//qui dichiarate
#include <iostream>
#include <fstream>

using namespace std;

//Dichiaro le funzioni di libreria

//Carica i dati da file in un vettore di float.
//nomefile: nome del file dati
//vett: vettore in cui  registrare dati
//dim: dimensione array

int caricaDatiFile(char nomefile[], float vett[], int dim);


//Elimina l'elemento in posizione pos 
//dal vettore v
//contenente dim dati
//scambiando elemento da eliminare con ultimo
//dato array. Restituisce la nuova dimensione
//(used) dei dati, -1 se pos non e`  in range

int eliminaSwap(float v[], int pos, int dim);

//Elimina l'elemento in posizione pos 
//dal vettore v
//contenente dim dati
//shiftando a sinistra di una posizione gli 
//elementi successivi. PRESERVA ORDINE RELATIVO!!!
// Restituisce la nuova dimensione
//(used) dei dati, -1 se pos non e`  in range

int eliminaShift(float v[], int pos, int dim);
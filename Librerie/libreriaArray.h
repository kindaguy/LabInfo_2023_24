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

//Questa funzione carica dati interi da file in un vettore dinamicamente allocato.
//Restituisce il vettore (int *) e registra la dimensione del vettore
//nel parametro riferimenti (int *pn)
//Se errore file: return NULL e dimensione -1;
//Se errore allocazioni: return NULL e dimensione 0;

int *caricaDatiFile(char nomefile[], int *np);

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


//Determina la posizione dell'elemento piu` piccolo nell'array
//v[ind_min,...,ind_max]
int pos_min(float v[], int ind_min, int ind_max);
int pos_min(char v[], int ind_min, int ind_max);

//Ordina l'array v contenente used elementi usando
//algoritmo Selection Sort
void selsort(float v[], int used);



//Scambia gli elementi in posizione p1 e p2 dell'array v
void scambia(float v[],int p1, int p2);
void scambia(char v[],int p1, int p2);


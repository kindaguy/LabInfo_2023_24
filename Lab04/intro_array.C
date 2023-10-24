//Direttiva a preprocessore: includi libreria
#include <iostream>

//Direttiva a preprocessore: definizione costante
#define NN 35
#define PI_GRECO 3.14159f


using namespace std;
//Stampa gli elementi dell'array
void stampaArray(int [],int);

//Caricamento: restituisce il numero di elementi caricati
int caricaArray(int [],int);

//Caricamento: restituisce il numero di elementi caricati
int caricaArrayStop(int [],int);


int main(){
    
    //Questa terna va mantenuta in modo consistente
    int a[NN];
    int size = NN;
    int used = 0;
    cout << endl << "Dimensione array: " << NN << endl;

    a[0]= 5;

    cout << endl << a[0] << endl;

    return 0;
}

//Stampa gli elementi dell'array
void stampaArray(int a[],int used){

    for(int i =0; i<used; i++){
        cout << endl << "elemento " << i << ": " << a[i];
    }
    cout << endl;
}

//Caricamento: restituisce il numero di elementi caricati
int caricaArray(int a[], int size){
    for(int i=0; i<size; i++){
        cout << " Inserire valore intero:";
        cin >> a[i];
    }
    return size;

}

//Soluzione esercizio 2
int caricaArrayStop(int a[], int size){
    int conta = 0;
    int appo;

    cin >> appo;
    while(appo!=0 and conta<size){
        a[conta] = appo;
        conta++;

        if(conta!=size) cin >> appo;
    }
    
   
    return conta;

}
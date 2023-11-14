#include <iostream>
#include <fstream>
#include "../Librerie/libreriaArray.h"
using namespace std;

void media(float v[], int ndati,float *pmedia);

int main(){

    //Qui leggeremo il numero di dati
    int ndati;
    //Qui salveremo l'indirizzo dell'array
    //allocato dinamicamente
    float *vdati = NULL;

    float average;

    ifstream file_in;

    ofstream file_out;

    file_in.open("dati_header.dat");
    if(file_in.fail()){
        cout << endl << " Errore apertura file! Esco!" <<endl;
        return -1;
    }

    //Se aggancio stream ok....

    //Leggo numero di dati da file, come da specifiche formato
    file_in >> ndati;

    vdati = new float[ndati];

    if(vdati == NULL){
        cout<< endl << "Problema allocazione dinamica vdati, esco"<<endl;
        return -2;
    }

    //Ho l'array dinamicamente allocato

    //So quanti dati devo caricare
    for(int i=0; i<ndati; i++)
        file_in >> vdati[i];
    
    file_in.close();

    //Posso procedere con l'elaborazione
    selsort(vdati,ndati);

    media(vdati,ndati,&average);

    cout << endl << " Media campionaria: " << average << endl;

    //Fate quello che dovete fare
    //Rimuove array
    delete [] vdati;
    vdati = NULL;

    return 0;
}


void media(float v[], int ndati,float *pmedia){

    float accu = 0.f;

    for(int i=0; i<ndati; i++)
        accu += v[i]; //accu = accu + v[i]
    
    *pmedia = accu/ndati;

}
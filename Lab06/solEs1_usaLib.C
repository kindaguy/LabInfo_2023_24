#include <iostream>
#include <fstream>

#include "../Librerie/libreriaArray.h"

#define NMAX 150

using namespace std;



int main(){

    int ndati;
    float vdati[NMAX];

    ifstream file_in;
    ofstream file_out;

    file_in.open("dati_header.dat");

    //Leggo numero di dati da file, come da specifiche formato
    file_in >> ndati;

    //Adesso so quanti dati devo caricare
    for(int i=0; i<ndati; i++)
        file_in >> vdati[i];
    
    file_in.close();
    cout << endl << endl << " Prima ordinamento:" << endl;
    for(int i=0; i<10; i++)
        cout << endl << vdati[i] << endl;

    //Supponiamo di avere i dati correttamente caricati
    selsort(vdati,ndati);

    cout << endl << endl << " Dopo ordinamento:" << endl;
    for(int i=0; i<10; i++)
        cout << endl << vdati[i] << endl;

    return 0;
}

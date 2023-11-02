#include <iostream>

//Libreria per uso stream su file
#include <fstream>

using namespace std;

int main(){

    float a;
    int conta = 0;

    ifstream file_in;
    ofstream file_out;

    file_in.open("dati.dat");

    file_out.open("dati_copia.dat");


    //file_in.fail() restiuisce:
    //true: se qualcosa e`  andato storto con l' apertura del flusso
    //false: altrimenti
    if(file_in.fail()){
        //esci di corsa dal programma!
        cout << endl << "Problema apertura file dati. Esco!" << endl;
        return -1;
    }

    if(file_out.fail()){
         //esci di corsa dal programma!
        cout << endl << "Problema apertura file scrittura. Esco!" << endl;
        return -2;
    }


    //Istruzione di lettura da tastiera
    file_in >> a;

    //Il caricamento termina appena viene inserito lo 0
   
   //file_in.eof() restituisce:
   //true: se il file e`  finito (non ci sono piu` dati)
   //false: altrimenti (ci sono ancora dati)

   while(!file_in.eof()){ 
    
        conta = conta + 1;
        file_out << a << endl;
     //   cout << endl <<  "conta: " << conta  << endl;
        file_in >> a;
    }

    cout << endl << "Dati su file: " << conta << endl;
    
    file_in.close();
    file_out.close();

    return 0;
}


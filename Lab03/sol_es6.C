
#include <iostream>

using namespace std;


//Dichiarazione funzioni
int leggiValore(int,int);

int main(){

    int a;
    int quanti;
    

    int somma = 0; //Inizializzo valore

    //Chiedo all'utente quanti dati vuole inserire
    cout << endl << "Quanti voti vuoi inserire?" << endl;
    cin >> quanti;

    //A questo punto so quanti valori saranno inseriti
    for(int i=0; i<quanti; i++){
        cout << endl << "inserire valore " << i+1 << " di " << quanti <<": ";
        a = leggiValore(18,30);
        somma = somma+a;
    }

    //Questo ciclo e`  equivalente a...
    //int i=0;
    // while(i<quanti){
    //     a = leggiValore(18,30);
    //     somma = somma+a;
    //     i++;
    // }
    

    //Quando esco devo fare qualche cosa....
    cout << endl << "somma = " << somma << endl;
    cout << endl << "media = " << (float)somma/quanti << endl;
    

    
    return 0;
}

int leggiValore(int min,int max){
   
   int value;

   do{
      cout << endl << "inserire valore compreso tra" << min << " e " << max<< endl;
      cin >> value;
   }while(value<min or value >max);

   return value;

}
#include <iostream>
#include <iomanip>

using namespace std;

#define SIZE 15

int main(){

   int var = 5;
   int arrayInt[10];

   int *puntatore;

   int check;
   
   cout <<  "variabile: " << endl;
   cout << endl <<  "\t contenuto:  " << setw(SIZE) << var;
   cout << endl <<  "\t indirizzo:  " << setw(SIZE) << &var;
   cout << endl << endl;

   cin >> check;


   puntatore = &var; //Operarore &: restituisce l'indirizzo del suo argomento.

   cout <<  "Puntatore: " << endl;
   cout << endl <<  "\t contenuto:  " << setw(SIZE) << puntatore;
   cout << endl <<  "\t indirizzo:  " << setw(SIZE) << &puntatore;
   cout << endl << endl;

   cin >>check;
   
   cout << endl << "*puntatore = " << *puntatore;

   *puntatore  = 7;

   cout <<  "variabile: " << endl;
   cout << endl <<  "\t contenuto:  " << setw(SIZE) << var;
   cout << endl <<  "\t indirizzo:  " << setw(SIZE) << &var;
   cout << endl << endl;

   cout <<  "Puntatore: " << endl;
   cout << endl <<  "\t contenuto:  " << setw(SIZE) << puntatore;
   cout << endl <<  "\t indirizzo:  " << setw(SIZE) << &puntatore;
   cout << endl << endl;
   
   cin >> check;
   
   
   
   cout <<  "Array: " << endl;
   cout << endl <<  "\t contenuto:  " << setw(SIZE) << arrayInt;
   cout << endl <<  "\t indirizzo:  " << setw(SIZE) << arrayInt;
   cout << endl << endl;
   cout << "Un array statico non ha un contenuto: e` un indirizzo..." << endl << endl;


   return 0;

}
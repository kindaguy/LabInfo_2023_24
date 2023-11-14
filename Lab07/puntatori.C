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

   cout <<  endl << "variabile: " << endl;
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


   arrayInt[2]=4;
   //puntatore = &arrayInt[2];
   
   puntatore = arrayInt+2;
   cout << endl << "Sono l' array" << arrayInt << endl;
   cout << endl <<  " Indirizzo in puntatore: " << puntatore <<endl;
   cout << endl<< "eccomi: " << *puntatore << endl;
   return 0;

}
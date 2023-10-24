#include <iostream>
using namespace std;

//Scope: ambito di visibilita` di variabili (e funzioni)

//Procedura: funzione che non restituisce nulla (void)
void scambia(int,int);
void scambiaVettore(int[]);
int main(){
    int a=5;
    int b=7;

    int v[2] = {5,7};

    cout << endl << "Prima:";
    cout << endl << "a = " << a <<"; b = " << b << endl;

    cout << endl << "Prima (vettore):";
    cout << endl << "v[0] = " << v[0] <<"; v[1] = " << v[1] << endl;
    
    scambia(a,b);
    scambiaVettore(v);

    cout << endl << "Dopo:";
    cout << endl << "a = " << a <<"; b = " << b << endl;
   
    cout << endl << "Dopo (vettore):";
    cout << endl << "v[0] = " << v[0] <<"; v[1] = " << v[1] << endl;
   
    return 0;
}

void scambia(int v1, int v2){

    int appo;
    appo=v1;
    v1 = v2;
    v2 = appo;

    cout << endl<< " in scambia:" << endl;
    cout << "v1: " << v1 << "; v2: " << v2 << endl;
    
    //return;
}   

void scambiaVettore(int a[]){

    int appo;
    appo = a[0];
    a[0] = a[1];
    a[1] = appo;

    return;
}
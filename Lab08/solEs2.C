#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int n);

int main(){

    int numero;

    cout << "Inserire numero: ";
    cin >> numero;

    if(isPrime(numero))
        cout << numero << " e`  primo." << endl;
    else
        cout << numero << " NON e` primo" << endl; 
    return 0;
}

bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}
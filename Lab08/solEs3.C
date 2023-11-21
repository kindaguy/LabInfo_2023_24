#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool isSquare(int n);

int main(){

    int numero;

    cout << "Inserire numero: ";
    cin >> numero;

    if(isSquare(numero))
        cout << numero << " e`  quadrato perfetto." << endl;
    else
        cout << numero << " NON e` quadrato perfetto" << endl; 
    return 0;
}

bool isSquare(int n){
    int appo;

    appo = sqrt(n);
    if(appo*appo == n)
        return true;
    else
        return false;
}
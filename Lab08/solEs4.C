#include <iostream>
#include <fstream>
#include <cmath>

#include "../Librerie/libreriaUtils.h"
#include "../Librerie/libreriaArray.h"

using namespace std;

//Dichiarazione funzioni
bool isSquare(int n);
bool isPrime(int n);

int main(){
    int *v;


}



//Definizione funzioni
bool isPrime(int n){
    for(int i=2; i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}

bool isSquare(int n){
    int appo;

    appo = sqrt(n);
    if(appo*appo == n)
        return true;
    else
        return false;
}
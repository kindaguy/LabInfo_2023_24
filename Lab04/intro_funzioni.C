#include <iostream>

using namespace std;



//Dichiarazione
float massimo(float, float);

int main(){
    int v1, v2;
    cin >> v1 >> v2;
    cout << endl << "il valore piu`  grande inserito e`: " << massimo(v1,v2) << endl;
    return 0;
}

//Restuisce il massimo tra due valori float.

//Definizione
float massimo(float a, float b){
    if(a<=b){ 
        return b;
    }
    else{
        return a;
    }
}
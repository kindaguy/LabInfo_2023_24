//Direttiva a preprocessore: includi libreria
#include <iostream>

//Direttiva a preprocessore: definizione costante
#define NN 35
#define PI_GRECO 3.14159f


using namespace std;

int main(){
    
    //Questa terna va mantenuta in modo consistente
    int a[NN];
    int size = NN;
    int used = 0;
    cout << endl << "Dimensione array: " << NN << endl;

    a[0]= 5;

    cout << endl << a[0] << endl;

    return 0;
}

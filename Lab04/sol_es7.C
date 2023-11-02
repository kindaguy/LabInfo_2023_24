#include <iostream>

using namespace std;

void scambia(int,int);
void scambia(int [], int, int, int );
void stampaArray(int [], int);
int main(){
    int a=5;
    int b=7;
    int w[4]={1,2,3,4};
    int size = 4;


    // cout << endl << a  << "  " << b << endl;
    // scambia(a,b);
    // cout << endl << a  << "  " << b << endl;
    cout << endl << "Prima di scambio";
    stampaArray(w,size);
    scambia(w,size,0,4);
    cout << endl << "Dopo scambio";
    stampaArray(w,size);
    return 0;
}

void scambia(int v1, int v2){
    int appo;
    cout << endl << " Dentro scambia" << endl;
    cout << endl << v1  << "  " << v2 << endl;
    appo = v1;
    v1=v2;
    v2=appo;

    cout << endl << v1  << "  " << v2 << endl;

    return;
}

void scambia(int v[], int n, int i, int j){

    int appo;
    //Prima di procedere controllo che gli indici
    //forniti siano validi

    if(i>= 0 and j >=0 and i<n and j<n){
        appo = v[i];
        v[i]=v[j];
        v[j]=appo;
    }
    else{
        cout << endl << " Indici fuori range!!!!" << endl;
    }

    return;

}


void stampaArray(int v[], int dim){
    cout<< endl << "Stampo vettore:" << endl;

    for(int i=0; i<dim; i++)
     cout << endl << v[i];

    cout << endl;

    return;
}
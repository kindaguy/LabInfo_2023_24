#include <iostream>

using namespace std;

void scambia(int [], int, int, int );

void stampaArray(int [], int);

int eliminaEntrySwap(int [], int, int, int);
int eliminaEntryShift(int [], int, int, int);

int main(){

    int w[4]={1,2,3,4};
    int size = 4;
    int used = 4;

    cout << endl << "Prima di elimina";
    
    cout << endl << "used: " << used<< endl;
    
    stampaArray(w,used);
    
    used = eliminaEntryShift(w,size,used,2);
    
    cout << endl << "Dopo elimina";
    cout << endl << "used: " << used<< endl;
    stampaArray(w,used);
    
    return 0;
}


void scambia(int v[], int n, int i, int j){

    int appo;
    //Prima di procedere controllo che gli indici
    //forniti siano validi

    if(i >= 0 and j >=0 and i<n and j<n){
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

int eliminaEntrySwap(int v[], int size, int used, int where){
    cout << endl << "where: " << where << "; used-1: " << used-1 << endl;
    v[where] = v[used-1];
    
    //scambia(v,size,where,used-1);
    return used-1;

}

int eliminaEntryShift(int v[], int size, int used, int where){

    for(int i=where; i<used-1; i++)
        v[i] = v[i+1];
    
    return used-1;
}
#include <iostream>

using namespace std;

struct myArrayFloat{
    int size;  //Dimensione array
    int used;  //Numero elementi usati
    float *raw;//Array "fisico" 
};

void stampaMyArrayFloat(myArrayFloat vett){

        cout << endl << "Dimensione array: " << vett.size << endl;
        cout << endl << "Usati: " << vett.used << endl;
        for(int i=0; i<vett.used; i++){
            cout << endl  << vett.raw[i] << endl;
        }

        return;

}
int main(){

    myArrayFloat v;
    int appo;
    cout << endl << "dimensione array: ";
    cin >> appo;

    v.size = appo;
    v.used = 0;
    v.raw = new float[v.size];

    for(int i=0; i<v.size;i++){
        v.raw[i] = 0.2 *i;
        v.used++;
    }

    // cout << endl << "usati " << v.used << " elementi" << endl;
    // for(int i=0; i<v.used; i++){
    //     cout << v.raw[i] << endl;
    // }

    stampaMyArrayFloat(v);

    delete [] v.raw;
    v.raw = NULL;
    v.size = 0;
    v.used = 0;




    return 0;
}
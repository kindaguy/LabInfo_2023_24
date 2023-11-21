#include <iostream>
#include <fstream>

using namespace std;

bool *crivello(int nmax);

int main(){

    bool *v = NULL;
    int n_max;
    int dim;

    int p;

    int conta = 0;

    ofstream ofile;
    //Viene creato un vettore di char di 
    //lunghezza pari a caratteri nella stringa + 1;
    char nomefile[] = "primi.dat";
    char nomefile2[100];

    float dens;
    //Determino intervallo ricerca primi
    do{
        cout << "\nInserire valore N_max:";
        cin >>n_max;
    }while(n_max <=3);

    // //Assert: n_max >3
     dim = n_max+1;

    
    v = crivello(n_max);



    for(int i=2; i<dim; i++){
        if(v[i]) cout << endl << i;
    }
    cout << endl;
    //Marcato tutti i primi nel range
    for(int i=2; i<dim;i++)
        if(v[i])conta++;
    
    dens = (float)conta/n_max;

    cout << endl << "densita`  primi: " << dens<< endl;

    //ofile.open(nomefile);
    cout << endl << "Dove vuoi salvare?";
    cin >>nomefile2;
    ofile.open(nomefile2);

    if(ofile.fail()){
        cout << endl <<"Problema apertura file uscita! " << endl;
        return -1;
    }

    ofile << "N_max: " << n_max << endl;
    ofile << "Quanti primi: " << conta << endl;
    ofile << "Densita`:  " << dens << endl;
    for(int i=2; i<dim; i++){
        if(v[i]){
            ofile <<endl <<  i ;
        }
    }
    ofile << endl;

    ofile.close();

    
    delete [] v;
    return 0;
}

bool *crivello(int nmax){
    
    int dim;
    bool *v = NULL;
    int p;


    dim = nmax+1;

    //Alloco dinamicamente il vettore
    v=new bool[dim];
    //Inizializzo tutti gli elementi a true
    for(int i=0;i<dim; i++) v[i]=true;

    v[0] = false;
    v[1] = false; 

    p=2;
    
    do{
        //Ciclo interno: marco false tutti i 
        //multipli di p nel vettore
        for(int j = 2*p;j<dim;j += p) v[j]=false;
        p++;
        while(p<dim and v[p]==false){ 
             p++;
        }
    }while(p<dim);

    //bool *v
    return v;
}
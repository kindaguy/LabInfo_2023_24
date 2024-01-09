#include <iostream>
#include <fstream>

#include "sfera.h"
#include "libMyArraySfera.h"


using namespace std;

int main(){
  
  myArraySfera v;
  int err;

  err = caricaMyArrayFile("sfere.dat",v);

  stampa(v);
  cout << endl << " Numero di sfere:" << v.used << endl;
  

   return 0;
}



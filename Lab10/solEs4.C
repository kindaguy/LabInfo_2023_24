#include <iostream>
#include <fstream>

//Includiamo per generare errori Gaussiani
#include "../Librerie/libACaso.h"
#include "../Librerie/puntoR2.h"

double rileva(double time, double x0, double v, double mu, double sig);


int main(){

   ofstream file_out;
   int nn = 100;
   double t0 = 0.;
   double delta = 0.2;
   double x0 = 2;
   double v = 0.3;

   double mu = 0.;
   double sigma = 0.4;

   puntoR2 * vmisure = new puntoR2[nn];


   //Inizializza generatore numeri casuali
   initSeme();

   //Genero rilevazioni sporcate da errore Gaussiano.

   for(int i = 0; i<nn; i++){
      vmisure[i].x = delta*i;
      vmisure[i].y = rileva(delta*i,x0,v,mu,sigma);
   }

   //Registro rilevazioni su file
   file_out.open("rilevazioni.dat");


   for(int i =0; i < nn; i++)
      stampa(file_out,vmisure[i]);

   file_out << endl;
   
   file_out.close();


   delete [] vmisure;

   return 0;
}

double rileva(double time, double x0, double v, double mu, double sig){
   return x0 + v * time + randGaussiano(mu,sig);
}
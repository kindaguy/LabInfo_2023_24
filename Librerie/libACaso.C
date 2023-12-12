#include "libACaso.h"

double randUniforme(double minimo, double massimo){

   return (massimo-minimo)* (double)rand()/RAND_MAX+minimo;
}
double randGaussiano(double media, double stdVar){

   double u1,u2;
   u1 = randUniforme(0.,1.);
   u2 = randUniforme(0.,1.);
   
   return stdVar*sqrt(-2*log(u1))*cos(2*PI*u2)+media;


}
void initSeme(){
   srand(time(NULL));
}
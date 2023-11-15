#include <iostream>
#include <fstream>

using namespace std;

struct carattereTesto{
   char caratt;
   int occ;
   float freq;
};

int main(){

   ifstream file_in;
   ofstream file_out;

   int conta = 0;

   char appoc, appowaste;
   int appoint;

   int accu = 0;
   carattereTesto *vchar;

   file_in.open("appo.dat");

   file_in >> appoc >> appowaste >> appoint;
   while (!file_in.eof())
   {

      conta++;
      file_in >> appoc >> appowaste >> appoint;
   }

   cout << "Numero caratteri diversi: " << conta << endl;

   file_in.clear();
   file_in.seekg(0, ios::beg);

   vchar = new carattereTesto[conta];

   for (int i = 0; i < conta; i++)
      file_in >> vchar[i].caratt >> appowaste >> vchar[i].occ;

   file_in.close();

   for (int i = 0; i < conta; i++)
      accu += vchar[i].occ;

   file_out.open("frequenze.dat");
   for (int i = 0; i < conta; i++)
   {
      vchar[i].freq = (float)vchar[i].occ / accu;
      file_out << vchar[i].caratt << "\t" <<  vchar[i].occ << "\t" << vchar[i].freq << endl;
   }


  file_out.close();

  delete [] vchar;

   return 0;
}
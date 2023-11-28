#include <iostream>

using namespace std;

void dumb(int& r){

    r = r+1;

}
int main(){

    int a = 5;
    int& ra = a;

    cout << endl << a << endl;
    cout << endl << ra << endl;

    ra = 7;

    cout << endl << a << endl;
    cout << endl << ra << endl;

    dumb(a);
    cout << endl << a << endl;

    return 0;
}
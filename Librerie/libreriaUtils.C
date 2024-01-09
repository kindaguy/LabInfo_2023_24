#include "libreriaUtils.h"

void scambia(int *p1, int *p2){
    int appo;
    appo = *p1;
    *p1 = *p2;
    *p2 = appo;
}
void scambia(bool *p1, bool *p2){
    bool appo;
    appo = *p1;
    *p1 = *p2;
    *p2 = appo;

}
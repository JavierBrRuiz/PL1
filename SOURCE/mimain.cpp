#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Evaluacion.h"

int main(){

    Evaluacion e;
    int res;

    res = e.evaluar_expresionInfija((char*) "(((2*5)-(1*2))/(11-9))");
    cout << "El resultado es: " << res << endl;
    return 0;
}

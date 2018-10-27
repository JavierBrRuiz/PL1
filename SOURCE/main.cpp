#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Evaluacion.h"
#include <iostream>
using namespace std;
int main (){
    int resultado;
    Evaluacion e;
    cout << "expresion -> ((-2+5)-(3*9)/25)" << endl;
    resultado = e.evaluar_expresionInfija((char*)"((-2+5)-(3*9)/25)");

    cout << "El resultado es: " << resultado << endl;
    return 0;
}

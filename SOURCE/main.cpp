#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Evaluacion.h"
#include <iostream>
using namespace std;
int main (){
    int resultado;
    Evaluacion e;
    cout << "Expresion: -3*(5+7)" << endl;
    resultado = e.evaluar_expresionInfija((char*)"((2*50)-(100-90))");

    cout << "El resultado es: " << resultado << endl;
    return 0;
}

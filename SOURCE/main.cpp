#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Evaluacion.h"
#include <iostream>
using namespace std;
int main (){
    int resultado;
    Evaluacion e;
    cout << "Expresion: 7-4*3+11" << endl;
    resultado = e.evaluar_expresionInfija_2((char*)"7-4*3+11");

    cout << "El resultado es: " << resultado << endl;
    /*Pila p;
    p.Apilar(7);
    p.Apilar(8);
    p.Apilar(5);
    p.Apilar(3);
    p.Mostrar();
    cout << "Invertir...\n";
    p.Invertir();
    p.Mostrar();*/


    return 0;
}

#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Evaluacion.h"
#include <iostream>
using namespace std;
int main (){
    Evaluacion e;

    cout << "Expresion:\t 15-7*12\n";
    e.expresionInfija_a_expresionPostfija((char*)"12+8*9-(15+7)");


    /*int resultado;
    Evaluacion e;
    cout << "Expresion: 7-4*3+11" << endl;
    resultado = e.evaluar_expresionInfija_2((char*)"7+8*(5+6)");

    cout << "El resultado es: " << resultado << endl;*/
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

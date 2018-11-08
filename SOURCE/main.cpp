#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Evaluacion.h"
#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Lista.h"
#include <iostream>
using namespace std;
int main (){
    Evaluacion e;

    /*Lista l;
    l.Insertar_dcha(40, true);
    l.Insertar_dcha(7, false);
    l.Insertar_dcha(42, true);
    l.Insertar_dcha(40, true);
    l.Insertar_dcha(5, false);
    l.Insertar_dcha(43, true);
    l.Insertar_dcha(8, false);
    l.Insertar_dcha(41, true);
    l.Insertar_dcha(41, true);

    l.Mostrar();
    int i = Buscar_cierre(l, 3);

    cout << "La posicion de cierre respecto al primer * es:\t" << i << endl;*/
    cout << e.completar_parentesis((char*)"85*(4+6/(25+15))") << endl;
    //e.es_correcta((char*) "7+5*8+3");
    /*Lista l;

    l.Insertar_dcha(2, false);

    cout << "Deberia printearse: [2]\n";

    l.Mostrar();
    cout << "-------------------------------\n";
    cout << "Usamos eliminar en posicion 2.\n";
    l.Eliminar_pos(2);
    cout << "Deberia dar error\n";
    l.Mostrar();*/
    /*cout << "La longitud ahora es: \t" << l.Longitud() << endl;
    cout << "A continuacion vamos a insertar en la posicion 2 de nuevo.\n";
    l.Insertar_pos(14, false, 2);
    l.Mostrar();
    cout << "La longitud ahora es: \t" << l.Longitud() << endl;*/



    /*cout << "Valor inicial =\t" << l.Valor_inicial() << endl;
    cout << "Valor ultimo =\t" << l.Valor_ultimo() << endl;

    cout << "Cogiendo el valor de la posicion 2:\t" << l.Coger_valorPos(2) << endl;
    cout << "Cogiendo el bool de la posicion 3:\t" << l.Coger_esOpPos(3) << endl;

    cout << "Eliminamos el ultimo\n";
    l.Eliminar_ultimo();
    l.Mostrar();
    cout << "Eliminamos el primero\n";
    l.Eliminar_inicial();
    l.Mostrar();
    cout << "Valor inicial:\t" << l.Valor_inicial();
    cout << "Ultimo valor:\t" << l.Valor_ultimo();/*


    /*Evaluacion e;
    int res;
    cout << "Expresion:\t 15-7*12\n";
    res = e.evaluar_expresionPostfija(e.expresionInfija_a_expresionPostfija((char*)"15-7*12"));

    cout << "El resultado es: " << res << endl;*/

//((2*5)–(1*2))/(11-9)
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

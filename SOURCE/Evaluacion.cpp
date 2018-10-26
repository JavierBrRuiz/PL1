#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Evaluacion.h"
#include <iostream>
#include <math.h>
using namespace std;
Evaluacion::Evaluacion(){

}
Evaluacion::~Evaluacion(){

}
int Evaluacion::evaluar_expresionInfija(char* expresionInfija){
    int i = 0, cont = 0;
    int n_cifras = 0;
    char* p;
    //Recorremos la expresionInfija con un puntero a char
    for (p = expresionInfija; *p != '\0'; p++){
        //cout << "El valor de *p es: " << (int)*p << endl;

        /*Si el char es un digito sumamos 1 al contador
        de digitos(para digitos de varias cifras)
        y añadimos el digito a la pila de numeros*/
        if (es_Digito(*p)){
            cont++;
            //cout << "apilando *p - 48 en primer if" << endl;
            pNumeros.Apilar((int)(*p - 48));
        }

        /*Si no es digito, será un símbolo, por lo que
        añadimos el simbolo a la pila de simbolos
        y aplicamos nuestro "algoritmo" para formar
        los digitos de varias cifras*/
        else{
            if (cont > 1){
                for (i = 0; i < cont; i++){
            //        pNumeros.Mostrar();
            //        cout << "cima: " << pNumeros.Cima() << "i: " << i << endl;
                    n_cifras += pNumeros.Cima() * (pow(10, i));
                    pNumeros.Desapilar();
            //        cout << "algoritmo nCifras, valor: " << n_cifras << endl;
                }
            //    cout << "Valor n_cifras apilado: " << n_cifras << endl;
                pNumeros.Apilar(n_cifras);

            }
            //cout << "Apilando *p como simbolo: " << *p << endl;
            pSimbolos.Apilar((int)*p);
            //POSIBLE FUNCION *************************************************************************************
            int op1, op2, res, cierre = ')', abertura = '(';
            if (pSimbolos.Cima() == cierre){
                pSimbolos.Mostrar();
                system("read -p 'Press Enter to continue...' var");
                pSimbolos.Desapilar();
                pNumeros.Mostrar();
                system("read -p 'Press Enter to continue...' var");
                while ((pSimbolos.Cima() != abertura) || pSimbolos.Vacia()){
                    op2 = pNumeros.Cima();
                    pNumeros.Desapilar();
                    op1 = pNumeros.Cima();
                    pNumeros.Desapilar();
                    switch (pSimbolos.Cima()) {
                        case 43:
                            res = op1 + op2;
                            pSimbolos.Desapilar(); break;
                        case 45:
                            res = op1 - op2;
                            pSimbolos.Desapilar(); break;
                        case 42:
                            res = op1 * op2;
                            pSimbolos.Desapilar(); break;
                        case 47:
                            res = (op1-(op1%op2)) / op2; //division entera(formula para evitar errores con redondeo)
                            pSimbolos.Desapilar(); break;
                        default:
                            cout << "Error, simbolo incorrecto" << endl;
                    }
                    cout << op1 << (char) pSimbolos.Cima() << op2 << '=' << res << endl;
                    pNumeros.Apilar(res);
                    pNumeros.Mostrar();
                    system("read -p 'Press Enter to continue...' var");
                }
                pSimbolos.Desapilar();
                pSimbolos.Mostrar();
                system("read -p 'Press Enter to continue...' var");
            }
            cont = 0;
        }
    }

    /*cout << "Pila de numeros: " << endl;
    pNumeros.Mostrar();
    cout << "-------------------------------------------" << endl;
    cout << "Pila de simbolos" << endl;
    pSimbolos.Mostrar();*/
    return pNumeros.Cima();
}

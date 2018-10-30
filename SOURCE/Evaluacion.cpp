#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Evaluacion.h"
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define ERRORS "Error, simbolo incorrecto"

using namespace std;
Evaluacion::Evaluacion(){

}
Evaluacion::~Evaluacion(){

}
int Evaluacion::evaluar_expresionInfija(char* expresionInfija){
    int i = 0, cont = 0, n_cifras = 0;
    int op1, op2, res, cierre = ')', abertura = '(';
    bool negativo = false, op_realizada = false;
    /*
    op_realizada es un flag util para saber, en caso de que el siguiente
    simbolo sea '-', si actua como operador, o esta marcando un numero negativo
    */
    char* p;
    //Recorremos la expresionInfija con un puntero a char
    for (p = expresionInfija; *p != '\0'; p++){
        cout << *p << endl;
        //cout << "El valor de *p es: " << (int)*p << endl;

        /*Si el char es un digito sumamos 1 al contador
        de digitos(para digitos de varias cifras)
        y añadimos el digito a la pila de numeros*/
        //cout << "Cont en la iteracion anterior salio con valor: " << cont << endl;
        if (es_Digito(*p)){
            cont++;
            //cout << "apilando *p - 48 en primer if" << endl;
        //    cout << "Apilando un numero\n";
            if(!negativo){
                pNumeros.Apilar((int)(*p - 48));
            }else {
                pNumeros.Apilar((int)((*p - 48) * -1));
                negativo = false;
            }
        }

        /*Si no es digito, será un símbolo, por lo que
        añadimos el simbolo a la pila de simbolos
        y aplicamos nuestro "algoritmo" para formar
        los digitos de varias cifras*/
        else{
            if (cont > 1){
        //        cout << "If -> cont > 1" << endl;
                if(!negativo){
                    for (i = 0; i < cont; i++){
                //        pNumeros.Mostrar();
                //        cout << "cima: " << pNumeros.Cima() << "i: " << i << endl;
                        n_cifras += pNumeros.Cima() * (pow(10, i));
                        pNumeros.Desapilar();
                //        cout << "algoritmo nCifras, valor: " << n_cifras << endl;
                    }
                } else {
                    for (i = 0; i < cont; i++){
                //        pNumeros.Mostrar();
                //        cout << "cima: " << pNumeros.Cima() << "i: " << i << endl;
                        n_cifras -= pNumeros.Cima() * (pow(10, i));
                        pNumeros.Desapilar();
                //        cout << "algoritmo nCifras, valor: " << n_cifras << endl;
                    }
                    //negativo = false;
                }
            //    cout << "Valor n_cifras apilado: " << n_cifras << endl;
                pNumeros.Apilar(n_cifras);
                n_cifras = 0;
                pSimbolos.Apilar((int)*p);
            }else if(cont == 0 && *p == 45 && !op_realizada){
        //        cout << "If -> cont = 0 , *p = - y operacion realizada" << endl;
                negativo = true;
                op_realizada = false;
            }else{
        //        cout << "If de Apilar simbolo simplemente" << endl;
                pSimbolos.Apilar((int)*p);
            }
            //POSIBLE FUNCION *************************************************************************************
            //int op1, op2, res, cierre = ')', abertura = '(';
            if (pSimbolos.Cima() == cierre){
                op_realizada = true;
                pSimbolos.Mostrar();
                system("read -p 'Press Enter to continue...' var");
                pSimbolos.Desapilar();
                pNumeros.Mostrar();
                system("read -p 'Press Enter to continue...' var");
                while ((pSimbolos.Cima() != abertura) && !pSimbolos.Vacia()){
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
                            cout << ERRORS << endl;
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
        //cout << "Para la siguiente iteracion del bucle, cont valdra: " << cont << endl;
        //cout << "---------------------------------------------------------------------------------- " << endl;
    }

    /*cout << "Pila de numeros: " << endl;
    pNumeros.Mostrar();
    cout << "-------------------------------------------" << endl;
    cout << "Pila de simbolos" << endl;
    pSimbolos.Mostrar();*/
    pNumeros.Mostrar();
    cout << "----------------------------\n";
    pSimbolos.Mostrar();
    cout << "Vaciando pila...\n";
    pSimbolos.~Pila();
    pSimbolos.Mostrar();
    cout << negativo << endl;
    return pNumeros.Cima();
}
int Evaluacion::evaluar_expresionInfija_2(char* expresionInfija){
    char* expresion_nueva;
    char* p;
    int long_nueva = strlen(expresionInfija)+2;
    int i = 0, cont = 0, n_cifras = 0;
    int op1, op2, res, cierre = ')', abertura = '(', sim_aux, operador;
    bool negativo = false, op_realizada = false, op_preferente = false;


    expresion_nueva = new char[long_nueva];
    expresion_nueva[0] = '(';
    strcat(expresion_nueva, expresionInfija);
    strcat(expresion_nueva, ")");
    cout << "Expresion concatenada: " << expresion_nueva << endl;

    for (p = expresion_nueva; *p != '\0'; p++){
        cout << *p << endl;
        //cout << "El valor de *p es: " << (int)*p << endl;

        /*Si el char es un digito sumamos 1 al contador
        de digitos(para digitos de varias cifras)
        y añadimos el digito a la pila de numeros*/
        //cout << "Cont en la iteracion anterior salio con valor: " << cont << endl;
        if (es_Digito(*p)){

            //cout << "apilando *p - 48 en primer if" << endl;
        //    cout << "Apilando un numero\n";
            if(!negativo){
                pNumeros.Apilar((int)(*p - 48));
            }else {
                pNumeros.Apilar((int)((*p - 48) * -1));
                negativo = false;
            }
            cont++;
        }

        /*Si no es digito, será un símbolo, por lo que
        añadimos el simbolo a la pila de simbolos
        y aplicamos nuestro "algoritmo" para formar
        los digitos de varias cifras*/
        else{
            if (cont > 1){
        //        cout << "If -> cont > 1" << endl;
                if(!negativo){
                    for (i = 0; i < cont; i++){
                //        pNumeros.Mostrar();
                //        cout << "cima: " << pNumeros.Cima() << "i: " << i << endl;
                        n_cifras += pNumeros.Cima() * (pow(10, i));
                        pNumeros.Desapilar();
                //        cout << "algoritmo nCifras, valor: " << n_cifras << endl;
                    }
                } else {
                    for (i = 0; i < cont; i++){
                //        pNumeros.Mostrar();
                //        cout << "cima: " << pNumeros.Cima() << "i: " << i << endl;
                        n_cifras -= pNumeros.Cima() * (pow(10, i));
                        pNumeros.Desapilar();
                //        cout << "algoritmo nCifras, valor: " << n_cifras << endl;
                    }
                    //negativo = false;
                }
            //    cout << "Valor n_cifras apilado: " << n_cifras << endl;
                pNumeros.Apilar(n_cifras);
                n_cifras = 0;

                pSimbolos.Apilar((int)*p);
            }else if(*p == 45 && !op_realizada){
        //        cout << "If -> cont = 0 , *p = - y operacion realizada" << endl;
                negativo = true;
                op_realizada = false;
            }
            else if(*p == 42 || *p == 47){
                op_preferente = true;
                pSimbolos.Apilar((int)*p);
            }else{
        //        cout << "If de Apilar simbolo simplemente" << endl;
                pSimbolos.Apilar((int)*p);
            }
            //POSIBLE FUNCION *************************************************************************************
            //int op1, op2, res, cierre = ')', abertura = '(';
            if (pSimbolos.Cima() == cierre){
                op_realizada = true;
                pSimbolos.Mostrar();
                system("read -p 'Press Enter to continue...' var");
                pSimbolos.Desapilar();
                pNumeros.Mostrar();
                system("read -p 'Press Enter to continue...' var");
                while ((pSimbolos.Cima() != abertura) && !pSimbolos.Vacia()){
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
                            cout << ERRORS << endl;
                    }
                    cout << op1 << (char) pSimbolos.Cima() << op2 << '=' << res << endl;
                    pNumeros.Apilar(res);
                    pNumeros.Mostrar();
                    system("read -p 'Press Enter to continue...' var");
                }
                pSimbolos.Desapilar();
                pSimbolos.Mostrar();
                system("read -p 'Press Enter to continue...' var");
            }else if (pSimbolos.Cima() == abertura){
                op_preferente = false;
                // si el simbolo introducido es un parentesis
                // el antiguo operador ya no tiene preferencia
            }else if(op_preferente && (pSimbolos.Cima() != 42 && pSimbolos.Cima() != 47)){
                op2 = pNumeros.Cima();
                pNumeros.Desapilar();
                op1 = pNumeros.Cima();
                pNumeros.Desapilar();
                sim_aux = pSimbolos.Cima();
                pSimbolos.Desapilar();
                // guardamos este simbolo ya que es
                // el ultimo apilado, pero no es nuestro
                // operando, por lo que necesitamos reapilarlo
                operador = pSimbolos.Cima();
                switch (operador) {
                    case 42:
                        res = op1 * op2; break;
                    case 47:
                        res = (op1 - (op1 % op2)) / op2; break;
                    default:
                        cout << ERRORS << endl;
                }
                pSimbolos.Desapilar();
                pSimbolos.Apilar(sim_aux); // reapilamos
                pNumeros.Apilar(res);
            }
            cont = 0;
        }
        //cout << "Para la siguiente iteracion del bucle, cont valdra: " << cont << endl;
        //cout << "---------------------------------------------------------------------------------- " << endl;
    }

    /*cout << "Pila de numeros: " << endl;
    pNumeros.Mostrar();
    cout << "-------------------------------------------" << endl;
    cout << "Pila de simbolos" << endl;
    pSimbolos.Mostrar();*/
    pNumeros.Mostrar();
    cout << "----------------------------\n";
    pSimbolos.Mostrar();
    cout << "Vaciando pila...\n";
    pSimbolos.~Pila();
    pSimbolos.Mostrar();
    cout << negativo << endl;
    return pNumeros.Cima();
}

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
    /*int i = 0,*/int cont = 0; /*n_cifras = 0;*/
    int cierre = ')', abertura = '(';
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
                    Almacenar_multicifra_positivo(pNumeros, cont);
                } else {
                    Almacenar_multicifra_negativo(pNumeros, cont);
                    //negativo = false;
                }
            //    cout << "Valor n_cifras apilado: " << n_cifras << endl;
                //pNumeros.Apilar(n_cifras);
                //n_cifras = 0;
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
                Operar_parentesis(pNumeros, pSimbolos, abertura);
                cout << "Salimos de operar parentesis\n";
                //pSimbolos.Desapilar();
                //pSimbolos.Mostrar();
                //system("read -p 'Press Enter to continue...' var");
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
    int cont = 0;
    int op1, op2, res, cierre = ')', abertura = '(', sim_aux, operador;
    bool negativo = false, op_realizada = false, op_preferente = false, par_sobre_pref = false;

    //*encap_char = ' ';
    expresion_nueva = new char[long_nueva];
    expresion_nueva [0] = '$';
    strcat(expresion_nueva, expresionInfija);
    expresion_nueva[long_nueva-1] = '$';
    cout << "Expresion concatenada: " << expresion_nueva << endl;


    for (p = expresion_nueva; *p != '\0'; p++){
        cout << *p << endl;
        //cout << "El valor de *p es: " << (int)*p << endl;

        /*Si el char es un digito sumamos 1 al contador
        de digitos(para digitos de varias cifras)
        y añadimos el digito a la pila de numeros*/
        //cout << "Cont en la iteracion anterior salio con valor: " << cont << endl;
        if (es_Digito(*p)){
            cout << "Entro en if es_Digito\n";
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
            cout << "Entro en if es char\n";
            if (cont > 1){
                cout << "If -> cont > 1" << endl;
                if(!negativo){
                    Almacenar_multicifra_positivo(pNumeros, cont);
                } else {
                    Almacenar_multicifra_negativo(pNumeros, cont);
                    //negativo = false;
                }

            }else if(cont == 0 && *p == 45 && !op_realizada){
                cout << "If -> cont = 0 , *p = - y operacion realizada" << endl;
                negativo = true;
                op_realizada = false;
            }

            //cout << "Sigo vivo\n";
            if(*p == 42 || *p == 47){
                op_preferente = true;
                pSimbolos.Apilar((int)*p);
            }else if(op_preferente && *p == 40){
                par_sobre_pref = true;
                pSimbolos.Apilar((int)*p);
            }
            else{
            //        cout << "If de Apilar simbolo simplemente" << endl;
                if (*p != 36)
                    pSimbolos.Apilar((int)*p);
                else{
                    cout << "He leido $ pero no lo apilo\n";
                }
            }

            cout << "Sigo vivo\n";
            pSimbolos.Mostrar();
            system("read -p 'Press Enter to continue...' var");
            //POSIBLE FUNCION *************************************************************************************
            //int op1, op2, res, cierre = ')', abertura = '(';
            if (!pSimbolos.Vacia()){
                if (pSimbolos.Cima() == cierre && !op_preferente){
                    op_realizada = true;
                    pSimbolos.Mostrar();
                    system("read -p 'Press Enter to continue...' var");
                    pSimbolos.Desapilar();
                    pNumeros.Mostrar();
                    system("read -p 'Press Enter to continue...' var");
                    Operar_parentesis(pNumeros, pSimbolos, abertura);
                    cout << "Hemos salido de Operar parentesis, sigue todo bien\n";
                    pSimbolos.Mostrar();
                    system("read -p 'Press Enter to continue...' var");
                }else if(op_preferente && !par_sobre_pref && (pSimbolos.Cima() == 43 || pSimbolos.Cima() == 45)){
                    Operar_preferencia(pNumeros, pSimbolos);
                    op_preferente = false;
                }else if (op_preferente && pSimbolos.Cima() == 41){
                    Operar_parentesis(pNumeros, pSimbolos, abertura);
                    cout << "Hemos salido de Operar parentesis, sigue todo bien\n";

                    Operar_preferencia(pNumeros,pSimbolos);
                    op_preferente = false;
                    par_sobre_pref = false;
                }
            }
            cout << "Hemos acabado el bucle\n";
            cont = 0;
        }
        //cout << "Para la siguiente iteracion del bucle, cont valdra: " << cont << endl;
        //cout << "---------------------------------------------------------------------------------- " << endl;
    }
    //pSimbolos.Mostrar();
    pSimbolos.Invertir();
    pNumeros.Invertir();

    Operar_izq_dcha(pNumeros, pSimbolos);




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

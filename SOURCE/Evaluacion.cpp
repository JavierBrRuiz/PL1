#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/Headers/Evaluacion.h"
#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/Headers/PL1-lib.h"
Evaluacion::Evaluacion(){

}
Evaluacion::~Evaluacion(){

}
int Evaluacion::evaluar_expresionInfija(char* expresionInfija){
    int i = 1, cont = 0;
    int n_cifras;
    char* p;
    //Recorremos la expresionInfija con un puntero a char
    for (p = expresionInfija; *p != "\0"; p++){

        /*Si el char es un digito sumamos 1 al contador
        de digitos(para digitos de varias cifras)
        y añadimos el digito a la pila de numeros*/
        if (es_Digito(*p)){
            cont++;
            pNumeros.Apilar((int)(*p - 48));
        }

        /*Si no es digito, será un símbolo, por lo que
        añadimos el simbolo a la pila de simbolos
        y aplicamos nuestro "algoritmo" para formar
        los digitos de varias cifras*/
        else{
            if (cont > 1){
                for (i; i <= cont; i++){
                    nCifras += pNumeros.Cima() * ((10^i)/10);
                    pNumeros.Desapilar();
                }
                cont = 0;
            }
            pSimbolos.Apilar((int)*p);
        }
    }
}

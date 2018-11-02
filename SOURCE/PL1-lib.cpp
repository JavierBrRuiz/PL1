#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/PL1-lib.h"
#include <math.h>
#include <iostream>
#define ERRORS "Error, simbolo incorrecto"


using namespace std;

bool es_Digito(char c){
    int ctoi = c;

    return ((ctoi >= 48) && (ctoi <=57));
}
void Almacenar_multicifra_positivo(Pila &pNumeros, int cont){
    int i, n_cifras = 0;
    for (i = 0; i < cont; i++){
        n_cifras += pNumeros.Cima() * (pow(10, i));
        pNumeros.Desapilar();
    }
    pNumeros.Apilar(n_cifras);
}
void Almacenar_multicifra_negativo(Pila &pNumeros, int cont){
    int i, n_cifras = 0;
    for (i = 0; i < cont; i++){
        n_cifras -= pNumeros.Cima() * (pow(10, i));
        pNumeros.Desapilar();
    }
    pNumeros.Apilar(n_cifras);
}
void Operar_parentesis(Pila &pNumeros, Pila &pSimbolos, int abertura){
    int res, op1, op2;

    pSimbolos.Desapilar();
    while ((pSimbolos.Cima() != abertura) && !pSimbolos.Vacia()){
        op2 = pNumeros.Cima();
        pNumeros.Desapilar();
        op1 = pNumeros.Cima();
        pNumeros.Desapilar();
        switch (pSimbolos.Cima()) {
            case 43:
                res = op1 + op2;
                pSimbolos.Desapilar();
                pNumeros.Apilar(res); break;
            case 45:
                res = op1 - op2;
                pSimbolos.Desapilar();
                pNumeros.Apilar(res); break;
            case 42:
                res = op1 * op2;
                pSimbolos.Desapilar();
                pNumeros.Apilar(res); break;
            case 47:
                res = (op1-(op1%op2)) / op2; //division entera(formula para evitar errores con redondeo)
                pSimbolos.Desapilar();
                pNumeros.Apilar(res); break;
            default:
                cout << ERRORS << "Operar parentesis" << pSimbolos.Cima() << endl;
        }
        cout << op1 << (char) pSimbolos.Cima() << op2 << '=' << res << endl;

    }
    pSimbolos.Desapilar();
    pSimbolos.Mostrar();
    pNumeros.Mostrar();
    system("read -p 'Press Enter to continue...' var");
    cout << "Operar parentesis esta bien\n";
}
void Operar_preferencia(Pila& pNumeros, Pila& pSimbolos){
    cout << "Ha entrado en Operar_preferencia\n";
    int op1, op2, sim_aux, res;
    bool cima_preferente = false;
    if (pSimbolos.Cima() != 42 && pSimbolos.Cima() != 47){
        sim_aux = pSimbolos.Cima();
        pSimbolos.Desapilar();

    } else{
        cima_preferente = true;
    }
    while (!pSimbolos.Vacia() && (pSimbolos.Cima() == 42 || pSimbolos.Cima() == 47)){
        op2 = pNumeros.Cima();
        pNumeros.Desapilar();
        op1 = pNumeros.Cima();
        pNumeros.Desapilar();

        switch (pSimbolos.Cima()) {
            case 42:
                res = op1 * op2;
                cout << op1 << (char) pSimbolos.Cima() << op2 << '=' << res << endl;
                pSimbolos.Desapilar();
                pNumeros.Apilar(res); break;
            case 47:
                res = (op1 - (op1%op2)) / op2;
                cout << op1 << (char) pSimbolos.Cima() << op2 << '=' << res << endl;
                pSimbolos.Mostrar();
                cout << "Hasta aqui funciona\n";
                pSimbolos.Desapilar();

                pNumeros.Apilar(res);
                pNumeros.Mostrar(); break;

            default:
                cout << ERRORS << endl;
        }

    }
    cout << "Y esto funciona?\n";
    if (!cima_preferente)
        pSimbolos.Apilar(sim_aux);
}
void Operar_izq_dcha(Pila& pNumeros, Pila& pSimbolos){
    int op1, op2, res;
    while (!pSimbolos.Vacia()){
        op1 = pNumeros.Cima();
        pNumeros.Desapilar();

        op2 = pNumeros.Cima();
        pNumeros.Desapilar();

        switch (pSimbolos.Cima()){
            case 43:
                res = op1 + op2;
                cout << "La operacion realizada en esta iteracion es: \t" << op1 << "+" << op2 << "=" << res << endl;
                pNumeros.Apilar(res);
                pSimbolos.Desapilar(); break;

            case 45:
                res = op1 - op2;
                cout << "La operacion realizada en esta iteracion es: \t" << op1 << "-" << op2 << "=" << res << endl;
                pNumeros.Apilar(res);
                pSimbolos.Desapilar(); break;
            default:
                cout << ERRORS << endl;
        }
    }
}

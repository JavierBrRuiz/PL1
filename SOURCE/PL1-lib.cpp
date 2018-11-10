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
    pNumeros.Apilar(n_cifras, false);
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
    bool num_solo_parentesis;

    if (pSimbolos.Cima() == 40) {
        pSimbolos.Desapilar();
        num_solo_parentesis = true;
    }
    cout << "Entramos al bucle de realizar parentesis con las siguientes pilas:\n";
    pSimbolos.Mostrar();
    pNumeros.Mostrar();
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
    cout << "ANTES DE DESAPILAR.\n";
    pSimbolos.Mostrar();
    if (!num_solo_parentesis) pSimbolos.Desapilar(); 
    cout << "Despues de desapilar.\n";
    pSimbolos.Mostrar();
    pNumeros.Mostrar();
    system("read -p 'Press Enter to continue...' var");
    //cout << "Operar parentesis esta bien\n";
}
void Operar_preferencia(Pila& pNumeros, Pila& pSimbolos){
    //cout << "Ha entrado en Operar_preferencia\n";
    int op1, op2, sim_aux, res;
    bool cima_preferente = false;
    if (pSimbolos.Cima() != 42 && pSimbolos.Cima() != 47){
        sim_aux = pSimbolos.Cima();
        pSimbolos.Desapilar();
        cout << "Se ha guardado el simbolo: " << sim_aux << endl;

    } else{
        cima_preferente = true;
    }
    while (!pSimbolos.Vacia() && (pSimbolos.Cima() == 42 || pSimbolos.Cima() == 47)){
        cout << "Se mete en el while.\n";
        op2 = pNumeros.Cima();
        cout << "Se ha recogido op2 como: " << op2 << endl;
        pNumeros.Desapilar();
        op1 = pNumeros.Cima();
        cout << "Se ha recogido el op1 como: " << op1 << endl;
        pNumeros.Desapilar();
        cout << "La cima es: " << pSimbolos.Cima() << endl;
        switch (pSimbolos.Cima()) {
            case 42:
                res = op1 * op2;
                cout << op1 << (char) pSimbolos.Cima() << op2 << '=' << res << endl;
                pSimbolos.Desapilar();
                cout << "vemos como queda la pila.\n";
                pSimbolos.Mostrar();
                pNumeros.Apilar(res);
                cout << "Y vemos como queda la de numeros.\n";
                pNumeros.Mostrar(); break;
            case 47:
                res = (op1 - (op1%op2)) / op2;
                cout << op1 << (char) pSimbolos.Cima() << op2 << '=' << res << endl;
                pSimbolos.Mostrar();
            //    cout << "Hasta aqui funciona\n";
                pSimbolos.Desapilar();

                pNumeros.Apilar(res);
                pNumeros.Mostrar(); break;

            default:
                cout << ERRORS << endl;
        }

    }
    cout << "cima perferente?" << cima_preferente << endl;
    if (!cima_preferente) pSimbolos.Apilar(sim_aux);
    cout << "DEBERIA HABERSE APILADO\n";
    pSimbolos.Mostrar();
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
void Operar_Postfija(Pila& pNumeros, int operador){
    int op1, op2, res;
    op2 = pNumeros.Cima();
    pNumeros.Desapilar();

    op1 = pNumeros.Cima();
    pNumeros.Desapilar();

    switch (operador){
        case 42:
            res = op1 * op2;
            cout << op1 << "*" << op2 << "=" << res << endl;
            pNumeros.Apilar(res); break;
        case 43:
            res = op1 + op2;
            cout << op1 << "+" << op2 << "=" << res << endl;
            pNumeros.Apilar(res); break;
        case 45:
            res = op1 - op2;
            cout << op1 << "-" << op2 << "=" << res << endl;
            pNumeros.Apilar(res); break;
        case 47:
            res = (op1 - (op1 % op2)) / op2;
            cout << op1 << "/" << op2 << "=" << res << endl;
            pNumeros.Apilar(res); break;
        default:
            cout << ERRORS << "El simbolo tomado como operador es: " << operador << endl;
    }
}
int Pri_Simb(char* p){
    switch(*p){
        case ')':
            return 4;
        case '(':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            cout << ERRORS << endl;
    }
}
void Encolar_pSimbolos(Cola& cExpresionPostfija, Pila& pSimbolos){
    while (!pSimbolos.Vacia()){
        cExpresionPostfija.Encolar(pSimbolos.Cima(), pSimbolos.Cima_op());
        pSimbolos.Desapilar();
    }
}
int Buscar_cierre(Lista& lExpresion, int pos_l){
    cout << "Funcion Buscar cierre, antes de entrar en el bucle.\n";
    system("read -p 'Press Enter to continue...' var");

    int cont_parentesis, vtemp, i;
    bool es_op_tem;

    cont_parentesis = 1;
    for(i = pos_l + 2; cont_parentesis != 0; i++){
        cout << "i = " << i << endl;
        vtemp = lExpresion.Coger_valorPos(i);
        es_op_tem = lExpresion.Coger_esOpPos(i);
        if (es_op_tem && vtemp == 40) cont_parentesis++;
        else if (es_op_tem && vtemp == 41) cont_parentesis--;
    }

    return i - 1;
}
int Buscar_apertura(Lista& lExpresion, int pos_l){
    cout << "Funcion Buscar apertura, antes de entrar en el bucle.\n";
    system("read -p 'Press Enter to continue...' var");

    int cont_parentesis, vtemp, i;
    bool es_op_tem;

    cont_parentesis = 1;
    for(i = pos_l - 2; cont_parentesis != 0; i--){
        vtemp = lExpresion.Coger_valorPos(i);
        es_op_tem = lExpresion.Coger_esOpPos(i);
        if (es_op_tem && vtemp == 41) cont_parentesis++;
        else if(es_op_tem && vtemp == 40) cont_parentesis--;
        cout << " i dentro del bucle: " << i << endl;
    }
    cout << " i fuera del bucle: " << i << endl;
    return i + 1;
}
int Longitud_string(Lista& lExpresion){
    int desc_num, resto, i = 0;
    int long_string = 0;

    for (i; i < lExpresion.Longitud(); i++){
        if (lExpresion.Coger_esOpPos(i + 1)) long_string++;
        else{
            desc_num = lExpresion.Coger_valorPos(i + 1);
            while (desc_num > 9){
                desc_num = (desc_num - (desc_num % 10)) / 10;
                long_string++;
            }
            long_string++;
        }
    }
    return long_string;
}

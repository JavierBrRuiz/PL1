#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Evaluacion.h"

#include <math.h>
#include <string.h>
#include <stdlib.h>
#define ERRORS "Error, simbolo incorrecto"

//using namespace std;
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
            cout << "caracter leido: " << *p << endl;
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
                cout << "Aun no hemos operado\n";
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
    int op1, op2, aux, res, cierre = ')', abertura = '(', sim_aux, operador;
    bool negativo = false, op_realizada = false, op_preferente = false, par_sobre_pref = false;

    //*encap_char = ' ';
    expresion_nueva = new char[long_nueva];
    expresion_nueva [0] = '$';
    strcat(expresion_nueva, expresionInfija);
    expresion_nueva[long_nueva-1] = '$';
    cout << "Expresion concatenada: " << expresion_nueva << endl;


    for (p = expresion_nueva; *p != '\0'; p++){
        cout << "PRIMERA EJECUCION DEL BUCLE---------------------: \t" << *p << endl;
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
                if (*p != 36){
                    pSimbolos.Apilar((int)*p);
                    cout << "CARACTER APILADO: " << *p << endl;
                }
                else{
                    cout << "He leido $ pero no lo apilo\n";
                }
            }

            cout << "Sigo vivo el estado de los flags es: \n";
            cout << "Op_preferente\t" << op_preferente << endl;
            cout << "par_sobre_pref\t" << par_sobre_pref << endl;
            cout << "negativo\t" << negativo << endl;
            cout << "Op_realizada\t" << op_realizada << endl;
            pSimbolos.Mostrar();
            pNumeros.Mostrar();
            system("read -p 'Press Enter to continue...' var");
            cout << "Estamos alive\n";


            //POSIBLE FUNCION *************************************************************************************
            //int op1, op2, res, cierre = ')', abertura = '(';
            if (!pSimbolos.Vacia()){
                //cout << "Estamos alivex2\n";
                /*aux = pSimbolos.Cima();
                pSimbolos.Desapilar();
                if (!pSimbolos.Vacia())
                    simbolo_anterior = pSimbolos.Cima();
                pSimbolos.Apilar(aux);*/
                if (pSimbolos.Cima() == cierre && !op_preferente){
                    cout << "AQUI!!!!!\n";
                    op_realizada = true;
                    pSimbolos.Mostrar();
                    system("read -p 'Press Enter to continue...' var");
                    //pSimbolos.Desapilar();
                    pNumeros.Mostrar();
                    pSimbolos.Desapilar();
                    system("read -p 'Press Enter to continue...' var");
                    Operar_parentesis(pNumeros, pSimbolos, abertura);
                    cout << "Hemos salido de Operar parentesis, sigue todo bien\n";
                    pSimbolos.Mostrar();
                    system("read -p 'Press Enter to continue...' var");
                }else if(op_preferente && !par_sobre_pref && (pSimbolos.Cima() == 43 || pSimbolos.Cima() == 45 || pSimbolos.Cima() == 41)){
                    cout << "ME ESTOY METIENDO EN ESTE IF?\n";
                    if (pSimbolos.Cima() == 43 || pSimbolos.Cima() == 45){
                        Operar_preferencia(pNumeros, pSimbolos);
                        op_preferente = false;
                    }else if(pSimbolos.Cima() == 41 && pNumeros.Contar_pila() == 2){
                        op_realizada = true;
                        cout << "Entro else if, se van a mostrar las pilas.\n";
                        pNumeros.Mostrar();
                        pSimbolos.Mostrar();
                        Operar_preferencia(pNumeros, pSimbolos);
                        cout << "Comprobando pila de simbolos.\n";
                        pSimbolos.Mostrar();
                        pSimbolos.Desapilar();
                        cout << "------------------------------\n";
                        pSimbolos.Desapilar();
                        pSimbolos.Mostrar();
                    }
                    else{
                        cout << "segundo if, el else.\n";
                        cout << "Contamos la pila de numeros: " << pNumeros.Contar_pila() << endl;
                        Operar_preferencia(pNumeros, pSimbolos);
                        op_preferente = false;
                        cout << "De aqui salimos con esta pila de números y de simbolos.\n";
                        pSimbolos.Mostrar();
                        pNumeros.Mostrar();
                        cout << "Estamos Antes de operar parentesis.\n";
                        pSimbolos.Desapilar();
                        Operar_parentesis(pNumeros, pSimbolos, abertura);

                    }
                }else if (op_preferente && pSimbolos.Cima() == 41 && par_sobre_pref){
                    pSimbolos.Desapilar();
                    Operar_parentesis(pNumeros, pSimbolos, abertura);
                    cout << "Hemos salido de Operar parentesis, sigue todo bien\n";
                    pSimbolos.Mostrar();
                    Operar_preferencia(pNumeros,pSimbolos);
                    op_preferente = false;
                    par_sobre_pref = false;
                }
            }
            //cout << "Hemos acabado el bucle\n";
            cont = 0;
        }
        //cout << "Para la siguiente iteracion del bucle, cont valdra: " << cont << endl;
        //cout << "---------------------------------------------------------------------------------- " << endl;
    }
    //pSimbolos.Mostrar();
    pSimbolos.Invertir();
    pNumeros.Invertir();

    Operar_izq_dcha(pNumeros, pSimbolos);




    cout << "Pila de numeros: " << endl;
    pNumeros.Mostrar();
    cout << "-------------------------------------------" << endl;
    cout << "Pila de simbolos" << endl;
    pSimbolos.Mostrar();
    pNumeros.Mostrar();
    cout << "----------------------------\n";
    pSimbolos.Mostrar();
    cout << "Vaciando pila...\n";
    pSimbolos.~Pila();
    pSimbolos.Mostrar();
    cout << negativo << endl;
    return pNumeros.Cima();
}
Cola* Evaluacion::expresionInfija_a_expresionPostfija(char* expresionInfija){
    char* p;
    char* expresion_nueva;
    bool parentesis = false;
    int long_nueva = strlen(expresionInfija) + 2;
    expresion_nueva = new char [long_nueva];
    expresion_nueva[0] = '$';
    strcat(expresion_nueva, expresionInfija);
    expresion_nueva[long_nueva - 1] = '$';
    cout << "Expresion concatenada:\t " << expresion_nueva << endl;

    int pri_ant = 0, pri_act = 0, cont = 0;

    for (p = expresion_nueva; *p != '\0'; p++){
        cout << "Estamos leyendo:\t" << *p << endl;
        if (es_Digito(*p)){
            cExpresionPostfija.Encolar((int)(*p - 48), false);
            cont++;
        }
        else{
            if (cont > 1){
                /*
                Bloque if que detecta si un numero tiene mas de una cifra, y,
                en ese caso hace uso de una pila generica para aplicar el "algoritmo"
                y ser capaz de almacenar en el nodo de la cola el numero con todas
                sus cifras
                */
                while (!cExpresionPostfija.Vacia()) {
                    pGenerica.Apilar(cExpresionPostfija.Primero(), cExpresionPostfija.Primero_op());
                    cExpresionPostfija.Desencolar();
                }
                Almacenar_multicifra_positivo(pGenerica, cont);
                pGenerica.Mostrar();
                pGenerica.Invertir();
                cout << "Pila generica invertida.\n";
                pGenerica.Mostrar();

                while (!pGenerica.Vacia()){
                    cExpresionPostfija.Encolar(pGenerica.Cima(), pGenerica.Cima_op());
                    pGenerica.Desapilar();
                }

            }
            if (*p != 36){
                pri_act = Pri_Simb(p);
                if (*p == 41){
                    Encolar_pSimbolos(cExpresionPostfija, pSimbolos);
                    pri_ant = 0;
                }
                else if (pri_act == 3){
                    pri_ant = 0;
                }
                else if(pri_act > pri_ant){
                    pSimbolos.Apilar(*p, true);
                    pri_ant = pri_act;
                }else if (pri_act <= pri_ant){
                    Encolar_pSimbolos(cExpresionPostfija, pSimbolos);
                    pSimbolos.Apilar(*p, true);
                    pri_ant = pri_act;
                }
            }

            cont = 0;
        }
        cExpresionPostfija.Mostrar();
        pSimbolos.Mostrar();
        system("read -p 'Press Enter to continue...' var");

    }
    Encolar_pSimbolos(cExpresionPostfija, pSimbolos);
    cExpresionPostfija.Mostrar();
    return &cExpresionPostfija;
}
int Evaluacion::evaluar_expresionPostfija(char* expresion){
    evaluar_postfija = expresionInfija_a_expresionPostfija(expresion);

    while (!cExpresionPostfija.Vacia()){
        if (cExpresionPostfija.Primero_op()){
            cout << "Operador leido: " << cExpresionPostfija.Primero() << endl;
            cout << "Esta es la pila de numeros antes de realizar una operacion:\n";
            pNumeros.Mostrar();
            Operar_Postfija(pNumeros, cExpresionPostfija.Primero());
            cout << "Si esto esta bien acabamos de coger dos numeros de la pila y operarlos\n";
            cExpresionPostfija.Desencolar();
        }else{
            cout << "Leyendo un operando: " << cExpresionPostfija.Primero() << endl;
            cout << "Apilamos el operando.\n";
            pNumeros.Apilar(cExpresionPostfija.Primero(), false);
            pNumeros.Mostrar();
            cExpresionPostfija.Desencolar();
        }
    }
    return pNumeros.Cima();
}
bool Evaluacion::es_correcta(char* expresionInfija){
    char* p;
    char* expresion_nueva;
    int long_nueva = strlen(expresionInfija) + 2;
    int cont = 0, cont_ab = 0, cont_ci = 0, cont_op = 0, cont_num = 0, v;
    pNodo_l z;
    bool tiene_parentesis = false;

    expresion_nueva = new char[long_nueva];
    expresion_nueva[0] = '$';
    expresion_nueva = strcat(expresion_nueva, expresionInfija);
    expresion_nueva[long_nueva - 1] = '$';

    for (p = expresion_nueva; *p != '\0'; p++){
        if (es_Digito(*p)){
            lExpresion.Insertar_dcha((int)(*p - 48), false);
            cont++;
        }
        else{
            if (cont > 1){
                while(!lExpresion.Vacia()){
                    pGenerica.Apilar(lExpresion.Valor_inicial(), lExpresion.EsOp_inicial());
                    lExpresion.Eliminar_inicial();
                }
                Almacenar_multicifra_positivo(pGenerica, cont);

                while(!pGenerica.Vacia()){
                    lExpresion.Insertar_izqd(pGenerica.Cima(), pGenerica.Cima_op());
                    pGenerica.Desapilar();
                }
            }
            if (*p != 36) lExpresion.Insertar_dcha((int) *p, true);
            cont = 0;
            if (*p == 41 || *p == 40) tiene_parentesis = true;
        }
    }

    lExpresion.Mostrar();

    for(z = lExpresion.Nodo_inicial(); z != NULL; z = z->siguiente){
        v = z->valor;
        if (z->es_operador){
            if (v == 41){
                pEs_correcta.Desapilar();
            }else if(v == 40){
                pEs_correcta.Apilar(v, true);
            }else{
                cont_op++;
            }
        }
        else{
            cont_num++;
        }
    }
    if (tiene_parentesis)return cont_num == cont_op + 1 && pEs_correcta.Vacia();
    else return cont_num == (cont_op + 1);
}
Lista* Evaluacion::completar_parentesis(char* expresionInfija){
    char* p;
    char* expresion_nueva , *return_exp;
    cout << "Longitud antigua: " << strlen(expresionInfija) << endl;
    int long_nueva = strlen(expresionInfija) + 2;
    int cont = 0, i, h, v, pos_l = 0, cont_parentesis = 0, contg_pos = 0;
    int vdcha, vizqd, vtemp, desc_num, resto;
    bool vdcha_es_op, vizqd_es_op, es_op_tem;
    pNodo_l z;

    expresion_nueva = new char[long_nueva];
    expresion_nueva[0] = '$';
    strcat(expresion_nueva, expresionInfija);
    cout << "Expresion nueva: " << expresion_nueva << endl;
    cout << "longitud nueva: " << long_nueva << endl;
    expresion_nueva[long_nueva - 1] = '$';
    cout << "Expresion nueva: " << expresion_nueva << endl;

    cout << "Nos vamos a meter en el primer bucle, el de pasar string a lista.\n";

    for (p = expresion_nueva; *p != '\0'; p++){
        cout << "El valor leido es: " << (int) *p << endl;
        if (es_Digito(*p)){
            lExpresion.Insertar_dcha((int)(*p - 48), false);
            cont++;
        }
        else{
            if (cont > 1){
                while(!lExpresion.Vacia()){
                    pGenerica.Apilar(lExpresion.Valor_inicial(), lExpresion.EsOp_inicial());
                    lExpresion.Eliminar_inicial();
                }

                Almacenar_multicifra_positivo(pGenerica, cont);

                while(!pGenerica.Vacia()){
                    lExpresion.Insertar_izqd(pGenerica.Cima(), pGenerica.Cima_op());
                    pGenerica.Desapilar();
                }
            }
            if (*p > 36) lExpresion.Insertar_dcha(*p, true);
            cont = 0;
        }
    }
    cout << "Comprobando si se ha almacenado bien la expresion.\n";
    lExpresion.Mostrar();

    cout << "2o bucle, el mas importante.\n";
    cout << "Longitud expresion = " << lExpresion.Longitud() << endl;
    cout << "La posicion 4: " << lExpresion.Coger_esOpPos(4 ) << lExpresion.Coger_valorPos(4);

    for (z = lExpresion.Nodo_inicial(); z != NULL; z = z->siguiente){
        pos_l++;
        cout << "POSL " << pos_l<< endl;
        cout << "Longitud: " << lExpresion.Longitud() << endl;
        v = z->valor;
        cout << "Estamos recorriendo la lista, el valor que esta leyendo es: \t" << v << endl;
        cout << "Y el booleano del nodo leido es:\t" << z->es_operador << endl;

        if (z->es_operador && (v == 42 || v == 47)){
            vdcha = lExpresion.Coger_valorPos(pos_l + 1);
            vizqd = lExpresion.Coger_valorPos(pos_l - 1);
            vdcha_es_op = lExpresion.Coger_esOpPos(pos_l + 1);
            vizqd_es_op = lExpresion.Coger_esOpPos(pos_l -1);


            if (vdcha_es_op && vizqd_es_op){
                i = Buscar_cierre(lExpresion, pos_l);
                h = Buscar_apertura(lExpresion, pos_l);
                if (h == 1 || i == lExpresion.Longitud()){
                    lExpresion.Insertar_pos(41, true, i);
                    lExpresion.Insertar_pos(40, true, h);
                    pos_l++;
                }else{
                    if (lExpresion.Coger_valorPos(h - 1) != 40){
                        lExpresion.Insertar_pos(41, true, i);
                        lExpresion.Insertar_pos(40, true, h);
                        pos_l++;
                    }
                }


            }else if(vizqd_es_op && !vdcha_es_op){
                if (pos_l + 2 > lExpresion.Longitud()){
                    lExpresion.Insertar_dcha(41, true);
                    i = Buscar_apertura(lExpresion, pos_l);
                    lExpresion.Insertar_pos(40, true, i);
                    pos_l++;
                }
                else{
                    if (lExpresion.Coger_valorPos(pos_l + 2) != 41){
                        lExpresion.Insertar_pos(41, true, pos_l + 2);
                        i = Buscar_apertura(lExpresion, pos_l);
                        lExpresion.Insertar_pos(40, true, i);
                        pos_l++;
                    }
                }
            }else if(!vizqd_es_op && vdcha_es_op){
                if (pos_l == 2){
                    lExpresion.Mostrar();
                    lExpresion.Insertar_izqd(40, true);
                    pos_l++;
                    i = Buscar_cierre(lExpresion, pos_l);
                    system("read -p 'PULSA ENTER' var");
                    cout << "Hasta aqui llega.\n";
                    lExpresion.Insertar_pos(41, true, i);
                }
                else{
                    if(lExpresion.Coger_valorPos(pos_l - 2) != 40){
                        lExpresion.Insertar_pos(40, true, pos_l - 1);
                        pos_l++;
                        i = Buscar_cierre(lExpresion, pos_l);
                        lExpresion.Insertar_pos(41, true, i);
                    }
                }
            }else if (!vizqd_es_op && !vdcha_es_op){
                cout << "Aqui se mete.\n";
                cout << "POSICION Y LONGITUD: " << pos_l << " " << lExpresion.Longitud() << endl;
                if (pos_l != 2 && (pos_l + 2 < lExpresion.Longitud())){
                    if ((lExpresion.Coger_esOpPos(pos_l - 2) && lExpresion.Coger_valorPos(pos_l - 2) != 40) || (lExpresion.Coger_valorPos(pos_l + 2) && (lExpresion.Coger_valorPos(pos_l + 2) != 41))) {
                        lExpresion.Insertar_pos(41, true, pos_l + 2);
                        lExpresion.Insertar_pos(40, true, pos_l - 1);
                        pos_l++;
                    }
                }else if(pos_l == 2){
                    cout << "Aqui se mete?????\n";
                    lExpresion.Insertar_pos(41, true, pos_l + 2);
                    lExpresion.Insertar_izqd(40, true);
                    pos_l++;
                }else{
                    lExpresion.Insertar_dcha(41, true);
                    lExpresion.Insertar_pos(40, true, pos_l - 1);
                    pos_l++;
                }
            }
        }
        lExpresion.Mostrar();
    }
    pos_l = 0;
    for (z = lExpresion.Nodo_inicial(); z != NULL; z = z->siguiente){
        pos_l++;
        cout << "POSL " << pos_l<< endl;
        cout << "Longitud: " << lExpresion.Longitud() << endl;
        v = z->valor;
        cout << "Estamos recorriendo la lista, el valor que esta leyendo es: \t" << v << endl;
        cout << "Y el booleano del nodo leido es:\t" << z->es_operador << endl;

        if (z->es_operador && (v == 43 || v == 45)){
            vdcha = lExpresion.Coger_valorPos(pos_l + 1);
            vizqd = lExpresion.Coger_valorPos(pos_l - 1);
            vdcha_es_op = lExpresion.Coger_esOpPos(pos_l + 1);
            vizqd_es_op = lExpresion.Coger_esOpPos(pos_l -1);


            if (vdcha_es_op && vizqd_es_op){
                i = Buscar_cierre(lExpresion, pos_l);
                h = Buscar_apertura(lExpresion, pos_l);
                if (h == 1 || i == lExpresion.Longitud()){
                    lExpresion.Insertar_pos(41, true, i);
                    lExpresion.Insertar_pos(40, true, h);
                    pos_l++;
                }else{
                    if (lExpresion.Coger_valorPos(h - 1) != 40){
                        lExpresion.Insertar_pos(41, true, i);
                        lExpresion.Insertar_pos(40, true, h);
                        pos_l++;
                    }
                }
            }else if(vizqd_es_op && !vdcha_es_op){
                if (pos_l + 2 > lExpresion.Longitud()){
                    lExpresion.Insertar_dcha(41, true);
                    i = Buscar_apertura(lExpresion, pos_l);
                    lExpresion.Insertar_pos(40, true, i);
                    pos_l++;
                }
                else{
                    if (lExpresion.Coger_valorPos(pos_l + 2) != 41){
                        lExpresion.Insertar_pos(41, true, pos_l + 2);
                        i = Buscar_apertura(lExpresion, pos_l);
                        lExpresion.Insertar_pos(40, true, i);
                        pos_l++;
                    }
                }
            }else if(!vizqd_es_op && vdcha_es_op){
                if (pos_l == 2){
                    lExpresion.Insertar_izqd(40, true);
                    pos_l++;
                    i = Buscar_cierre(lExpresion, pos_l);
                    lExpresion.Insertar_pos(41, true, i);
                }
                else{
                    if(lExpresion.Coger_valorPos(pos_l - 2) != 40){
                        lExpresion.Insertar_pos(40, true, pos_l - 1);
                        pos_l++;
                        i = Buscar_cierre(lExpresion, pos_l);
                        lExpresion.Insertar_pos(41, true, i);
                    }
                }
            }else if (!vizqd_es_op && !vdcha_es_op){
                cout << "Aqui se mete.\n";
                cout << "POSICION Y LONGITUD: " << pos_l << " " << lExpresion.Longitud() << endl;
                if (pos_l != 2 && (pos_l + 2 < lExpresion.Longitud())){
                    if ((lExpresion.Coger_esOpPos(pos_l - 2) && lExpresion.Coger_valorPos(pos_l - 2) != 40) || (lExpresion.Coger_valorPos(pos_l + 2) && (lExpresion.Coger_valorPos(pos_l + 2) != 41))) {
                        lExpresion.Insertar_pos(41, true, pos_l + 2);
                        lExpresion.Insertar_pos(40, true, pos_l - 1);
                        pos_l++;
                    }
                }else if(pos_l == 2){
                    cout << "Aqui se mete?????\n";
                    lExpresion.Insertar_pos(41, true, pos_l + 2);
                    lExpresion.Insertar_izqd(40, true);
                    pos_l++;
                }else{
                    lExpresion.Insertar_dcha(41, true);
                    lExpresion.Insertar_pos(40, true, pos_l - 1);
                    pos_l++;
                }
            }
        }
        lExpresion.Mostrar();
    }
    lExpresion.Mostrar();
    /*char itoa;
    int j, k, longitud_string;
    cout << "Hasa antes del bucle llega.\n";
    cout << "La longitud de la lista es. " << lExpresion.Longitud() << endl;
    lExpresion.Mostrar();
    longitud_string = Longitud_string(lExpresion);
    cout << "La longitud del string será: " << longitud_string << endl;
    k = 0;
    return_exp = new char[longitud_string + 1];
    for (j = 0; k < lExpresion.Longitud(); j++){
        cout << "El valor de j es: " << j << endl;
        cout << "El valor de k es: " << k << endl;
        if (lExpresion.Coger_esOpPos(k + 1)){
            cout << "Si se ha metido en el primer if es_op es = " << lExpresion.Coger_esOpPos(k + 1) << endl;
            itoa = lExpresion.Coger_valorPos(k + 1);
            cout << "ITOA = " << itoa << endl;
            strcat(return_exp, &itoa);
            cout << "Vamos a ver si el valor se almacena en el array char: return_exp = " << return_exp << endl;
        }else{
            cout << "Si se mete en el else es por que es un numero, y su valor es: " << lExpresion.Coger_valorPos(k + 1) << endl;
            desc_num = lExpresion.Coger_valorPos(k + 1);
            while(desc_num > 9){
                cout << "Si esta aqui es por que el valor es mayor que nueve y se ejecuta el while.\n";
                resto = desc_num % 10;
                cout << "El resto es: " << resto << "Y se mete en la pila.\n";
                desc_num = (desc_num - resto) / 10;
                cout << "El siguiente numero que entra al bucle es: " << desc_num << endl;
                pGenerica.Apilar(resto, false);
            }
            pGenerica.Apilar(desc_num, false);
            pGenerica.Mostrar();
            while (!pGenerica.Vacia()){
                itoa = pGenerica.Cima() + 48;
                strcat(return_exp, &itoa);
                cout << "Metiendo en return exp la cima de la pila: " << (char) (pGenerica.Cima() + 48) << endl;
                pGenerica.Desapilar();
                cout << "return_exp ahora esta asi: return_exp = " << return_exp << endl;
                j++;
            }
        }
        if (k < lExpresion.Longitud()) k++;
    }
    return_exp[j] = '\0';
    lExpresion.Mostrar();
    cout << return_exp;
    cout << "La longitud de la cadena es: " << strlen (return_exp) << endl;
    return return_exp;*/
    return &lExpresion;
}

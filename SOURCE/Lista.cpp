#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Lista.h"
#include <iostream>
#define ERRORL "Error, has intentado acceder a una posicion de la lista que no existe.\n"
#define ERRORV "Error, has intentado recibir un valor de la lista, y esta está vacía.\n"
using namespace std;

Lista::Lista(){
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}
Lista::~Lista(){
}
bool Lista::Vacia(){
    return primero == NULL;
}
void Lista::Unitaria(int v, bool op){
    pNodo_l nuevo;
    nuevo = new Nodo_l(v, op, NULL, NULL);
    primero = nuevo;
    ultimo = nuevo;
    longitud++;
}
int Lista::Coger_valorPos(int posicion){
    int n;
    pNodo_l p;
    p = primero;
    n = 1;

    if (posicion == 0 || posicion > longitud){
        cout << ERRORL;
        return -1;
    }else if(posicion == 1){
        return primero->valor;
    }else{
        while (n < posicion){
            p = p->siguiente;
            n++;
        }
        return p->valor;
    }
}
bool Lista::Coger_esOpPos(int posicion){
    int n;
    pNodo_l p;

    p = primero;
    n = 1;

    if (posicion == 0 || posicion > longitud){
        cout << ERRORL;
        return -1;
    }else if(posicion == 1){
        return primero->es_operador;
    }else{
        while (n < posicion){
            p = p->siguiente;
            n++;
        }
        return p->es_operador;
    }
}
void Lista::Insertar_izqd(int v, bool op){

    if (!Vacia()){
        pNodo_l p;
        p = new Nodo_l(v, op, primero, NULL);
        primero->anterior = p;
        primero = p;
        longitud ++;
    }else{
        Unitaria(v, op);
    }
}
void Lista::Insertar_dcha(int v, bool op){
    if (!Vacia()){
        pNodo_l p;
        p = new Nodo_l(v, op, NULL, ultimo);

        ultimo->siguiente = p;
        ultimo = p;
        longitud++;
    }else{
        Unitaria(v, op);
    }
}
int Lista::Valor_inicial(){
    if (!Vacia()) return primero->valor;
    else{
        cout << ERRORV;
        return -1;
    }
}
bool Lista::EsOp_inicial(){
    if (!Vacia())return primero->es_operador;
    else{
        cout << ERRORV;
        return -1;
    }
}
pNodo_l Lista::Nodo_inicial(){
    return primero;
}
int Lista::Valor_ultimo(){
    if (!Vacia()) return ultimo->valor;
    else{
        cout << ERRORV;
        return -1;
    }
}
bool Lista::EsOp_ultimo(){
    if (!Vacia()) return ultimo->es_operador;
    else{
        cout << ERRORV;
        return -1;
    }
}
void Lista::Eliminar_inicial(){
    pNodo_l aux;
    aux = primero->siguiente;
    if (aux){
        aux->anterior = NULL;
        primero->siguiente = NULL;
        primero = aux;
    }else{
        primero = NULL;
        ultimo = NULL;
    }
    longitud--;
}
void Lista::Eliminar_ultimo(){
    pNodo_l aux;
    aux = ultimo->anterior;
    if (aux){
        aux->siguiente = NULL;
        ultimo->anterior = NULL;
        ultimo = aux;
    }else{
        primero = NULL;
        ultimo = NULL;
    }
    longitud--;
}
void Lista::Mostrar(){
    pNodo_l aux;
    aux = primero;
    cout << '[';
    while (aux){
        if (aux->es_operador)
            cout << (char)aux->valor;
        else cout << aux->valor;
            aux = aux->siguiente;
    }
    cout << ']'<< endl;
}
void Lista::Eliminar_pos(int posicion){
    if (Vacia()){
        cout << ERRORL << endl;
    }else if (posicion == 0 || posicion > longitud){
        cout << ERRORL << endl;
    }else{
        pNodo_l p;
        int n;
        p = primero;
        n = 1;

        while (n < posicion){
            p = p->siguiente;
            n++;
        }
        p->anterior->siguiente = p->siguiente;
        p->siguiente->anterior = p->anterior;
        p->siguiente = NULL;
        p->anterior = NULL;
        delete p;
        longitud--;
    }
}
void Lista::Insertar_pos(int v, bool op, int posicion){
    if (Vacia()){
        cout << ERRORL << endl;
    }else if (posicion == 0 || posicion > longitud){
        cout << ERRORL << endl;
    }else if (posicion == 1){
        Insertar_izqd(v, op);
    }else{
        pNodo_l p, nuevo;
        int n;

        nuevo = new Nodo_l(v, op, NULL, NULL);
        p = primero;
        n = 1;

        while (n < posicion - 1){
            p = p->siguiente;
            n++;
        }
        p->siguiente->anterior = nuevo;
        nuevo->siguiente = p->siguiente;
        p->siguiente = nuevo;
        nuevo->anterior = p;
        longitud++;
    }
}
int Lista::Longitud(){
    return longitud;
}

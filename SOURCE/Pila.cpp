#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Pila.h"
#include <iostream>
using namespace std;
Pila::Pila(){
    cima = NULL;
}
Pila::~Pila(){
    while (cima){
        Desapilar();
    }
}
void Pila::Apilar(int v){

    pNodo nuevo;
    nuevo = new Nodo(v, cima);
    cima = nuevo;

}
void Pila::Apilar(int v, bool op){
    pNodo nuevo;
    nuevo = new Nodo(v, op, cima);
    cima = nuevo;
}
int Pila::Cima(){
    return cima->valor;
}
bool Pila::Cima_op(){
    return cima->es_operador;
}

void Pila::Desapilar(){
    pNodo aux;
    if (cima == NULL){
        cout << "La pila está vacía.\n";
    }
    aux = cima;
    cima = aux->siguiente;

    delete aux;

}
bool Pila::Vacia(){
    return cima == NULL;
}
void Pila::Mostrar(){
    pNodo aux;
    aux = cima;
    while (aux){
        cout << aux->valor << "-" << aux->es_operador << endl;
        aux = aux->siguiente;
    }
}
void Pila::Invertir(){
    int vint;
    bool vbool;
    Pila pAux;
    Pila pAux_2;
    while (!Vacia()){
        vint = Cima();
        vbool = Cima_op();
        pAux.Apilar(vint, vbool);
        Desapilar();
    }
    while (!pAux.Vacia()){
        vint = pAux.Cima();
        vbool = pAux.Cima_op();
        pAux_2.Apilar(vint, vbool);
        pAux.Desapilar();
    }
    while (!pAux_2.Vacia()){
        vint = pAux_2.Cima();
        vbool = pAux_2.Cima_op();
        Apilar(vint, vbool);
        pAux_2.Desapilar();
    }
}

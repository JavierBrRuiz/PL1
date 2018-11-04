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
        cout << aux->valor << endl;
        aux = aux->siguiente;
    }
}
void Pila::Invertir(){
    int vinv;
    Pila pAux;
    Pila pAux_2;
    while (!Vacia()){
        vinv = Cima();
        pAux.Apilar(vinv);
        Desapilar();
    }
    while (!pAux.Vacia()){
        vinv = pAux.Cima();
        pAux_2.Apilar(vinv);
        pAux.Desapilar();
    }
    while (!pAux_2.Vacia()){
        vinv = pAux_2.Cima();
        Apilar(vinv);
        pAux_2.Desapilar();
    }
}

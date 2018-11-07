#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Cola.h"
#include <iostream>
#include <stddef.h>
using namespace std;
Cola::Cola(){
    primero = nullptr;
    ultimo = nullptr;
}
Cola::~Cola(){
    while (primero){
        Desencolar();
    }
}
void Cola::Encolar(int v, bool op){
    pNodo_c nuevo;
    nuevo = new Nodo_c(v, op);
    if (ultimo){
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    if (!primero){
        primero = nuevo;
    }
}
void Cola::Desencolar(){
    pNodo_c aux;
    if (primero){
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }else{
        cout << "Cola vacia\n";
    }
}
bool Cola::Vacia(){
    return primero == nullptr;
}
int Cola::Primero(){
    return primero->valor;
}
bool Cola::Primero_op(){
    return primero->es_operador;
}
int Cola::Ultimo(){
    return ultimo->valor;
}
void Cola::Mostrar(){
    pNodo_c aux;
    aux = primero;
    while (aux){
        cout << aux->valor << "-"<< aux->es_operador << " -> ";
        aux = aux->siguiente;
    }
    cout << endl;
}

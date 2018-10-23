#include "Cola.h"
#include <iostream>
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
void Cola::Encolar(int v){
    pNodo_c nuevo;
    nuevo = new Nodo_c(v);
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
int Cola::Ultimo(){
    return ultimo->valor;
}

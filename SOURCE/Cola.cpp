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
void Cola::Encolar(int v){
    pNodo nuevo;
    nuevo = new Nodo(v);
    if (ultimo){
        ultimo->siguiente = nuevo;
    }
    ultimo = nuevo;
    if (!primero){
        primero = nuevo;
    }
}
void Cola::Desencolar(){
    pNodo aux;
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

#include "Pila.h"
#include <iostream>
using namespace std;
Pila::Pila(){
    cima = NULL;
}
Pila::~Pila(){
}
void Pila::Apilar(int v){

    pNodo nuevo;
    nuevo = new Nodo(v, cima);
    cima = nuevo;

}

int Pila::Cima(){
    return cima->valor;
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

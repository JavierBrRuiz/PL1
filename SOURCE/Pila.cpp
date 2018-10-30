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
void Pila::Mostrar(){
    pNodo aux;
    aux = cima;
    while (aux){
        cout << aux->valor << endl;
        aux = aux->siguiente;
    }
}

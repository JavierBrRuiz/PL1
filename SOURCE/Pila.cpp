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

    pNodo_p nuevo;
    nuevo = new Nodo_p(v, cima);
    cima = nuevo;

}
void Pila::Apilar(int v, bool op){
    pNodo_p nuevo;
    nuevo = new Nodo_p(v, op, cima);
    cima = nuevo;
}
int Pila::Cima(){
    if(Vacia()) cout << "Error, no hay cima.\n";

    else return cima->valor;
}
bool Pila::Cima_op(){
    return cima->es_operador;
}
void Pila::Desapilar(){
    pNodo_p aux;
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
    pNodo_p aux;
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
int Pila::Contar_pila(){
    int cont = 0;
    Pila pAux;
    while (!Vacia()){
        pAux.Apilar(Cima());
        Desapilar();
        cont++;
    }
    while(!pAux.Vacia()){
        Apilar(pAux.Cima());
        pAux.Desapilar();
    }
    return cont;
}

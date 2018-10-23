#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
class Pila{
private:
    pNodo cima;

public:
    Pila();
    ~Pila();
    void Apilar(int v);
    int Cima();
    void Desapilar();
    bool Vacia();
};
#endif 

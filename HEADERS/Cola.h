#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

class Cola{
private:
    pNodo primero;
    pNodo ultimo;
    friend class Evaluacion;
public:
    Cola();
    ~Cola();
    void Encolar(int v);
    void Desencolar();
    bool Vacia();
    int Primero();
    int Ultimo();
};
#endif

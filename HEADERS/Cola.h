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
    void Encolar(int v, bool op);
    void Desencolar();
    bool Vacia();
    int Primero();
    bool Primero_op();
    int Ultimo();
    void Mostrar();
};
#endif

#ifndef COLA_H
#define COLA_H
#include "Nodo_c.h"

class Cola{
private:
    pNodo_c primero;
    pNodo_c ultimo;
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

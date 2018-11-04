#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
class Pila{
private:
    pNodo cima;
    friend class Evaluacion;
public:
    Pila();
    ~Pila();
    void Apilar(int v);
    void Apilar(int v, bool op);
    int Cima();
    bool Cima_op();
    void Desapilar();
    bool Vacia();
    void Mostrar();
    void Invertir();
};
#endif

#ifndef PILA_H
#define PILA_H
#include "Nodo_p.h"
class Pila{
private:
    pNodo_p cima;
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
    int Contar_pila();
};
#endif

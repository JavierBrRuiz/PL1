#ifndef NODO_P_H
#define NODO_P_H
#include <stddef.h>
class Nodo_p{

private:
    int valor;
    Nodo_p *siguiente;
    bool es_operador;
    friend class Pila;
public:
    Nodo_p(int v, Nodo_p* sig = NULL);
    Nodo_p(int v, bool op, Nodo_p* sig = NULL);
};
typedef Nodo_p* pNodo_p;
#endif

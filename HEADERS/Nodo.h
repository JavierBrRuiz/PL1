#ifndef NODO_H
#define NODO_H
#include <stddef.h>
class Nodo{

private:
    int valor;
    Nodo *siguiente;
    friend class Pila;
    friend class Cola;
public:
    Nodo(int v, Nodo* sig = NULL);
};
typedef Nodo* pNodo;
#endif

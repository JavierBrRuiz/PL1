#ifndef NODO_C_H
#define NODO_C_H
#include <stddef.h>
class Nodo_c{

private:
    int valor;
    bool es_operador;
    Nodo_c *siguiente;
    friend class Cola;
public:
    Nodo_c(int v, Nodo_c* sig = NULL);
    Nodo_c(int v, bool op, Nodo_c* sig = NULL);
};
typedef Nodo_c* pNodo_c;
#endif

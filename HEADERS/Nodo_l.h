#ifndef NODO_L_H
#define NODO_L_H
#include <stddef.h>
class Nodo_l{
private:
    int valor;
    bool es_operador;
    Nodo_l* siguiente;
    Nodo_l* anterior;
    friend class Lista;
    friend class Evaluacion;
public:
    Nodo_l(int v, Nodo_l* sig = NULL, Nodo_l* ant = NULL);
    Nodo_l(int v, bool op, Nodo_l* sig = NULL, Nodo_l* ant = NULL);
};
typedef Nodo_l* pNodo_l;
#endif

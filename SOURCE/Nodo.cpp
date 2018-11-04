#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Nodo.h"

Nodo::Nodo(int v, Nodo* sig){
    valor = v;
    siguiente = sig;
}
Nodo::Nodo(int v, bool op, Nodo* sig){
    valor = v;
    es_operador = op;
    siguiente = sig;
}

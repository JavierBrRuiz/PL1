#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Nodo_c.h"

Nodo_c::Nodo_c(int v, Nodo_c* sig){
    valor = v;
    siguiente = sig;
}
Nodo_c::Nodo_c(int v, bool op, Nodo_c* sig){
    valor = v;
    es_operador = op;
    siguiente = sig;
}

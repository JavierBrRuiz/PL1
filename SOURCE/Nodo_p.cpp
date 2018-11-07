#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Nodo_p.h"

Nodo_p::Nodo_p(int v, Nodo_p* sig){
    valor = v;
    siguiente = sig;
}
Nodo_p::Nodo_p(int v, bool op, Nodo_p* sig){
    valor = v;
    es_operador = op;
    siguiente = sig;
}

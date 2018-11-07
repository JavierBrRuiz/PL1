#include "/home/javi11br/Documents/C++/EstrucDatos/PL1/HEADERS/Nodo_l.h"

Nodo_l::Nodo_l(int v, Nodo_l* sig, Nodo_l* ant){
    valor = v;
    siguiente = sig;
    anterior = ant;
}
Nodo_l::Nodo_l(int v, bool op, Nodo_l* sig, Nodo_l* ant){
    valor = v;
    es_operador = op;
    siguiente = sig;
    anterior = ant;
}

#ifndef LISTA_H
#define LISTA_H
#include "Nodo_l.h"

class Lista{
private:
    pNodo_l primero;
    pNodo_l ultimo;
    int longitud;
    friend class Evaluacion;
public:
    Lista();
    ~Lista();
    bool Vacia();
    void Unitaria(int v, bool op);
    int Coger_valorPos(int posicion);
    bool Coger_esOpPos(int posicion);
    void Insertar_izqd(int v, bool op);
    void Insertar_dcha(int v, bool op);
    int Valor_inicial();
    bool EsOp_inicial();
    int Valor_ultimo();
    bool EsOp_ultimo();
    pNodo_l Nodo_inicial();
    void Eliminar_inicial();
    void Eliminar_ultimo();
    void Mostrar();
    void Insertar_pos(int v, bool op);
    void Eliminar_pos(int posicion);
    void Insertar_pos(int v, bool op, int posicion);
    int Longitud();
};

#endif

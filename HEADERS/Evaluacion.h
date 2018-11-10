#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include "PL1-lib.h"
#include <iostream>

using namespace std;
class Evaluacion{
private:
    Pila pSimbolos, pNumeros;
    Cola cExpresionPostfija;
    Cola* evaluar_postfija;
    Pila pGenerica;
    Pila pEs_correcta;
    Lista lExpresion;
public:
    Evaluacion();
    ~Evaluacion();
    int evaluar_expresionInfija(char* expresionInfija);
    int evaluar_expresionInfija_2(char* expresionInfija);
    Cola* expresionInfija_a_expresionPostfija(char* expresionInfija);
    int evaluar_expresionPostfija(char* expresion);
    bool es_correcta(char* expresionInfija);
    Lista* completar_parentesis(char* expresionInfija);
};

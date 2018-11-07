#include "Cola.h"
#include "Pila.h"
#include "Lista.h"
#include "PL1-lib.h"

class Evaluacion{
private:
    Pila pSimbolos, pNumeros;
    Cola cExpresionPostfija;
    Pila pGenerica;
    Lista lExpresion;
public:
    Evaluacion();
    ~Evaluacion();
    int evaluar_expresionInfija(char* expresionInfija);
    int evaluar_expresionInfija_2(char* expresionInfija);
    Cola* expresionInfija_a_expresionPostfija(char* expresionInfija);
    int evaluar_expresionPostfija(Cola* cExpresionPostfija);
    bool es_correcta(char* expresionInfija);
    char* completar_parentesis(char* expresionInfija);
};

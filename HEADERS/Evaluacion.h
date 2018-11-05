#include "Cola.h"
#include "Pila.h"
#include "PL1-lib.h"

class Evaluacion{
private:
    Pila pSimbolos, pNumeros;
    Cola cExpresionPostfija;
    Pila pGenerica;
public:
    Evaluacion();
    ~Evaluacion();
    int evaluar_expresionInfija(char* expresionInfija);
    int evaluar_expresionInfija_2(char* expresionInfija);
    Cola* expresionInfija_a_expresionPostfija(char* expresionInfija);
    int evaluar_expresionPostfija(Cola* cExpresionPostfija);
    bool infija_correcta(char* expresionInfija);
    char* completar_parentesis(char* expresionInfija);
};

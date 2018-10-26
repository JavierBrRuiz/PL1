#include "Cola.h"
#include "Pila.h"
#include "PL1-lib.h"

class Evaluacion{
private:
    Pila pSimbolos, pNumeros;
    Cola cExpresionPostfija;
public:
    Evaluacion();
    ~Evaluacion();
    int evaluar_expresionInfija(char* expresionInfija);
    int evaluar_expresionInfija_2(char* expresionInfija);
    char* expresionInfija_a_expresionPostfija(char* expresionInfija);
    int evaluar_expresionPostfija(char* expresionPostfija);
    bool infija_correcta(char* expresionInfija);
    char* completar_parentesis(char* expresionInfija);
};

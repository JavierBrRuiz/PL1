#include "Pila.h"
#include "Cola.h"
#include "Lista.h"

bool es_Digito(char c);
void Almacenar_multicifra_positivo(Pila &pNumeros, int cont);
void Almacenar_multicifra_negativo(Pila &pNumeros, int cont);
void Operar_parentesis(Pila &pNumeros, Pila &pSimbolos, int abertura);
void Operar_preferencia(Pila& pNumeros, Pila& pSimbolos);
void Operar_izq_dcha(Pila& pNumeros, Pila& pSimbolos);
int Pri_Simb(char* p);
void Encolar_pSimbolos(Cola& cExpresionPostfija, Pila& pSimbolos);
void Operar_Postfija(Pila& pNumeros, int operador);
int Buscar_cierre(Lista& lExpresion, int pos_l);
int Buscar_apertura(Lista& lExpresion, int pos_l);
int Longitud_string(Lista& lExpresion);

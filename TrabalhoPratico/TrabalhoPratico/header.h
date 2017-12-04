/***************************************************************
* Autores: António Faneca (21250021), Amadeus Alves
* Para: ISEC - Instituto Superior de Engenharia de Coimbra
* Versão: V0.5
* Data: 04/12/2017 19h30
/***************************************************************/

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <locale.h>
#include <fstream>
#include "Formiga.h"
#include "Mundo.h"
#include "Ninho.h"
using namespace std;



string executaFicheiro(string nomeFicheiro, int linha);
void processaComandos(bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa);
void continuarJogo();
void sair();
bool valida(vector<string> palavra, int *limite, double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida);
vector<string> divideEmPalavras(string str);
bool processaComandos(string nomeFicheiro, bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa, int *limite,
double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida);
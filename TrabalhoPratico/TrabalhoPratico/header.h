#ifndef HEADER_H
#define HEADER_H
#pragma once

/***************************************************************
* Autores: António Faneca (21250021), Amadeus Alves (21260399)
* Para: ISEC - Instituto Superior de Engenharia de Coimbra
* Versão: V1.0
* Data: 15/12/2017 02:05
/***************************************************************/

#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime> 
#include <tchar.h>
#include "Consola.h"
#include "Interface.h"

class Mundo;
//class Interface;
class Formiga;
class Elementos;
class Comunidade;
class Ninho;
using namespace std;

static vector<vector<char>> grelha;
string executaFicheiro(string nomeFicheiro, int linha);
void processaComandos(bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa, bool *inicio);
bool valida(vector<string> palavra, int *limite, double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida);
vector<string> divideEmPalavras(string str);
bool processaComandos(string nomeFicheiro, bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa, bool *inicio, int *limite,
double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida, Mundo &mundo);
void iniciaSimul(int *limite, double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas,
	double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida, Mundo &mundo); 
bool ocupada(int x, int y);
void addGrelha(int x, int y, char avatar);
bool validaPos(int x, int y, int dx, int dy, int limite);
void movimentos(Mundo & mundo);
void listaMundo(Mundo & mundo);
void listaNinho(int id, Mundo & mundo);
void listaPosicao(int x, int y, Mundo & mundo);
#endif
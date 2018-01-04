#ifndef HEADER_H
#define HEADER_H
#pragma once

/***************************************************************
* Autores: Ant�nio Faneca (21250021), Amadeus Alves (21260399)
* Para: ISEC - Instituto Superior de Engenharia de Coimbra
* Vers�o: V1.5
* Data: 04/01/2018 12:30
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

class Processador
{
private:
	Interface i2;
public:
	Processador();
	~Processador();

	int contaLinhasFicheiro(string nomeFicheiro);
	string executaFicheiro(string nomeFicheiro, int linha);
	void processaComandos(bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa, bool *inicio, Interface &i1);
	bool valida(vector<string> palavra, int *limite, double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida);
	vector<string> divideEmPalavras(string str);
	bool processaComandos(string nomeFicheiro, bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa, bool *inicio, int *limite,
		double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida, Mundo &mundo, Interface &i1);
	void iniciaSimul(int *limite, double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas,
		double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida, Mundo &mundo);
};
#endif
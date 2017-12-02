#pragma once
#include "header.h"
class Ninho;
class Mundo
{

private:
	int limite;
	double energiaInicialNinhos;
	double valorEnergia;
	int posComMigalhas;
	double energiaInicialMigalhas;
	int maxMigalhas;
	double energiaTransferida;
	vector<Ninho> ninhos;
public:
	Mundo(int limite, double energiaInicialNinhos, double valorEnergia, int posComMigalhas, int energiaInicialMigalhas, int maxMigalhas, double energiaTransferida);
	~Mundo();
};


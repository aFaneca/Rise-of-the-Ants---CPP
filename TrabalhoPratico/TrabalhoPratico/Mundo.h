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
	//vector<char> grelha;
	vector<vector<char>>  grelha;
	bool iniciado;
public:
	Mundo();
	void Init(int limite, double energiaInicialNinhos, double valorEnergia, int posComMigalhas, double energiaInicialMigalhas, int maxMigalhas, double energiaTransferida);
	~Mundo();
	string toString();
	vector<vector<char>> getMundo();
	int getLimite();
	bool getIniciado();
	void setEnergiaInicialNinhos(double v);
	void setValorEnergia(double v);
	void setPosComMigalhas(int v);
	void setEnergiaInicialMigalhas(double v);
	void setMaxMigalhas(int v);
	void setEnergiaTransferida(double v);

	//void mostraMundo();
};


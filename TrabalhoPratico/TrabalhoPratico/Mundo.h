#ifndef MUNDO_H
#define MUNDO_H
#pragma once
#include "Processador.h"
#include "Elementos.h"
//class Comunidade;
class Mundo : public Elementos
{

private:
	int limite;
	double energiaInicialNinhos;
	double valorEnergia;
	int posComMigalhas;
	double energiaInicialMigalhas;
	int maxMigalhas;
	double energiaTransferida;
	vector<Comunidade> comunidades;
	bool iniciado;
	

public:
	
	Mundo();
	void Init(int limite, double energiaInicialNinhos, double valorEnergia, int posComMigalhas, double energiaInicialMigalhas, int maxMigalhas, double energiaTransferida);
	~Mundo();
	vector<vector<char>> grelha;
	string toString();
	int getLimite();
	bool getIniciado();
	void setEnergiaInicialNinhos(double v);
	void setValorEnergia(double v);
	void setPosComMigalhas(int v);
	void setEnergiaInicialMigalhas(double v);
	void setMaxMigalhas(int v);
	void setEnergiaTransferida(double v);
	void addComunidade(int posy, int posx);
	vector<Comunidade> & getComunidades();
	void addFormiga2Ninho(int idNinho, char tipoFormiga, int posx = -1, int posy = -1);
	bool ocupada(int x, int y);
	bool validaPos(int x, int y, int dx, int dy);
	void addGrelha(int x, int y, char avatar);
	vector<vector<char>> getGrelha();
	void addEnergia2Ninho(int idNinho, int energ);
	bool temFormiga(int x, int y);
	void addEnergia2Formiga(int x, int y, int energia);
};

#endif
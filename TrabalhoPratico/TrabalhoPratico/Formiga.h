#ifndef FORMIGA_H
#define FORMIGA_H
#pragma once
#include "Regra.h"
#include "Processador.h"
#include "Elementos.h"
#include "Ninho.h"
#include <algorithm>    // std::max
#include <cmath>        // std::abs

class Regra;
class Formiga : public Elementos
{
private:
	static int i;
	int id;
	char tipo;
	vector<Regra *> regras;
	Ninho *n;


public:
	Formiga(char tipo, int posx, int posy, Ninho &n);
	~Formiga();
	char getTipo();
	void mover();
	void setPosx(int x);
	void setPosy(int y);
	int getId();
	int getEnergia();
	void suicidio();
	void atualizaEnergia(char tipo, int novaPosX, int novaPosy);
	void setPropriedades(char tipo);
	vector<Regra *> getRegras();
	int calculaMovimento(int x1, int y1);
	bool podeMoverPara(int x1, int y1);
	Ninho * getNinho();
	void correRegras();
};

#endif
#ifndef NINHO_H
#define NINHO_H
#pragma once

#include "Processador.h"
#include "Elementos.h"
//class Formiga;
class Ninho : public Elementos
{
private:
	vector<Formiga *> formigas;
	static int i;
	int id;
	char tipo;
public:
	Ninho(int posx, int posy);
	~Ninho();
	int getId();
	vector<Formiga *> getFormigas();
	void addFormiga(char tipo, Mundo & mundo, int posx = -1, int poxy = -1);
	void addEnergia(int valor);
	void mataFormiga(int idFormiga);
};

#endif
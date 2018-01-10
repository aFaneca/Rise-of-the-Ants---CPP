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
	Mundo * m;
	Ninho(int posx, int posy, int energiaInicial, Mundo &m);
	~Ninho();
	int getId();
	vector<Formiga *> getFormigas();
	void addFormiga(char tipo, int posx = -1, int poxy = -1);
	void addEnergia(int valor);
	void mataFormiga(int idFormiga);
	Mundo * getMundo();
};

#endif
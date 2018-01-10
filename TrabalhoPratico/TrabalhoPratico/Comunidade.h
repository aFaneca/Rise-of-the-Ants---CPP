#ifndef COMUNIDADE_H
#define COMUNIDADE_H
#pragma once
#include "Processador.h"
#include "Elementos.h"

#include "Ninho.h"
class Comunidade : public Elementos
{

private:
	Ninho *ninho;
	int id;
	Mundo *mundo;
public:
	Comunidade(int posx, int posy, int energiaInicial, Mundo &m);
	~Comunidade();
	Ninho* getNinho();
	int getId();
	void destruir();
	int encontraFormiga(int x, int y);
	void addEnergia2Formiga(int idFormiga, int valor);
	void mataFormiga(int idFormiga);
};

#endif
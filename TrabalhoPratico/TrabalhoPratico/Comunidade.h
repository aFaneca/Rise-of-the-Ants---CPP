#ifndef COMUNIDADE_H
#define COMUNIDADE_H
#pragma once
#include "header.h"
#include "Elementos.h"

#include "Ninho.h"
class Comunidade : public Elementos
{
private:
	Ninho *ninho;
	int id;
public:
	Comunidade(int posx, int posy);
	~Comunidade();
	Ninho* getNinho();
	int getId();
	void destruir();
};

#endif
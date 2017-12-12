#ifndef FORMIGA_H
#define FORMIGA_H
#pragma once
#include "header.h"
#include "Elementos.h"
class Formiga : public Elementos
{
private:
	static int i;
	int id;
	char tipo;

public:

	Formiga(char tipo, int posx, int posy);
	~Formiga();
	char getTipo();
};

#endif
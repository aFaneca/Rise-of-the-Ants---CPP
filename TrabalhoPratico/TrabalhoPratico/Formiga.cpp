#include "Formiga.h"


int Formiga::i = 0;

Formiga::Formiga(char tipo, int posx, int posy)
{
	this->id = i++;
	this->avatar = 157;
	this->tipo = tipo;
	this->posx = posx;
	this->posy = posy;
}


Formiga::~Formiga()
{
}

char Formiga::getTipo()
{
	return this->tipo;
}

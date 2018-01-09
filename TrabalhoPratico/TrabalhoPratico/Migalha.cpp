#include "Migalha.h"


int Migalha::i = 0;

Migalha::Migalha(int posx, int posy, int energiaInicial)
{
	this->posx = posx;
	this->posy = posy;
	
	this->energia = this->energiaInicial = energiaInicial;
	this->avatar = 157;
	this->id = i++;
}


Migalha::~Migalha()
{
}

int Migalha::getId()
{
	return this->id;
}

void Migalha::iteracao()
{

	// PERDE 1 UNIDADE DE ENERGIA
	this->energia--;
}

int Migalha::getEnergiaInicial()
{
	return this->energiaInicial;
}

#include "Comunidade.h"



Comunidade::Comunidade(int posx, int posy) 
{
	cout << "Nova comunidade adicionada!";
	//Ninho n(posx, posy);
	//ninho = &n;
	ninho = new Ninho(posx, posy);
	
	this->id = (ninho)->getId();
	cout << "ID: " << this->id;
	
}


Comunidade::~Comunidade()
{

	//delete ninho;
}

Ninho * Comunidade::getNinho()
{
	return this->ninho;
}

int Comunidade::getId()
{
	return this->id;
}

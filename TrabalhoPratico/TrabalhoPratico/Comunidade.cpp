#include "Comunidade.h"

#include "Formiga.h"

Comunidade::Comunidade(int posx, int posy) 
{
	cout << "Nova comunidade adicionada!";
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

void Comunidade::destruir()
{
	delete ninho;
}

int Comunidade::encontraFormiga(int x, int y)
{
	for (int i = 0; i < ninho->getFormigas().size(); i++) {
		if (ninho->getFormigas()[i].posx == x && ninho->getFormigas()[i].posy == y)
			return ninho->getFormigas()[i].getId();
	}

	return -1; // N�O ENCONTROU QUALQUER FORMIGA DESTA COMUNIDADE NA POSI��O (X,Y)
}

void Comunidade::addEnergia2Formiga(int idFormiga, int valor)
{
	for (int i = 0; i < ninho->getFormigas().size(); i++) {
		if (ninho->getFormigas()[i].getId() == idFormiga)
			ninho->getFormigas()[i].energia += valor;
	}
}

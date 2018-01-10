#include "Comunidade.h"

#include "Formiga.h"

Comunidade::Comunidade(int posx, int posy, int energiaInicial, Mundo &m) 
{
	cout << "Nova comunidade adicionada!";
	this->mundo = &m;
	mundo->getLimite();
	ninho = new Ninho(posx, posy, energiaInicial, m);
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
	//delete this;
}

int Comunidade::encontraFormiga(int x, int y)
{
	for (int i = 0; i < ninho->getFormigas().size(); i++) {
		if (ninho->getFormigas()[i]->posx == x && ninho->getFormigas()[i]->posy == y)
			return ninho->getFormigas()[i]->getId();
	}

	return -1; // NÃO ENCONTROU QUALQUER FORMIGA DESTA COMUNIDADE NA POSIÇÃO (X,Y)
}

void Comunidade::addEnergia2Formiga(int idFormiga, int valor)
{
	for (int i = 0; i < ninho->getFormigas().size(); i++) {
		if (ninho->getFormigas()[i]->getId() == idFormiga)
			ninho->getFormigas()[i]->energia += valor;
	}
}



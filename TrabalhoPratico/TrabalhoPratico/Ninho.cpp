#include "Ninho.h"
#include "Mundo.h"
#include "Formiga.h"
int Ninho::i = 1;

Ninho::Ninho(int posx, int posy)
{
	this->id = i++;
	this->avatar = 178;
	this->posx = posx;
	this->posy = posy;
}


Ninho::~Ninho()
{
}

int Ninho::getId()
{
	return this->id;
}

vector<Formiga> Ninho::getFormigas()
{
	return this->formigas;
}



void Ninho::addFormiga(char tipo, Mundo & mundo)
{
	int px, py;
	int max = mundo.getLimite();
	int min = 1;
	//px = py = 6;
	//ATRIBUIR POSICAO ALEATORIA E VERIFICAR SE ESTA OCUPADA - REPETIR ATE FALSE


	do {
		srand(time(0));
		px = rand() % (max - min + 1) + min;
		py = rand() % (max - min + 1) + min;
		
	} while (ocupada(px,py));

	Formiga f(tipo, px, py);
	formigas.push_back(f);
}

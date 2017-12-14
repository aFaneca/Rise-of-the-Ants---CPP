#include "Formiga.h"


int Formiga::i = 0;

Formiga::Formiga(char tipo, int posx, int posy)
{
	this->id = i++;
	this->tipo = tipo;
	if (tipo == 'E') {
		this->avatar = 'E';
		this->raioVisao = 10;
		this->energia = 200; 
	}
	
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

void Formiga::mover(int limite)
{
	int tentativas = 0;
	do {
		this->dx = rand() % (2 * raioVisao + 1) - raioVisao;
		this->dy = rand() % (2 * raioVisao + 1) - raioVisao;
		
		if (tentativas++ > 100) {
			cerr << "Não existem mais movimentos disponiveis.";
			break;
		}

	} while (!validaPos(this->posx, this->posy,this->dx, this->dy, limite));
	this->posx += this->dx;
	this->posy += this->dy;

	this->energia--;
	
	}

void Formiga::setPosx(int x)
{
	posx = x;
}

void Formiga::setPosy(int y)
{
	posy = y;
}

int Formiga::getId()
{
	return this->id;
}

int Formiga::getEnergia()
{
	return this->energia;
}

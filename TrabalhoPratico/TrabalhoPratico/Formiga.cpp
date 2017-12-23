#include "Formiga.h"
#include "Mundo.h"

int Formiga::i = 0;

Formiga::Formiga(char tipo, int posx, int posy)
{
	this->id = i++;
	this->tipo = tipo;
	if (tipo == 'E') {
		this->avatar = 'E';
		this->raioVisao = 10;
		this->raioMovimento = 8;
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

void Formiga::mover(int limite, Mundo & mundo)
{
	int tentativas = 0;
	do {
		this->dx = rand() % (2 * raioMovimento + 1) - raioMovimento;
		this->dy = rand() % (2 * raioMovimento + 1) - raioMovimento;
		
		if (tentativas++ > 100) {
			cerr << "N�o existem mais movimentos disponiveis.";
			break;
		}
		
	} while (!mundo.validaPos(this->posx, this->posy,this->dx, this->dy));
	int novaPosX = this->posx + this->dx;
	int novaPosY = this->posy + this->dy;
	this->energia -= (1 + (abs(novaPosX - posx) + abs(novaPosY - posy))); // energia = energia - (1 + MovimentoEfetivo) <- ver Enunciado
	this->posx = novaPosX;
	this->posy = novaPosY;
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

void Formiga::suicidio()
{
		delete this;
}

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
	if (tipo == 'A') {
		this->avatar = 'A';
		this->raioVisao = 8;
		this->raioMovimento = 4;
		this->energia = 80;
	}
	if (tipo == 'V') {
		this->avatar = 'V';
		this->raioVisao = 7;
		this->raioMovimento = 5;
		this->energia = 150;
	}
	if (tipo == 'C') {
		this->avatar = 'C';
		this->raioVisao = 5;
		this->raioMovimento = 3;
		this->energia = 100;
	}
	if (tipo == 'S') {
		this->avatar = 'S';
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
			cerr << "Não existem mais movimentos disponiveis.";
			return;
		}
		
	} while (!mundo.validaPos(this->posx, this->posy,this->dx, this->dy));
	int novaPosX = this->posx + this->dx;
	int novaPosY = this->posy + this->dy;
	atualizaEnergia(this->tipo, novaPosX, novaPosY);
	
	this->posx = novaPosX;
	this->posy = novaPosY;
	}

void Formiga::atualizaEnergia(char tipo, int novaPosX, int novaPosY)
{
	if (tipo == 'E')
		this->energia -= (1 + (abs(novaPosX - posx) + abs(novaPosY - posy))); // energia = energia - (1 + MovimentoEfetivo) <- ver Enunciado
	if (tipo == 'A')
		this->energia -= (1 + 2 * (abs(novaPosX - posx) + abs(novaPosY - posy))); // energia = energia - (1 + 2 * MovimentoEfetivo) <- ver Enunciado
	if (tipo == 'V')
		this->energia -= (1 + (abs(novaPosX - posx) + abs(novaPosY - posy))); // energia = energia - (1 + MovimentoEfetivo) <- ver Enunciado
	if (tipo == 'C')
		this->energia -= (1 + (abs(novaPosX - posx) + abs(novaPosY - posy))); // energia = energia - (1 + MovimentoEfetivo) <- ver Enunciado
	if (tipo == 'S')
		this->energia -= (1 + (abs(novaPosX - posx) + abs(novaPosY - posy))); // energia = energia - (1 + MovimentoEfetivo) <- ver Enunciado
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



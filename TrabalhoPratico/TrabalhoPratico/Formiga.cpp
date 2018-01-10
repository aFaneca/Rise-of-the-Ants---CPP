#include "Formiga.h"
#include "Mundo.h"

int Formiga::i = 0;

Formiga::Formiga(char tipo, int posx, int posy, Ninho &n)
{
	this->id = i++;
	this->tipo = tipo;
	this->n = &n;
	setPropriedades(tipo);
	this->posx = posx;
	this->posy = posy;
}

Formiga::~Formiga()
{
	//delete this;
}


void Formiga::setPropriedades(char tipo) {
	if (tipo == 'E') {
		this->avatar = 'E';
		this->raioVisao = 10;
		this->raioMovimento = 8;
		this->energia = 200;

		regras.reserve(regras.size() + 1);
		regras.push_back(new RegraFoge(tipo, *this, *n->getMundo()));
		
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
}
vector<Regra*> Formiga::getRegras()
{
	return this->regras;
}
int Formiga::calculaMovimento(int x1, int y1)
{
	int x = this->posx;
	int y = this->posy;

	int maximo = max(abs(x - x1), abs(y - y1));

	return maximo;
}
bool Formiga::podeMoverPara(int x1, int y1)
{
	if (calculaMovimento(x1, y1) <= this->raioMovimento)
		return true;
	return false;
}
char Formiga::getTipo()
{
	return this->tipo;
}

void Formiga::mover(int limite)
{
	Mundo *mundo = n->getMundo();
	int tentativas = 0;
	do {
		this->dx = rand() % (2 * raioMovimento + 1) - raioMovimento;
		this->dy = rand() % (2 * raioMovimento + 1) - raioMovimento;

		if (tentativas++ > 100) {
			cerr << "Não existem mais movimentos disponiveis.";
			return;
		}
		
	} while (!mundo->validaPos(this->posx, this->posy,this->dx, this->dy));
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

Ninho * Formiga::getNinho() {
	return this->n;
}

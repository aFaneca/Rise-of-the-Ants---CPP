#include "Mundo.h"
#include "Comunidade.h"
using namespace std;


Mundo::Mundo()
{
	iniciado = false;
}

void Mundo::Init(int limite, double energiaInicialNinhos, double valorEnergia, int posComMigalhas, double energiaInicialMigalhas, int maxMigalhas, double energiaTransferida)
{
	this->limite = limite;
	this->energiaInicialNinhos = energiaInicialNinhos;
	this->energiaTransferida = energiaTransferida;
	this->posComMigalhas = posComMigalhas;
	this->energiaInicialMigalhas = energiaInicialMigalhas;
	this->maxMigalhas = maxMigalhas;
	this->valorEnergia = valorEnergia;
	iniciado = true;
	grelha.resize(limite);
	for (int i = 0; i < limite; i++)
		grelha[i].resize(limite);
}

Mundo::~Mundo()
{
}

string Mundo::toString()
{
	ostringstream oss;
	oss << "INFO: Limite: " << limite << " | Energia Inicial Ninhos: " << energiaInicialNinhos << " | Valor Energia: " << valorEnergia << " | Posições com Migalhas: "
		<< posComMigalhas << " | Energia Inicial Migalhas: " << energiaInicialMigalhas << " | Máximo de Migalhas: "
		<< maxMigalhas << " | EnergiaTransferida: " << energiaTransferida << endl;
	return oss.str();
}

int Mundo::getLimite()
{
	return limite;
}

bool Mundo::getIniciado()
{
	return iniciado;
}

void Mundo::setEnergiaInicialNinhos(double v)
{
	energiaInicialNinhos = v;
}

void Mundo::setValorEnergia(double v)
{
	valorEnergia = v;
}

void Mundo::setPosComMigalhas(int v)
{
	posComMigalhas = v;
}

void Mundo::setEnergiaInicialMigalhas(double v)
{
	energiaInicialMigalhas = v;
}

void Mundo::setMaxMigalhas(int v)
{
	maxMigalhas = v;
}

void Mundo::setEnergiaTransferida(double v)
{
	energiaTransferida = v;
}

void Mundo::addComunidade(int posy, int posx)
{
	Comunidade c(posx, posy);
	comunidades.push_back(c);
}

vector<Comunidade> &Mundo::getComunidades()
{
	return this->comunidades;
}


#include "Mundo.h"
#include "Ninho.h"
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
	//grelha.resize(limite * limite);
	grelha.resize(limite);
	iniciado = true;
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

vector<vector<char>> Mundo::getMundo()
{
	for (int i = 0; i < limite; i++) {
		grelha[i].resize(limite);
		for (int j = 0; j < limite; j++) {
			grelha[i][j] = 'C';
		}
	}
	return grelha;
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


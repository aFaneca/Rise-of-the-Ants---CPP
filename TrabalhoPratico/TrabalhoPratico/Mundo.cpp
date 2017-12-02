#include "Mundo.h"





Mundo::Mundo(int limite, double energiaInicialNinhos, double valorEnergia, int posComMigalhas, int energiaInicialMigalhas, int maxMigalhas, double energiaTransferida = 1)
{
	this->limite = limite;
	this->energiaInicialNinhos = energiaInicialNinhos;
	this->energiaTransferida = energiaTransferida;
	this->posComMigalhas = posComMigalhas;
	this->energiaInicialMigalhas = energiaInicialMigalhas;
	this->maxMigalhas = maxMigalhas;
	this->valorEnergia = valorEnergia;
}

Mundo::~Mundo()
{
}

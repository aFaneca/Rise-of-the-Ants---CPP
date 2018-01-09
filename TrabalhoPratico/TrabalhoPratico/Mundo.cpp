#include "Mundo.h"
#include "Comunidade.h"
#include "Migalha.h"
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
	
	// POPULAR MUNDO
	for (int i = 0; i < getLimite(); i++) 
		for (int j = 0; j < getLimite(); j++) 
			grelha[i][j] = 'V';

	gerarMigalhas();
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
	//Comunidade c = new Comunidade(posx, posy);
	comunidades.push_back(new Comunidade(posx, posy));
}

vector<Comunidade*> Mundo::getComunidades()
{
	return this->comunidades;
}

vector<Migalha*> Mundo::getMigalhas()
{
	return this->migalhas;
}

void Mundo::addMigalha(int posx, int posy)
{
	Migalha *m = new Migalha(posx, posy, (int)this->energiaInicialMigalhas);
	migalhas.reserve(migalhas.size() + 1);
	migalhas.push_back(m);
	addGrelha(posx, posy, m->avatar);
}

void Mundo::gerarMigalhas()
{
	int px, py;
	int max = limite - 1;
	int min = 1;
	int nMigalhas = (limite * limite) * (posComMigalhas / 100.00);

	//ATRIBUIR POSICAO ALEATORIA E VERIFICAR SE ESTA OCUPADA - REPETIR ATE FALSE
	for (int i = 0; i < nMigalhas; i++) {
		do {
			px = rand() % (max - min + 1) + min;
			py = rand() % (max - min + 1) + min;
		} while (ocupada(px, py));

		addMigalha(px, py);
	}
	

}

void Mundo::addFormiga2Ninho(int idNinho, char tipoFormiga, int posx, int posy)
{
	// PROCURA PELO NINHO (ID)
	for (int i = 0; i < this->getComunidades().size(); i++) {
		if (comunidades[i]->getId() == idNinho) {
			comunidades[i]->getNinho()->addFormiga(tipoFormiga, *this, posx, posy);
		}
	}
}

void Mundo::addEnergia2Ninho(int idNinho, int energ)
{
	// PROCURA PELO NINHO (ID)
	for (int i = 0; i < this->getComunidades().size(); i++) {
		if (comunidades[i]->getId() == idNinho) {
			comunidades[i]->getNinho()->addEnergia(energ);
		}
	}

}

bool Mundo::temFormiga(int x, int y)
{
	if (this->grelha[x - 1][y - 1] == 'E' || this->grelha[x - 1][y - 1] == 'A' || this->grelha[x - 1][y - 1] == 'V' || 
		this->grelha[x - 1][y - 1] == 'C' || this->grelha[x - 1][y - 1] == 'S')
		return true;

	return false;
}

void Mundo::addEnergia2Formiga(int x, int y, int energia)
{
	int idFormiga;
	// PROCURA A FORMIGA QUE ESTÁ NESSA POSIÇÃO
	for (int i = 0; i < comunidades.size(); i++) {
		idFormiga = comunidades[i]->encontraFormiga(x, y);
		if (idFormiga != -1) { // SE UMA FORMIGA FOR ENCONTRADA NESSA POSIÇÃO
			comunidades[i]->addEnergia2Formiga(idFormiga, energia);

			return;
		}

	}
}

void Mundo::eliminaNinho(int idNinho)
{
	// PROCURA PELO NINHO (ID)
	for (int i = 0; i < this->getComunidades().size(); i++) {
		if (comunidades[i]->getId() == idNinho) {
			delete comunidades[i];
			if (!comunidades.empty())
				comunidades.erase(comunidades.begin() + i);
		}
	}
}

void Mundo::mataFormiga(int posx, int posy)
{
	int idFormiga;
	// PROCURA A FORMIGA QUE ESTÁ NESSA POSIÇÃO
	for (int i = 0; i < comunidades.size(); i++) {
		idFormiga = comunidades[i]->encontraFormiga(posx, posy);
		if (idFormiga != -1) { // SE UMA FORMIGA FOR ENCONTRADA NESSA POSIÇÃO
			comunidades[i]->getNinho()->mataFormiga(idFormiga);

			return;
		}
	}
}



bool Mundo::ocupada(int x, int y)
{
	if (this->grelha[x - 1][y - 1] == 'V')
		return false;

	return true;
}
bool Mundo::validaPos(int x, int y, int dx, int dy) {
	x += dx;
	y += dy;

	if (x < 1 || y < 1 || x > limite || y > limite) //SE NÃO ULTRAPASSAR OS LIMITES
		return false;
	else {
		if (!this->ocupada(x, y)) { // SE NÃO ESTIVER OCUPADA
			return true;
		}
	}
	return false;
}
void Mundo::addGrelha(int x, int y, char avatar) {
	this->grelha[x - 1][y - 1] = avatar;
}

vector<vector<char>> Mundo::getGrelha()
{
	return grelha;
}



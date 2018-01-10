#include "Mundo.h"
#include "Comunidade.h"
#include "Migalha.h"
#include "Ninho.h"
#include "Formiga.h"
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
	comunidades.push_back(new Comunidade(posx, posy, energiaInicialNinhos, *this));
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

void Mundo::gerarMigalhas(int quantidade)
{
	int px, py;
	int max = limite - 1;
	int min = 1;
	int nMigalhas;
	if (quantidade == -1)
		nMigalhas = (limite * limite) * (posComMigalhas / 100.00);
	else
		nMigalhas = quantidade;

	//ATRIBUIR POSICAO ALEATORIA E VERIFICAR SE ESTA OCUPADA - REPETIR ATE FALSE
	for (int i = 0; i < nMigalhas; i++) {
		do {
			px = rand() % (max - min + 1) + min;
			py = rand() % (max - min + 1) + min;
		} while (ocupada(px, py));

		addMigalha(px, py);
	}
}

void Mundo::geraMaisMigalhas()
{
	int min = 0;
	int max = this->maxMigalhas;

	int nMigalhas = rand() % (max - min + 1) + min;

	gerarMigalhas(nMigalhas);
}

void Mundo::iteracao()
{
	iteraFormigas();
	iteraNinhos();
	iteraMigalhas();
	
	
}

void Mundo::iteraFormigas() {
	for (int i = 0; i < comunidades.size(); i++) {
		// VERIFICA NINHOS
		for (int j = 0; j < comunidades[i]->getNinho()->getFormigas().size(); j++) {
			// VERIFICA AS FORMIGAS DE CADA NINHO
			comunidades[i]->getNinho()->getFormigas()[j]->mover(limite);
			if (comunidades[i]->getNinho()->getFormigas()[j]->getEnergia() < 1) {
				int posx = comunidades[i]->getNinho()->getFormigas()[j]->posx;
				int posy = comunidades[i]->getNinho()->getFormigas()[j]->posy;
				mataFormiga(posx, posy);
				j--;
			}
		}
	}
}

void Mundo::iteraNinhos() {
	
}

void Mundo::iteraMigalhas() {
	// ORDENA AÇÃO DAS MIGALHAS EM CADA ITERAÇÃO
	for (int i = 0; i < migalhas.size(); i++) {
		migalhas[i]->iteracao();
		if (migalhas[i]->energia < (migalhas[i]->getEnergiaInicial() * 0.1)) {
			delete migalhas[i];
			if (!migalhas.empty())
				migalhas.erase(migalhas.begin() + i);
		}
	}
}

void Mundo::addFormiga2Ninho(int idNinho, char tipoFormiga, int posx, int posy)
{
	// PROCURA PELO NINHO (ID)
	for (int i = 0; i < this->getComunidades().size(); i++) {
		if (comunidades[i]->getId() == idNinho) {
			comunidades[i]->getNinho()->addFormiga(tipoFormiga, posx, posy);
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
	/*if (this->grelha[x - 1][y - 1] == 'E' || this->grelha[x - 1][y - 1] == 'A' || this->grelha[x - 1][y - 1] == 'V' || 
		this->grelha[x - 1][y - 1] == 'C' || this->grelha[x - 1][y - 1] == 'S')
		return true;

	return false;*/

	for (int i = 0; i < this->getComunidades().size(); i++) {
		for (int j = 0; j < this->getComunidades()[i]->getNinho()->getFormigas().size(); j++) {
			Formiga *f1 = this->getComunidades()[i]->getNinho()->getFormigas()[j];
			if (f1->posx == x && f1->posy == y) {
				return true;
				break;
			}
		}
	}

	return false;
}

Formiga * Mundo::encontraFormiga(int x, int y)
{


	for (int i = 0; i < this->getComunidades().size(); i++) {
		for (int j = 0; j < this->getComunidades()[i]->getNinho()->getFormigas().size(); j++) {
			Formiga *f1 = this->getComunidades()[i]->getNinho()->getFormigas()[j];
			if (f1->posx == x && f1->posy == y) {
				return f1;
				break;
			}
		}
	}

	return NULL;
}

int Mundo::getQuadrante(int x, int y)
{
	if (x < 0 && y < 0)
		return 1;
	if (x > 0 && y < 0)
		return 2;
	if (x < 0 && y < 0)
		return 3;
	else
		return 4;
}

int Mundo::getAleatorio(int min, int max)
{
	return (rand() % (max - min + 1) + min);
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
	try {
		if (this->grelha[x - 1][y - 1] == 'V')
			return false;
	}
	catch (const std::out_of_range& e) {
		return false;
	}
	

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



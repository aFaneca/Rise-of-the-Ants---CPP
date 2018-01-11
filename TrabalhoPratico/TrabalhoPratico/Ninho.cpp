#include "Ninho.h"
#include "Mundo.h"
#include "Formiga.h"
int Ninho::i = 1;

Ninho::Ninho(int posx, int posy, int energiaInicial, Mundo &m)
{
	this->id = i++;
	this->avatar = 178;
	this->posx = posx;
	this->posy = posy;
	this->m = &m;
	energia = energiaInicial;
}

Ninho::~Ninho()
{
	formigas.clear();
	delete this;
}

int Ninho::getId()
{
	return this->id;
}

vector<Formiga *> Ninho::getFormigas()
{
	return this->formigas;
}

void Ninho::addFormiga(char tipo, int posx, int posy)
{
	int px, py;
	int max = m->getLimite() - 1;
	int min = 1;

	if (posx == -1) {
		//ATRIBUIR POSICAO ALEATORIA E VERIFICAR SE ESTA OCUPADA - REPETIR ATE FALSE
		do {
			px = rand() % (max - min + 1) + min;
			py = rand() % (max - min + 1) + min;
		} while (m->ocupada(px, py));
	}
	else {
		px = posx;
		py = posy;
	}
	Formiga *f = new Formiga(tipo, px, py, *this);
	formigas.reserve(formigas.size() + 1);
	formigas.push_back(f);
	m->addGrelha(px, py, f->avatar);
}

void Ninho::addEnergia(int valor)
{
	this->energia += valor;
}

void Ninho::mataFormiga(int idFormiga)
{
	// PROCURA PELA FORMIGA (ID)
	for (int i = 0; i < getFormigas().size(); i++) {
		if (formigas[i]->getId() == idFormiga) {
			delete formigas[i];
			if (!formigas.empty())
				formigas.erase(formigas.begin() + i);
		}
	}
}

Mundo * Ninho::getMundo()
{
		return m;
}

void Ninho::correRegras()
{
	// ITERA POR TODAS AS FORMIGAS DO NINHO
	for (int i = 0; i < formigas.size(); i++) {
		formigas[i]->correRegras();
	}
}

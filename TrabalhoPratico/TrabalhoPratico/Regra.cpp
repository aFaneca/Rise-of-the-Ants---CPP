#include "Regra.h"
#include "Migalha.h"


Regra::~Regra()
{
}

Regra::Regra()
{
}

bool Regra::validaPos(int x, int y) {
	// VERIFICA SE A POSI��O EST� DENTRO DOS LIMITES
	if (x > 1 && y > 1 && x < m->getLimite() && y < m->getLimite()) { //SE N�O ULTRAPASSAR OS LIMITES
																	  // VERIFICA SE A POSICAO EST� VAZIA
		if (!m->ocupada(x, y))
			return true; // POSI��O V�LIDA
	}
	return false;
}

RegraAssalta::RegraAssalta(char tipo, Formiga &f, Mundo &m) :Regra()
{
	this->tipo = tipo;
	this->f = &f;
	this->m = &m;
}


RegraAssalta::~RegraAssalta()
{
}


// Est� uma formiga de outra comunidade no seu raio de vis�o?
bool RegraAssalta::condicao() {
	for (int x = -(f->raioVisao); x < +(f->raioVisao + 1); x++) {
		for (int y = -(f->raioVisao); y < +(f->raioVisao + 1); y++) { // PROCURA TODOS OS CAMPOS NO SEU RAIO DE VIS�O
			if (m->temFormiga(x, y)) { // SE HOUVER ALGUMA FORMIGA NESTA POSI��O
				formigaInimiga = m->encontraFormiga(x, y); //	RECEBE ESSA FORMIGA
				if (formigaInimiga->getNinho()->getId() != f->getNinho()->getId()) { // SE O ID FOR DIFERENTE => S�O DE COMUNIDADES DIFERENTES
					this->setAssaltada(*formigaInimiga);
					return true;
				}
			}
		}
	}
	return false;
}

// ASSALTA-A E ROUBA-LHE 50% DE ENERGIA
void RegraAssalta::acao() {
	f->energia += 0.5 * (assaltada->energia);
	assaltada->energia -= 0.5 * (assaltada->energia);
}


RegraComeMigalha::RegraComeMigalha(char tipo, Formiga &f, Mundo &m) :Regra()
{
	this->tipo = tipo;
	this->f = &f;
	this->m = &m;
}


RegraComeMigalha::~RegraComeMigalha()
{
}
//
// Est� uma migalha na mesma posi��o ou adjacente?
bool RegraComeMigalha::condicao() {
	int x = f->posx;
	int y = f->posy;

	for (int i = 0; i < m->getMigalhas().size(); i++) {
		int mX = m->getMigalhas().at(i)->posx;
		int mY = m->getMigalhas().at(i)->posy;
		if ( (mX == x && mY == y) || (mX == x && mY == (y+1) ) || (mX == (x + 1) && mY == y) || 
			(mX == x && mY == (y - 1)) || (mX == (x - 1) && mY == y)) {
			this->setMigalha(*m->getMigalhas().at(i));
			return true;
		}
	}
	return false;
}

//COMER COM DENTADA DE x%
void RegraComeMigalha::acao() {
	if (f->getTipo() == 'C') {
		f->energia += 0.5 * (migalha->energia);
		migalha->energia -= 0.5 * (migalha->energia);
	}
	if (f->getTipo() == 'E') {
		f->energia += 1 * (migalha->energia);
		migalha->energia -= 1 * (migalha->energia);
	}
	if (f->getTipo() == 'V') {
		f->energia += 0.75 * (migalha->energia);
		migalha->energia -= 0.75 * (migalha->energia);
	}
	if (f->getTipo() == 'S') {

	}
	if (f->getTipo() == 'A') {
		f->energia += 0.25 * (migalha->energia);
		migalha->energia -= 0.25 * (migalha->energia);
	}
}


RegraFoge::RegraFoge(char tipo, Formiga &f, Mundo &m) :Regra()
{
	this->tipo = tipo;
	this->f = &f;
	this->m = &m;
}


RegraFoge::~RegraFoge()
{
}


// Est� uma formiga de outra comunidade no seu raio de vis�o?
bool RegraFoge::condicao() {
	for (int x = -(f->raioVisao); x < +(f->raioVisao + 1); x++) {
		for (int y = -(f->raioVisao); y < +(f->raioVisao + 1); y++) { // PROCURA TODOS OS CAMPOS NO SEU RAIO DE VIS�O
			if (m->temFormiga(x, y)) { // SE HOUVER ALGUMA FORMIGA NESTA POSI��O
				formigaInimiga = m->encontraFormiga(x, y); //	RECEBE ESSA FORMIGA
				if (formigaInimiga->getNinho()->getId() != f->getNinho()->getId()) // SE O ID FOR DIFERENTE => S�O DE COMUNIDADES DIFERENTES
					return true;
			}
		}
	}

	return false;
}


// FUGIR PARA QUADRANTE OPOSTO
void RegraFoge::acao() {
	int x = f->posx;
	int y = f->posy;
	int xInimigo = formigaInimiga->posx;
	int yInimigo = formigaInimiga->posx;
	int novaPosX, novaPosY;
	int quadrante;
	int min, max;

	//TENTA IR PARA A POSI��O EXATAMENTE OPOSTA � DO INIMIGO
	novaPosX = x - (xInimigo - x);
	novaPosY = y - (yInimigo - y);
	while (!validaPos(novaPosX, novaPosY)) {
		quadrante = m->getQuadrante(novaPosX, novaPosY);

		if (quadrante == 1) {
			// IR PARA POSI��O ALEAT�RIA NO TERCEIRO QUADRANTE
			min = x - f->raioMovimento;
			max = x;
			novaPosX = m->getAleatorio(min, max);
			min = y - f->raioMovimento;
			max = y;
			novaPosY = m->getAleatorio(min, max);
		}
		else if (quadrante == 2) {
			// IR PARA POSI��O ALEAT�RIA NO QUARTO QUADRANTE
			min = x;
			max = x - f->raioMovimento;
			novaPosX = m->getAleatorio(min, max);
			min = y - f->raioMovimento;
			max = y;
			novaPosY = m->getAleatorio(min, max);
		}
		else if (quadrante == 3) {
			// IR PARA POSI��O ALEAT�RIA NO PRIMEIRO QUADRANTE
			min = x;
			max = x + f->raioMovimento;
			novaPosX = m->getAleatorio(min, max);
			min = y;
			max = y + f->raioMovimento;
			novaPosY = m->getAleatorio(min, max);
		}
		else if (quadrante == 4) {
			// IR PARA POSI��O ALEAT�RIA NO SEGUNDO QUADRANTE
			min = x - f->raioMovimento;
			max = x;
			novaPosX = m->getAleatorio(min, max);
			min = y;
			max = y + f->raioMovimento;
			novaPosY = m->getAleatorio(min, max);
		}
	}
	f->posx = novaPosX;
	f->posy = novaPosY;
}


RegraPasseia::RegraPasseia(char tipo, Formiga &f, Mundo &m) :Regra()
{
	this->tipo = tipo;
	this->f = &f;
	this->m = &m;
}


RegraPasseia::~RegraPasseia()
{
}


// Esta condi��o � sempre verdadeira
bool RegraPasseia::condicao() {
	return true;
}

// Passeia de forma aleat�ria dentro do raio de movimento
void RegraPasseia::acao() {
	f->mover();
}

RegraPersegue::RegraPersegue(char tipo, Formiga &f, Mundo &m) :Regra()
{
	this->tipo = tipo;
	this->f = &f;
	this->m = &m;
}


RegraPersegue::~RegraPersegue()
{
}


// Est� uma formiga de outra comunidade e uma aliada no seu raio de vis�o?
bool RegraPersegue::condicao() {
	return false;
}

// METER-SE NO MEIO DAS DUAS
void RegraPersegue::acao() {
	
}

RegraProcuraMigalha::RegraProcuraMigalha(char tipo, Formiga &f, Mundo &m) :Regra()
{
	this->tipo = tipo;
	this->f = &f;
	this->m = &m;
}


RegraProcuraMigalha::~RegraProcuraMigalha()
{
}

// Est� uma formiga de outra comunidade no seu raio de vis�o?
bool RegraProcuraMigalha::condicao() {
	return false;
}

// FUGIR PARA QUADRANTE OPOSTO
void RegraProcuraMigalha::acao() {
}

RegraProtege::RegraProtege(char tipo, Formiga &f, Mundo &m) :Regra()
{
	this->tipo = tipo;
	this->f = &f;
	this->m = &m;
}


RegraProtege::~RegraProtege()
{
}

// Est� uma formiga de outra comunidade e uma aliada no seu raio de vis�o?
bool RegraProtege::condicao() {
	bool temAliado = false;
	bool temInimigo = false;

	for (int x = -(f->raioVisao); x < +(f->raioVisao + 1); x++) {
		for (int y = -(f->raioVisao); y < +(f->raioVisao + 1); y++) { // PROCURA TODOS OS CAMPOS NO SEU RAIO DE VIS�O
			if (m->temFormiga(x, y)) { // SE HOUVER ALGUMA FORMIGA NESTA POSI��O
				formigaInimiga = m->encontraFormiga(x, y); //	RECEBE ESSA FORMIGA
				if (formigaInimiga->getNinho()->getId() != f->getNinho()->getId()) { // SE O ID FOR DIFERENTE => S�O DE COMUNIDADES DIFERENTES
					temInimigo = true;
					inimiga = formigaInimiga;

				}
				else {
					temAliado = true;
					aliada = formigaInimiga;
				}
				
			}
		}
	}

	if (temAliado && temInimigo)
		return true;

	return false;
}

// FUGIR PARA QUADRANTE OPOSTO
void RegraProtege::acao() {
	int novaPosX = (int) (aliada->posx + inimiga->posx) / 2;
	int novaPosY = (int)(aliada->posy + inimiga->posy) / 2;
	while (!validaPos(novaPosX, novaPosY)) {
		int novaPosX = (int)(aliada->posx + inimiga->posx++) / 2;
		int novaPosY = (int)(aliada->posy + inimiga->posy++) / 2;
	}
	f->posx = novaPosX;
	f->posy = novaPosY;
}

RegraVaiParaNinho::RegraVaiParaNinho(char tipo, Formiga &f, Mundo &m) :Regra()
{
	this->tipo = tipo;
	this->f = &f;
	this->m = &m;
}


RegraVaiParaNinho::~RegraVaiParaNinho()
{
}

// Quando  a  formiga  cuidadora  tiver um  valor  de  energia maior  do  que  a  energia inicial
//ou menor do que metade da energia inicial, tiver o ninho no seu raio de vis�o e estiver
//fora do ninho h� mais de 10 itera��es, dirige-se para o ninho.

bool RegraVaiParaNinho::condicao() {
	if (f->energia > f->energiaInicial || f->energia < 0.5 * f->energiaInicial) {
		//SE TIVER NINHO NO RAIO DE VIS�O
		for (int x = -(f->raioVisao); x < +(f->raioVisao + 1); x++) {
			for (int y = -(f->raioVisao); y < +(f->raioVisao + 1); y++) { // PROCURA TODOS OS CAMPOS NO SEU RAIO DE VIS�O
				if (m->temNinho(x, y)) { // SE HOUVER ALGUM NINHO NESTA POSI��O
					n = m->encontraNinho(x, y); //	RECEBE ESSE NINHO
					if (n->getId() == f->getNinho()->getId()) { // SE O ID FOR IGUAL => � O NINHO DA FORMIGA
						if (f->foraDoNinho > 10 ) // SE ESTIVER FORA DO NINHO H� MAIS DE 10 ITERA��ES
						return true;
					}
				}
			}
		}
	}

	return false;
}

// DIRIGE-SE PARA O NINHO
void RegraVaiParaNinho::acao() {
	int novaPosX, novaPosY;
	int quadrante;
	int min, max, x = 0, y = 0;

	// VERIFICA SE O NINHO EST� NO RAIO DE MOVIMENTO
	if (f->podeMoverPara(n->posx, n->posy)) {
		f->posx = n->posx;
		f->posy = n->posy;
	}
	else {
		do {
			quadrante = m->getQuadrante(n->posx, n->posy);
			if (quadrante == 1) {
				// IR PARA POSI��O ALEAT�RIA NO PRIMEIRO QUADRANTE
				min = x;
				max = x + f->raioMovimento;
				novaPosX = m->getAleatorio(min, max);
				min = y;
				max = y + f->raioMovimento;
				novaPosY = m->getAleatorio(min, max);
			}
			else if (quadrante == 2) {
				// IR PARA POSI��O ALEAT�RIA NO SEGUNDO QUADRANTE
				min = x - f->raioMovimento;
				max = x;
				novaPosX = m->getAleatorio(min, max);
				min = y;
				max = y + f->raioMovimento;
				novaPosY = m->getAleatorio(min, max);
			}
			else if (quadrante == 3) {
				// IR PARA POSI��O ALEAT�RIA NO TERCEIRO QUADRANTE
				min = x - f->raioMovimento;
				max = x;
				novaPosX = m->getAleatorio(min, max);
				min = y - f->raioMovimento;
				max = y;
				novaPosY = m->getAleatorio(min, max);
			}
			else if (quadrante == 4) {
				// IR PARA POSI��O ALEAT�RIA NO QUARTO QUADRANTE
				min = x;
				max = x - f->raioMovimento;
				novaPosX = m->getAleatorio(min, max);
				min = y - f->raioMovimento;
				max = y;
				novaPosY = m->getAleatorio(min, max);
			}

		} while (!validaPos(novaPosX, novaPosY));

		f->posx = novaPosX;
		f->posy = novaPosY;
	}
		


	
}

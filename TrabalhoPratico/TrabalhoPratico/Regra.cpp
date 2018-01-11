#include "Regra.h"
#include "Formiga.h"


Regra::~Regra()
{
}

Regra::Regra()
{
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
	return false;
}

// FUGIR PARA QUADRANTE OPOSTO
void RegraAssalta::acao() {
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
// Est� uma formiga de outra comunidade no seu raio de vis�o?
bool RegraComeMigalha::condicao() {
	return false;
}

// FUGIR PARA QUADRANTE OPOSTO
void RegraComeMigalha::acao() {
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
}

bool RegraFoge::validaPos(int x, int y) {
	// VERIFICA SE A POSI��O EST� DENTRO DOS LIMITES
	if (x > 1 && y > 1 && x < m->getLimite() && y < m->getLimite()) { //SE N�O ULTRAPASSAR OS LIMITES
																	  // VERIFICA SE A POSICAO EST� VAZIA
		if (!m->ocupada(x, y))
			return true; // POSI��O V�LIDA
	}
	return false;
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


// Est� uma formiga de outra comunidade no seu raio de vis�o?
bool RegraPersegue::condicao() {
	return false;
}

// FUGIR PARA QUADRANTE OPOSTO
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

// Est� uma formiga de outra comunidade no seu raio de vis�o?
bool RegraProtege::condicao() {
	return false;
}

// FUGIR PARA QUADRANTE OPOSTO
void RegraProtege::acao() {
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

// Est� uma formiga de outra comunidade no seu raio de vis�o?
bool RegraVaiParaNinho::condicao() {
	return false;
}

// FUGIR PARA QUADRANTE OPOSTO
void RegraVaiParaNinho::acao() {
}

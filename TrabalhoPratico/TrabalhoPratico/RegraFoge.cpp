#include "RegraFoge.h"


RegraFoge::RegraFoge(char tipo, Formiga &f, Mundo &m)
{
	this->tipo = tipo;
	this->f = &f;
	this->m = &m;
	
}


RegraFoge::~RegraFoge()
{
}


// Est� uma formiga de outra comunidade no seu raio de vis�o?
bool Regra::condicao() { 
	

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
void Regra::acao() {
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

bool Regra::validaPos(int x, int y) {
	// VERIFICA SE A POSI��O EST� DENTRO DOS LIMITES
	if (x > 1 && y > 1 && x < m->getLimite() && y < m->getLimite()){ //SE N�O ULTRAPASSAR OS LIMITES
		// VERIFICA SE A POSICAO EST� VAZIA
		if (!m->ocupada(x, y))
			return true; // POSI��O V�LIDA
	}
	return false;
}

#ifndef INTERFACE_H
#define INTERFACE_H
#pragma once
//#include "Processador.h"


class Mundo;
class Processador;

class Interface {
private:
	const int LIMIAR = 2; // POSIÇÃO NO EIXO DOS YY A PARTIR DA QUAL O MUNDO PODE SER MOSTRADO NA CONSOLA
	Processador *p1;
public:
	void run();
	void mostraMenu();
	void novoJogo();
	void continuarJogo();
	void sair();
	void mostraMundo(Mundo &mundo);
	void info(Mundo &mundo);
	void listaMundo(Mundo & mundo);
	void listaNinho(int id, Mundo & mundo);
	void listaPosicao(int x, int y, Mundo & mundo);
	void movimentos(Mundo & mundo);
	Interface();
	~Interface();
};


#endif 
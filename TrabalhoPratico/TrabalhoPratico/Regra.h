#pragma once
#include "Mundo.h"
class Regra
{
protected:
	char tipo;
	Formiga *f;
	Mundo *m;
	Formiga * formigaInimiga;
public:
	Regra();
	~Regra();


	virtual bool condicao();
	virtual void acao();
	virtual bool validaPos(int x, int y);
};


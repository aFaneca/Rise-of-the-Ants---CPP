#pragma once
#include "Elementos.h"
class Migalha : public Elementos
{
private:
	static int i;
	int id;
	int energiaInicial;

public:
	Migalha(int posx, int posy, int energiaInicial);
	~Migalha();
	int getId();
	void iteracao();
	int getEnergiaInicial();
};


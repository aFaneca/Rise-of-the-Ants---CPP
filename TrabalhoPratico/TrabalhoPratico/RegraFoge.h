#pragma once
#include "Regra.h"
#include "Formiga.h"


class RegraFoge : public Regra
{

public:
	RegraFoge(char tipo, Formiga &f, Mundo &m);
	~RegraFoge();
};


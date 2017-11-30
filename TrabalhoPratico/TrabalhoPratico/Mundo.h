#pragma once
#include "header.h"
class Ninho;
class Mundo
{

private:
	int dim;
	vector<Ninho> ninhos;
public:
	Mundo(int dim);
	~Mundo();
};


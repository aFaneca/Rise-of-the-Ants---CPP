#include "Elementos.h"
#include "header.h"


Elementos::Elementos()
{
}


Elementos::~Elementos()
{
}

bool Elementos::ocupada(int x, int y)
{
	if (grelha[x][y] == 'V')
		return false;

	return true;
}

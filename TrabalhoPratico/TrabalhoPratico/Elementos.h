#ifndef ELEMENTOS_H
#define ELEMENTOS_H
#pragma once
class Elementos
{
public:
	Elementos();
	~Elementos();

	int posx, posy;
	char avatar;
	bool ocupada(int x, int y);
};

#endif
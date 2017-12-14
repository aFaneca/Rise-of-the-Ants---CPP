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
	int raioVisao, dx = 0, dy = 0;
	int energia;
};

#endif
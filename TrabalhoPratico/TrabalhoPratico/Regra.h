#ifndef REGRA_H
#define REGRA_H
#pragma once
#include "Mundo.h"
#include "Formiga.h"

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


	virtual bool condicao() = 0;
	virtual void acao() = 0;
	virtual bool validaPos(int x, int y) = 0;
};

class RegraVaiParaNinho : public Regra
{
public:
	RegraVaiParaNinho(char tipo, Formiga &f, Mundo &m);
	~RegraVaiParaNinho();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y);
};

class RegraProtege : public Regra
{
public:
	RegraProtege(char tipo, Formiga &f, Mundo &m);
	~RegraProtege();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y);
};


class RegraProcuraMigalha : public Regra
{
public:
	RegraProcuraMigalha(char tipo, Formiga &f, Mundo &m);
	~RegraProcuraMigalha();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y);
};

class RegraPersegue : public Regra
{
public:
	RegraPersegue(char tipo, Formiga &f, Mundo &m);
	~RegraPersegue();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y);
};

class RegraPasseia : public Regra
{
public:
	RegraPasseia(char tipo, Formiga &f, Mundo &m);
	~RegraPasseia();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y);
};

class RegraFoge : public Regra
{

public:
	RegraFoge(char tipo, Formiga &f, Mundo &m);
	~RegraFoge();
	bool condicao();
	void acao();
	bool validaPos(int x, int y);
};

class RegraComeMigalha : public Regra
{
public:
	RegraComeMigalha(char tipo, Formiga &f, Mundo &m);
	~RegraComeMigalha();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y);
};

class RegraAssalta : public Regra
{
public:
	RegraAssalta(char tipo, Formiga &f, Mundo &m);
	~RegraAssalta();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y);
};

#endif
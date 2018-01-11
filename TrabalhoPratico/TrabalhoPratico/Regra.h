#pragma once
#include "Mundo.h"


class Formiga;

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

class RegraVaiParaNinho : public Regra
{
public:
	RegraVaiParaNinho(char tipo, Formiga &f, Mundo &m);
	~RegraVaiParaNinho();
	bool condicao();
	void acao();
	bool validaPos(int x, int y);
};

class RegraProtege : public Regra
{
public:
	RegraProtege(char tipo, Formiga &f, Mundo &m);
	~RegraProtege();
	bool condicao();
	void acao();
	bool validaPos(int x, int y);
};


class RegraProcuraMigalha : public Regra
{
public:
	RegraProcuraMigalha(char tipo, Formiga &f, Mundo &m);
	~RegraProcuraMigalha();
	bool condicao();
	void acao();
	bool validaPos(int x, int y);
};

class RegraPersegue : public Regra
{
public:
	RegraPersegue(char tipo, Formiga &f, Mundo &m);
	~RegraPersegue();
	bool condicao();
	void acao();
	bool validaPos(int x, int y);
};

class RegraPasseia : public Regra
{
public:
	RegraPasseia(char tipo, Formiga &f, Mundo &m);
	~RegraPasseia();
	bool condicao();
	void acao();
	bool validaPos(int x, int y);
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
	bool validaPos(int x, int y);
};

class RegraAssalta : public Regra
{
public:
	RegraAssalta(char tipo, Formiga &f, Mundo &m);
	~RegraAssalta();
	bool condicao();
	void acao();
	bool validaPos(int x, int y);
};


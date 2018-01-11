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
	bool validaPos(int x, int y);
};

class RegraVaiParaNinho : public Regra
{
protected:
	Ninho * n;

public:
	RegraVaiParaNinho(char tipo, Formiga &f, Mundo &m);
	~RegraVaiParaNinho();
	bool condicao();
	void acao();
	bool validaPos(int x, int y) { return true; };
};

class RegraProtege : public Regra
{
protected:
	Formiga * aliada;
	Formiga * inimiga;
public:
	RegraProtege(char tipo, Formiga &f, Mundo &m);
	~RegraProtege();
	bool condicao();
	void acao();
	bool validaPos(int x, int y) { return true; };
	void setAliada(Formiga &formiga) {
		this->aliada = &formiga;
	}
	void setInimiga(Formiga &formiga) {
		this->inimiga = &formiga;
	}
};


class RegraProcuraMigalha : public Regra
{
protected:
	Formiga * f;
	vector<Migalha *> migalhas;
public:
	RegraProcuraMigalha(char tipo, Formiga &f, Mundo &m);
	~RegraProcuraMigalha();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y) { return true; };
};

class RegraPersegue : public Regra
{
protected:
	vector<Formiga *> formigas;
public:
	RegraPersegue(char tipo, Formiga &f, Mundo &m);
	~RegraPersegue();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y) { return true; };
};

class RegraPasseia : public Regra
{
public:
	RegraPasseia(char tipo, Formiga &f, Mundo &m);
	~RegraPasseia();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y) { return true; };
};

class RegraFoge : public Regra
{

public:
	RegraFoge(char tipo, Formiga &f, Mundo &m);
	~RegraFoge();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y);
};

class RegraComeMigalha : public Regra
{
protected:
	Migalha * migalha;
public:
	RegraComeMigalha(char tipo, Formiga &f, Mundo &m);
	~RegraComeMigalha();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y) { return true; };
	Migalha * getMigalha() {
		return this->migalha;
	}
	void setMigalha(Migalha &migalha) {
		this->migalha = &migalha;
	}
};

class RegraAssalta : public Regra
{
protected:
	Formiga * assaltada;
	vector<Formiga *> formigas;
public:
	RegraAssalta(char tipo, Formiga &f, Mundo &m);
	~RegraAssalta();
	bool condicao();
	void acao();
	//bool validaPos(int x, int y) { return true; };
	Formiga * getAssaltada() {
		return this->assaltada;
	}
	void setAssaltada(Formiga & formiga) {
		this->assaltada = &formiga;
	}
};

#endif
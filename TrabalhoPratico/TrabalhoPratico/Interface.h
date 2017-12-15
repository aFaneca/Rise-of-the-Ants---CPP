#ifndef INTERFACE_H
#define INTERFACE_H
#pragma once
#include "header.h"


class Mundo;

const int LIMIAR = 2; // POSIÇÃO NO EIXO DOS YY A PARTIR DA QUAL O MUNDO PODE SER MOSTRADO NA CONSOLA
int main();
void mostraMenu();
void novoJogo();
void continuarJogo();
void sair();
void mostraMundo(Mundo &mundo);
void info(Mundo &mundo);


#endif 
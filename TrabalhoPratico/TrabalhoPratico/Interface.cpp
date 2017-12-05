#include "header.h"
#include "Mundo.h"
#include "Ninho.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	int opt;

	Consola::setScreenSize(800, 600);  // linhas colunas. valores grandes pode nao dar
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);  // favor consultar o .h para ver as constantes
	Consola::clrscr();
	Consola::setTextColor(Consola::PRETO);

	Consola::setTextSize(20, 20);
	Consola::gotoxy(10, 10);
	cout << "SUCK MY SNAKE, BIATCH!";

	Consola::getch();


	do {
		mostraMenu();
		cin >> opt;
		if (opt == 3)
			sair();
		else if (opt == 2)
			continuarJogo();
		else if (opt == 1)
			novoJogo();

	} while (opt < 1 || opt > 3);

	Consola::getch();

}

void mostraMenu() {
	Consola::clrscr();
	cout << "## Menu ##" << endl;
	cout << "[1] NOVO JOGO\n[2] CONTINUAR JOGO\n[3] SAIR" << endl;
	cout << "> ";
}

void novoJogo() {
	bool defmundo = false, defen = false, defpc = false, defvt = true, defmi = false, defme = false, defnm = false, executa = false, inicio = false;
	Consola::setScreenSize(50, 80);
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::setTextColor(Consola::VERDE);
	Consola::clrscr();
	cout << "Novo Jogo...";
	processaComandos(&defmundo, &defen, &defpc, &defvt, &defmi, &defme, &defnm, &executa, &inicio);
}

void sair() {
	exit(0);
}




void mostraMundo(Mundo & mundo)
{
	//Consola::clrscr();
	vector<vector<char>> grelha = mundo.getMundo();
	//cout << grelha.size();
	Consola::setTextColor(Consola::CYAN);
	
	cout << endl;
	info(mundo);
	for (int i = 0; i < mundo.getLimite(); i++) {
		for (int j = 0; j < mundo.getLimite(); j++) {
			cout << " " << grelha[i][j];
		}
		cout << endl;
	}
	cout << endl;
	Consola::setTextColor(Consola::VERDE);
}

void info(Mundo & mundo)
{
	cout << mundo.toString();
}


void continuarJogo() {
	Consola::clrscr();
	cout << "Continua jogo...";
}


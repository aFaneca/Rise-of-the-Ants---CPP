#include "header.h"


void sair() {
	exit(0);
}
void continuarJogo() {
	Consola::clrscr();
	cout << "Continua jogo...";
}

void novoJogo() {
	string comando;

	Consola::clrscr();
	cout << "Novo Jogo...";

	cout << "> ";

	while (1) {
		cin >> comando;
		if (!comando.compare("AA"))
			cout << "AA o caralho!";

		break;
	}
}

void mostraMenu() {
	Consola::clrscr();
	cout << "## Menu ##" << endl;
	cout << "[1] NOVO JOGO\n[2] CONTINUAR JOGO\n[3] SAIR" << endl;
	cout << "> ";
}


int main() {
	int opt;
	//Consola::setBackgroundColor(Consola::AZUL);
	

	//Consola::getch();
	Consola::setScreenSize(20, 50);  // linhas colunas. valores grandes pode nao dar
	Consola::setBackgroundColor(Consola::BRANCO_CLARO);  // favor consultar o .h para ver as constantes
	Consola::setTextColor(Consola::AMARELO_CLARO);
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
		else
			novoJogo();
	}while (opt < 1 || opt > 3);
	

	

	











	Consola::getch();

}



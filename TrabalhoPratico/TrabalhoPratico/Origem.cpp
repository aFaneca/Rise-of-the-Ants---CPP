#include "header.h"

void valida(string comando) {
	cout << "A validar " << comando << "...";
	if (!comando.compare(0, 9, "defmundo ")) {
		if (comando.length() > 9) {
				cout << "Tudo ok...";
		}else {
			cout << "Erro de Sintaxe";
		}
	}
	
}
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
		cin.ignore();
		getline(cin, comando);
		cout << comando;
		if (!comando.compare(0, 9, "defmundo ")) {
			valida(comando);
		}
		else if (!comando.compare(0,5,"defen")) {
			valida(comando);
		}
		else if (!comando.compare(0,5,"defpc")) {
			valida(comando);
		}
		else if (!comando.compare(0,5,"defvt")) {
			valida(comando);
		}
		else if (!comando.compare(0,5,"defmi")) {
			valida(comando);
		}
		else if (!comando.compare(0,5,"defme")) {
			valida("defme");
		}
		else if (!comando.compare(0,5,"defnm")) {
			valida("defnm");
		}
		else if (!comando.compare(0,7,"executa")) {
			valida("executa");
		}
		else if (!comando.compare(0,6,"inicia")) {
			valida("inicia");
		}
		else {
			cout << "oh tone... 'ta fodereee!";
		}
			

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
	bool defmundo = false, defen = false, defpc = false, defvt = false, defmi = false, defme = false, defnm = false;

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



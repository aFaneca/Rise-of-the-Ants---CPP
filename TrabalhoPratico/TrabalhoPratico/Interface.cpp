#include "header.h"
#include "Comunidade.h"
#include "Mundo.h"
#include "Ninho.h"
#include "Formiga.h"

struct desenhos {
	char cantoSuperiorEsquerdo = 201;
	char cantoInferiorEsquerdo = 200;
	char cantoSuperiorDireito = 187;
	char cantoInferiorDireito = 188;
	char linhaHorizontal = 205;
	char linhaVertical = 186;
} desenho;


int main() {
	
	//setlocale(LC_ALL, "Portuguese"); <- causa bug com os caractéres ascii
	int opt;
	//Ninho n;

	Consola::setScreenSize(1000, 1000);  // linhas colunas. valores grandes pode nao dar
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


bool ocupada(int x, int y)
{
	if (grelha[x][y] == 'V')
		return false;

	return true;
}

void mostraMundo(Mundo & mundo)
{	
	int posx, posy;
	char avatar;
	//Consola::clrscr();
//	vector<vector<char>> grelha = mundo.getMundo();
	//cout << grelha.size();
	Consola::setTextColor(Consola::CYAN);
	
	cout << endl;
	info(mundo);
	
	
	grelha.clear();
	grelha.resize(mundo.getLimite());
	for (int i = 0; i < mundo.getLimite(); i++)
		grelha[i].resize(mundo.getLimite());

	for (int i = 0; i < mundo.getLimite(); i++) {
		for (int j = 0; j < mundo.getLimite(); j++) {
			grelha[i][j] = 'V';
		}
	}
	
	// CRIA O MUNDO E OS SEUS LIMITES
	Consola::gotoxy(0, LIMIAR);
	cout << desenho.cantoSuperiorEsquerdo;
	for (int i = 0; i < mundo.getLimite(); i++)
		cout << desenho.linhaHorizontal;
	cout << desenho.cantoSuperiorDireito;
	for (int i = 0; i < mundo.getLimite(); i++) {
		cout << endl;
		cout << desenho.linhaVertical;
		Consola::gotoxy(mundo.getLimite() + 1, i + LIMIAR + 1);
		cout << desenho.linhaVertical;
	}
	cout << endl;
	cout << desenho.cantoInferiorEsquerdo;
	for (int i = 0; i < mundo.getLimite(); i++)
		cout << desenho.linhaHorizontal;
	cout << desenho.cantoInferiorDireito;
	cout << endl;
	
	vector<Comunidade> comunidades;
	// ADICIONA OS ELEMENTOS NO MUNDO
	for (int i = 0; i < mundo.getComunidades().size(); i++) {
		// VERIFICA NINHOS
		Comunidade comunidade = mundo.getComunidades()[i];
		posx = comunidade.getNinho()->posx;
		posy = comunidade.getNinho()->posy;
		avatar = comunidade.getNinho()->avatar;
		grelha[posx][posy] = 'N';
		Consola::gotoxy(posx, posy + LIMIAR);
		cout << avatar;

		for (int j = 0; j < mundo.getComunidades()[i].getNinho()->getFormigas().size(); j++) {
			// VERIFICA AS FORMIGAS DE CADA NINHO
			posx = mundo.getComunidades()[i].getNinho()->getFormigas()[i].posx;
			posy = mundo.getComunidades()[i].getNinho()->getFormigas()[i].posy;
			avatar = mundo.getComunidades()[i].getNinho()->getFormigas()[i].avatar;
			grelha[posx][posy] = mundo.getComunidades()[i].getNinho()->getFormigas()[i].getTipo();
			Consola::gotoxy(posx, posy + LIMIAR);
			cout << avatar;
		}

	}
	

	// RETORNA À POSICAO ORIGINAL NO ECRA
	Consola::gotoxy(1, mundo.getLimite() + LIMIAR + 1);
	}

void info(Mundo & mundo)
{
	cout << mundo.toString();
}


void continuarJogo() {
	Consola::clrscr();
	cout << "Continua jogo...";
}


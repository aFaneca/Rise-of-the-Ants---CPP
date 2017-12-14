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
	char ident1 = 175;
	char ident2 = 254;
	char ident3 = 248;
} desenho;


int main() {
	
	//setlocale(LC_ALL, "Portuguese"); <- causa bug com os caractéres ascii
	int opt;
	//Ninho n;
	srand(time(NULL));
	Consola::setScreenSize(1000, 4000);  // linhas colunas. valores grandes pode nao dar
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


void listaNinho(int id, Mundo &mundo) {
	Consola::gotoxy(1, mundo.getLimite() + LIMIAR + 5);
	cout << "## INFO DO NINHO ##" << endl;
	cout << "-> Comunidade " << mundo.getComunidades()[id - 1].getId() << endl;
	cout << "\t " << (char)desenho.ident1 << " Formigas: (TOTAL: " << mundo.getComunidades()[id - 1].getNinho()->getFormigas().size() << " )" << endl;
	for (int j = 0; j < mundo.getComunidades()[id - 1].getNinho()->getFormigas().size(); j++) {
		cout << "\t\t" << (char)desenho.ident2 << " Formiga " << mundo.getComunidades()[id - 1].getNinho()->getFormigas()[j].getId() << endl;
		cout << "\t\t\t" << (char)desenho.ident3 << " TIPO: " << mundo.getComunidades()[id - 1].getNinho()->getFormigas()[j].getTipo() << endl;
		cout << "\t\t\t" << (char)desenho.ident3 << " Energia: " << mundo.getComunidades()[id - 1].getNinho()->getFormigas()[j].getEnergia() << endl;
		cout << "\t\t\t" << (char)desenho.ident3 << " Posicao: (" << mundo.getComunidades()[id - 1].getNinho()->getFormigas()[j].posx << ", " << 
			mundo.getComunidades()[id - 1].getNinho()->getFormigas()[j].posy << ")" <<endl;
	}
}

void listaMundo(Mundo & mundo) {
	Consola::gotoxy(1, mundo.getLimite() + LIMIAR + 5);
	cout << "## INFO DO MUNDO ##" << endl;
	cout << "Comunidades ( TOTAL: " << mundo.getComunidades().size() << ")" << endl;
	for (int i = 0; i < mundo.getComunidades().size(); i++) {
		cout <<"-> Comunidade " << mundo.getComunidades()[i].getId() << endl;
		cout << "\t " << (char)desenho.ident1 << " Formigas: (TOTAL: " << mundo.getComunidades()[i].getNinho()->getFormigas().size() << " )" << endl;
		// LISTAGEM DAS FORMIGAS - DESNECESSARIO NESTE COMANDO - VER LISTANINHO()
	/*	for (int j = 0; j < mundo.getComunidades()[i].getNinho()->getFormigas().size(); j++) {
			cout << "\t\t" << (char)desenho.ident2 << " Formiga " << mundo.getComunidades()[i].getNinho()->getFormigas()[j].getId() << endl;
			cout << "\t\t\t" << (char)desenho.ident3 << " TIPO: " << mundo.getComunidades()[i].getNinho()->getFormigas()[j].getTipo() << endl;
			cout << "\t\t\t" << (char)desenho.ident3 << " Energia: " << mundo.getComunidades()[i].getNinho()->getFormigas()[j].getEnergia() << endl;
		}
		*/
	}
	// RETORNA À POSICAO ORIGINAL NO ECRA
	Consola::gotoxy(1, mundo.getLimite() + LIMIAR + 1);
}


void listaPosicao(int x, int y, Mundo & mundo) {
	int total = 0;
	Consola::gotoxy(1, mundo.getLimite() + LIMIAR + 5);
	cout << "## INFO DO NINHO (" << x << ", " << y << ") ##" << endl;
	for (int i = 0; i < mundo.getComunidades().size(); i++) {
		int px = mundo.getComunidades()[i].posx;
		int py = mundo.getComunidades()[i].posy;
		if (px == x && py == y) {
			cout << "  " <<desenho.ident1 << " Ninho " << mundo.getComunidades()[i].getId() << endl;
			total++;
		}	
		for (int j = 0; j < mundo.getComunidades()[i].getNinho()->getFormigas().size(); j++) {
			int px = mundo.getComunidades()[i].getNinho()->getFormigas()[j].posx;
			int py = mundo.getComunidades()[i].getNinho()->getFormigas()[j].posy;
			if (px == x && py == y) {
				cout << "  " << desenho.ident1 << " Formiga " << mundo.getComunidades()[i].getId() << endl;
				total++;
			}		
		}
	}
	cout << "\t" << desenho.ident2 << " TOTAL: " << total;
}


bool ocupada(int x, int y)
{
	
	 if (grelha[x-1][y-1] == 'V')
		return false;

	return true;
	
}

bool validaPos(int x, int y, int dx, int dy, int limite) {
	x += dx;
	y += dy;
	
	if (x < 1 || y < 1 || x > limite || y > limite) //SE NÃO ULTRAPASSAR OS LIMITES
		return false;
	else {
		if (!ocupada(x, y)) { // SE NÃO ESTIVER OCUPADA
			return true;
		}
	}

	return false;
	}

void addGrelha(int x, int y, char avatar) {
	grelha[x - 1][y - 1] = avatar;
}

void movimentos(Mundo & mundo) {
	for (int i = 0; i < mundo.getComunidades().size(); i++) {
		// VERIFICA NINHOS
		for (int j = 0; j < mundo.getComunidades()[i].getNinho()->getFormigas().size(); j++) {
			// VERIFICA AS FORMIGAS DE CADA NINHO
			mundo.getComunidades()[i].getNinho()->getFormigas()[j].mover(mundo.getLimite());

			cout << "MOVIMENTOS: " << mundo.getComunidades()[i].getNinho()->getFormigas()[j].posx << " - " << mundo.getComunidades()[i].getNinho()->getFormigas()[j].posy;
		}
	}
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
	//info(mundo);
	
	
	grelha.clear();
	grelha.resize(mundo.getLimite());
	for (int i = 0; i < mundo.getLimite(); i++)
		grelha[i].resize(mundo.getLimite());

	for (int i = 0; i < mundo.getLimite(); i++) {
		for (int j = 0; j < mundo.getLimite(); j++) {
			grelha[i][j] = 'V';
			//cout << grelha[i][j];
		}
		cout << endl;
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
		grelha[posx-1][posy-1] = 'N';
		Consola::gotoxy(posx, posy + LIMIAR);
		cout << avatar;

		for (int j = 0; j < mundo.getComunidades()[i].getNinho()->getFormigas().size(); j++) {
			// VERIFICA AS FORMIGAS DE CADA NINHO
			posx = mundo.getComunidades()[i].getNinho()->getFormigas()[j].posx;
			posy = mundo.getComunidades()[i].getNinho()->getFormigas()[j].posy;
			avatar = mundo.getComunidades()[i].getNinho()->getFormigas()[j].avatar;
			grelha[posx-1][posy-1] = mundo.getComunidades()[i].getNinho()->getFormigas()[j].getTipo();
			
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


#include "header.h"

vector<string> divideEmPalavras(string str) {
	istringstream iss(str);
	vector<string> palavra;
	while (iss) {
		string word;
		iss >> word;
		palavra.push_back(word);
	}

	return palavra;
}

bool valida(string comando, int *limite, double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida) {
	vector<string> palavra = divideEmPalavras(comando);
	
	//cout << "A validar " << comando << "...";

	if (palavra[0] == "defmundo") {
		if (palavra.size() != 2 + 1)
			cout << "Será que quis dizer \"defmundo <limite>\"?";
		else {
			try {
				*limite = stoi(palavra[1]);
				if (*limite < 10)
					cout << "Limite Inválido! Limite >= 10";
				else {
					cout << "Limite Definido para " << *limite << " com sucesso."; // VALIDAÇÃO CONCLUIDA COM SUCESSO
					return true;
				}
			}catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"defmundo <limite>\"";
			}
			
		}
	}
	else if (palavra[0] == "defen") {
		if (palavra.size() != 2 + 1)
			cout << "Será que quis dizer \"defen <energia> \"?";
		else {
			try {
				 *energiaInicialNinhos = stoi(palavra[1]);
				cout << "Valor Inicial de Energia dos Ninhos definido para " << *energiaInicialNinhos << " com sucesso.";
				return true;
			}catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"defen <energia> \"";
			}
			
		}
	}
	else if (palavra[0] == "defpc") {
		if (palavra.size() != 2 + 1)
			cout << "Será que quis dizer \"defpc <valor (%)> \"?";
		else {
			try {
				*valorEnergia = stoi(palavra[1]);
				cout << "Percentagem de Energia dos Ninhos definido para " << *valorEnergia << " com sucesso.";
				return true;
			}catch (const invalid_argument& ia) {
				cerr << "Formato Inválido: \"defpc <valor (%)> \"";
			}
		}
	}
	else if (palavra[0] == "defvt") {
		if (palavra.size() != 2 + 1)
			cout << "Será que quis dizer \"defvt <valor> \"?";
		else {
			try {
				*energiaTransferida = stoi(palavra[1]);
				cout << "Unidades de Energia transferidas Ninho <-> Formiga definidas para " << *energiaTransferida << " com sucesso.";
				return true;
			}catch (const invalid_argument& ia) {
				cerr << "Formato Inválido: \"defvt <valor> \"";
			}	
		}
	}
	else if (palavra[0] == "defmi") {
		if (palavra.size() != 2 + 1)
			cout << "Será que quis dizer \"defmi <valor (%) [0-100]> \"?";
		else {
			try {
				*posComMigalhas = stoi(palavra[1]);
				cout << "Posições iniciais vazias com migalhas definidas para " << *posComMigalhas << " com sucesso.";
				return true;
			}catch (const invalid_argument& ia) {
				cerr << "Formato Inválido: \"defmi <valor (%) [0-100]> \"";
			}
			
		}
	}
	else if (palavra[0] == "defme") {
		if (palavra.size() != 2 + 1)
			cout << "Será que quis dizer \"defme <energia> \"?";
		else {
			try {
				*energiaInicialMigalhas = stoi(palavra[1]);
				cout << "Energia Inicial das Novas Migalhas definida para " << *energiaInicialMigalhas << " com sucesso.";
				return true;
			}catch (const invalid_argument& ia) {
				cerr << "Formato Inválido: \"defme <energia> \"";
			}
		}
	}
	else if (palavra[0] == "defnm") {
		if (palavra.size() != 2 + 1)
			cout << "Será que quis dizer \"defnm <max> \"?";
		else {
			try {
				*maxMigalhas = stoi(palavra[1]);
				cout << "Número Máximo de Migalhas definido para " << *maxMigalhas << " com sucesso.";
				return true;
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido: \"defme <energia> \"";
			}
		}
	}
	else if (palavra[0] == "executa") {
		if (palavra.size() != 2 + 1)
			cout << "Será que quis dizer \"executa <nomeFicheiro> \"?";
		else {
			cout << "A executar ficheiro...";
			return true;
		}
	}

	return false;
}

void sair() {
	exit(0);
}
void continuarJogo() {
	Consola::clrscr();
	cout << "Continua jogo...";
}

void novoJogo() {
	bool defmundo = false, defen = false, defpc = false, defvt = true, defmi = false, defme = false, defnm = false, executa = false;
	int limite;
	double energiaInicialNinhos;
	double valorEnergia;
	int posComMigalhas;
	double energiaInicialMigalhas;
	int maxMigalhas;
	double energiaTransferida;
	string comando;
	Consola::setScreenSize(50, 80);
	Consola::setBackgroundColor(Consola::PRETO);
	Consola::setTextColor(Consola::VERDE);
	Consola::clrscr();
	cout << "Novo Jogo...";

	while (1) {
		cout << "\n> ";
		getline(cin, comando);
		//cout << comando;
		if (!comando.compare(0, 9, "defmundo ")) {
			if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				cout << "DEFMUNDO: " << limite;
				defmundo = true;
			}
		}
		else if (!comando.compare(0, 6, "defen ")) {
			if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				defen = true;
			}
		}
		else if (!comando.compare(0, 6, "defpc ")) {
			if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				defpc = true;
			}
		}
		else if (!comando.compare(0, 6, "defvt ")) {
			if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				defvt = true;
			}
		}
		else if (!comando.compare(0, 6, "defmi ")) {
			if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				defmi = true;
			}
		}
		else if (!comando.compare(0, 6, "defme ")) {
			if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				defme = true;
			}
		}
		else if (!comando.compare(0, 6, "defnm ")) {
			if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				defnm = true;
			}
		}
		else if (!comando.compare(0, 8, "executa ")) {
			if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				executa = true;
			}
		}
		else if (!comando.compare(0, 6, "inicia")) {
			//if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
			if (defmundo = defen = defpc = defvt = defmi = defme = defnm == true) {
				// INICIAR
			}
			else {
				cerr << "Algumas configurações em falta!";
			}

			
		}
		else if (!comando.compare("abortar")) {
			break;
		}else {
			cout << "Erro de Sintaxe!";
		}
		cin.ignore(-1);
	}
}

void mostraMenu() {
	Consola::clrscr();
	cout << "## Menu ##" << endl;
	cout << "[1] NOVO JOGO\n[2] CONTINUAR JOGO\n[3] SAIR" << endl;
	cout << "> ";
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int opt;
	
	Consola::setScreenSize(800, 600);  // linhas colunas. valores grandes pode nao dar
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



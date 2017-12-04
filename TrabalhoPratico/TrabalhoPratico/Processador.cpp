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

bool valida(vector<string> palavra, int *limite, double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida) {
	//vector<string> palavra = divideEmPalavras(comando);
	
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
				if (*posComMigalhas < 0 || *posComMigalhas > 100)
					throw invalid_argument("Valor deve igual ou superior a 0 e igual ou superior a 100.");

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
	else {
		cout << "Comando não reconhecido...";
	}
	return false;
}

string executaFicheiro(string nomeFicheiro, int linha) {
	ifstream ficheiro;
	string comando;
	ficheiro.open(nomeFicheiro);

	if (ficheiro.is_open()){
		for (int i = 0; i < linha; i++) {
			getline(ficheiro, comando);
			if(!ficheiro){
				comando == "null";
			}
		}
	} else comando = "null"; 

	ficheiro.close();
	return comando; // LEITURA DO FICHEIRO EFETUADA COM SUCESSO
}

int contaLinhasFicheiro(string nomeFicheiro) {
	int nrlinhas = 0;
	string linha;
	ifstream ficheiro(nomeFicheiro);
	if (!ficheiro) {
		cout << "Ficheiro não encontrado :/";
		return -1;
	}
	while (getline(ficheiro, linha))
		++nrlinhas;

	return nrlinhas;
}
// PROCESSA COMANDOS LIDOS DE UM FICHEIRO
bool processaComandos(string nomeFicheiro, bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa, int *limite,
	double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida) {
	int linha = 1;
	string comando;
	int nrlinhas = contaLinhasFicheiro(nomeFicheiro);
	if (nrlinhas == -1)
		return false;
	for(int i = 0; i < nrlinhas; i++){
		comando = executaFicheiro(nomeFicheiro, i+1);
		cout << "\n";
		//cout << "\n> ";
		//getline(cin, comando);

		vector<string> palavra = divideEmPalavras(comando);
		//cout << comando;
		if (!comando.compare(0, 9, "defmundo ")) {
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defmundo = true;
			}
		}
		else if (!comando.compare(0, 6, "defen ")) {
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defen = true;
			}
		}
		else if (!comando.compare(0, 6, "defpc ")) {
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defpc = true;
			}
		}
		else if (!comando.compare(0, 6, "defvt ")) {
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defvt = true;
			}
		}
		else if (!comando.compare(0, 6, "defmi ")) {
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defmi = true;
			}
		}
		else if (!comando.compare(0, 6, "defme ")) {
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defme = true;
			}
		}
		else if (!comando.compare(0, 6, "defnm ")) {
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defnm = true;
			}
		}
		else if (!comando.compare(0, 6, "inicio")) {
			//if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
			if (*defmundo = *defen = *defpc = *defvt = *defmi = *defme = *defnm == true) {
				// INICIAR
			}
			else {
				cerr << "Algumas configurações em falta!";
			}
		}
		else if (!comando.compare("abortar")) {
			cout << "Abortado. Clique em qualquer tecla para sair...";
			break;
		}
		else {
			cout << "Erro de Sintaxe!";
		}
		//cin.ignore(-1);
	}

	return true; // TAREFA REALIZADA COM SUCESSO
}

// PROCESSA COMANDOS LIDOS DA LINHA DE COMANDOS
void processaComandos(bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa) {
	int limite;
	double energiaInicialNinhos;
	double valorEnergia;
	int posComMigalhas;
	double energiaInicialMigalhas;
	int maxMigalhas;
	double energiaTransferida;
	string comando;
	while (1) {
		cout << "\n> ";
		getline(cin, comando);
		
		vector<string> palavra = divideEmPalavras(comando);
		//cout << comando;
		if (!comando.compare(0, 9, "defmundo ")) {
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				cout << "DEFMUNDO: " << limite;
				*defmundo = true;
			}
		}
		else if (!comando.compare(0, 6, "defen ")) {
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defen = true;
			}
		}
		else if (!comando.compare(0, 6, "defpc ")) {
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defpc = true;
			}
		}
		else if (!comando.compare(0, 6, "defvt ")) {
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defvt = true;
			}
		}
		else if (!comando.compare(0, 6, "defmi ")) {
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defmi = true;
			}
		}
		else if (!comando.compare(0, 6, "defme ")) {
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defme = true;
			}
		}
		else if (!comando.compare(0, 6, "defnm ")) {
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defnm = true;
			}
		}
		else if (!comando.compare(0, 8, "executa ")) {

			//if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*executa = true;
				processaComandos(palavra[1], defmundo, defen, defpc, defvt, defmi, defme, defnm, executa, &limite,
					&energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida);
			/*	lerDoFicheiro = true;
				// EXECUTA COMANDOS DO FICHEIRO
				linha = 1;
				comando = executaFicheiro(palavra[1], linha);
				while (comando.compare("null")) {
					cout << "\nlinha lida: " << comando;
					linha++;
					comando = executaFicheiro(palavra[1], linha);
				}
				
				
				lerDoFicheiro = false;
				*/
			//}
		}
		else if (!comando.compare(0, 6, "inicio")) {
			//if (valida(comando, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
			if (*defmundo = *defen = *defpc = *defvt = *defmi = *defme = *defnm == true) {
				// INICIAR
			}
			else {
				cerr << "Algumas configurações em falta!";
			}
		}
		else if (!comando.compare("abortar")) {
			cout << "Abortado. Clique em qualquer tecla para sair...";
			break;
		}
		else {
			cout << "Erro de Sintaxe!";
		}
		cin.ignore(-1);
	}
}










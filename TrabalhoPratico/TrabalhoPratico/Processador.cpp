#include "Processador.h"
#include "Mundo.h"
#include "Ninho.h"
#include "Comunidade.h"
using namespace std;
vector<string> Processador::divideEmPalavras(string str) {
	istringstream iss(str);
	vector<string> palavra;
	while (iss) {
		string word;
		iss >> word;
		palavra.push_back(word);
	}

	return palavra;
}


//VALIDA COMANDOS
bool Processador::valida(vector<string> palavra, int *limite, double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida) {
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

		return false;
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
	else if (palavra[0] == "ninho") {
		if (palavra.size() != 3 + 1) {
			cout << "Será que quis dizer \"ninho <linha> <coluna>\"?";
		}
		else {
			try {
				int posy = stoi(palavra[1]);
				int posx = stoi(palavra[2]);

				if (posy <= *limite && posx <= *limite && posy > 0 && posx > 0)
					return true;
				else {
					cerr << "Coordenadas invalidas! (Fora do limite definido)";
				}
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"ninho <linha> <coluna>\"";
				return false;
			}
		}
	}
	else if (palavra[0] == "criaf") {
		if (palavra.size() != 4 + 1) {
			cout << "Será que quis dizer \"criaf <F> <T> <N>\"?";
		}
		else if (palavra[2].size() != 1 || (palavra[2].compare("E") != 0 && palavra[2].compare("C") != 0 &&
			palavra[2].compare("V") != 0 && palavra[2].compare("A") != 0 && palavra[2].compare("S") != 0)) {
			cerr << "Tipo de Formiga inválido.";
		}
		else {
			try {
				int nFormigas = stoi(palavra[1]);
				return true;
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"criaf <F> <T> <N>\"";
				return false;
			}
		}
	}
	else if (palavra[0] == "cria1") { 
		// cria1 <TIPO> <NINHO> <LINHA> <COLUNA>
		if (palavra.size() != 5 + 1) {
			cout << "Será que quis dizer \"cria1 <T> <N> <linha> <coluna>\"?";
		}
		else if (palavra[1].size() != 1 || (palavra[1].compare("E") != 0 && palavra[1].compare("C") != 0 &&
			palavra[1].compare("V") != 0 && palavra[1].compare("A") != 0 && palavra[1].compare("S") != 0)) { // VERIFICAR SE O TIPO É CORRETO
			cerr << "Tipo de Formiga inválido.";
		}
		else {
			try { // VERIFICAR SE <N>, <linha> e <coluna> são números inteiros
				stoi(palavra[2]);
				int posy = stoi(palavra[3]);
				int posx = stoi(palavra[4]);

				if (posy <= *limite && posx <= *limite && posy > 0 && posx > 0)
					return true;
				else {
					cerr << "Coordenadas invalidas! (Fora do limite definido)";
				}

			}catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"cria1 <T> <N> <linha> <coluna>\"";
				return false;
			}
		}
	}
	else if (palavra[0] == "listaninho") {
		if (palavra.size() != 2 + 1) {
			cout << "Será que quis dizer \"listaninho <N>\"?";
		}else {
			try {
				int idNinho = stoi(palavra[1]);
				return true;
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"listaninho <N>\"";
				return false;
			}
		}
	}
	else if (palavra[0] == "listaposicao") {
		if (palavra.size() != 3 + 1) {
			cout << "Será que quis dizer \"listaninho <linha> <coluna>\"?";
		}
		else {
			try {
				int x = stoi(palavra[2]);
				int y = stoi(palavra[1]);
				return true;
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"listaninho <linha> <coluna>\"";
				return false;
			}
		}
	}
	else if (palavra[0] == "energformiga") {
		if (palavra.size() != 4 + 1) {
			cout << "Será que quis dizer \"energformiga <linha> <coluna> <E>\"?";
		}
		else {
			try {
				stoi(palavra[2]);
				stoi(palavra[1]);
				stoi(palavra[3]);
				return true;
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"energformiga <linha> <coluna> <E>\"";
				return false;
			}
		}
	}
	else if (palavra[0] == "energninho") {
		if (palavra.size() != 3 + 1) {
			cout << "Será que quis dizer \"energninho <N> <E>\"?";
		}
		else {
			try {
				stoi(palavra[1]);
				stoi(palavra[2]);
				return true;
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"energninho <N> <E>\"";
				return false;
			}
		}
	}
	else if (palavra[0] == "inseticida") {
		if (palavra.size() != 2 + 1) {
			cout << "Será que quis dizer \"inseticida <N>\"?";
		}
		else {
			try {
				stoi(palavra[1]);
				return true;
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"inseticida <N>\"";
				return false;
			}
		}
	}
	else if (palavra[0] == "mata") {
		if (palavra.size() != 3 + 1) {
			cout << "Será que quis dizer \"mata <linha> <coluna>\"?";
		}
		else {
			try {
				stoi(palavra[2]);
				stoi(palavra[1]);
				return true;
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"mata <linha> <coluna>\"";
				return false;
			}
		}
	}
	else if (palavra[0] == "migalha") {
		if (palavra.size() != 3 + 1) {
			cout << "Será que quis dizer \"migalha <linha> <coluna>\"?";
		}
		else {
			try { // VERIFICAR SE <N>, <linha> e <coluna> são números inteiros
				int posx = stoi(palavra[2]);
				int posy = stoi(palavra[1]);

				if (posy <= *limite && posx <= *limite && posy > 0 && posx > 0)
					return true;
				else {
					cerr << "Coordenadas invalidas! (Fora do limite definido)";
				}
			}
			catch (const invalid_argument& ia) {
				cerr << "Formato Inválido:  \"migalha <linha> <coluna>\"";
				return false;
			}
		}
		
	}
	else {
		cout << "Comando não reconhecido...";
	}
	return false;
}

string Processador::executaFicheiro(string nomeFicheiro, int linha) {
	ifstream ficheiro;
	string comando;
	ficheiro.open(nomeFicheiro);

	if (ficheiro.is_open()){
		for (int i = 0; i < linha; i++) {
			getline(ficheiro, comando);
			if(!ficheiro){
				comando == "ERRO! O ficheiro chegou ao fim!";
			}
		}
	} else comando = "ERRO! Impossível abrir o ficheiro (sera que o processo esta ocupado? ou talvez o documento ja nao exista..."; 

	ficheiro.close();
	return comando; // LEITURA DO FICHEIRO EFETUADA COM SUCESSO
}

int Processador::contaLinhasFicheiro(string nomeFicheiro) {
	int nrlinhas = 0;
	string linha;
	ifstream ficheiro(nomeFicheiro);
	if (!ficheiro) {
		cout << "Ficheiro nao encontrado :/";
		return -1;
	}
	while (getline(ficheiro, linha))
		++nrlinhas;

	return nrlinhas;
}
// PROCESSA COMANDOS LIDOS DE UM FICHEIRO
bool Processador::processaComandos(string nomeFicheiro, bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa, bool *inicio, int *limite,
	double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas, double *energiaInicialMigalhas, 
		int *maxMigalhas, double *energiaTransferida, Mundo &mundo, Interface &i1) {
	int linha = 1;
	string comando;
	int nrlinhas = contaLinhasFicheiro(nomeFicheiro);
	if (nrlinhas == -1)
		return false;
	
	for(int i = 0; i < nrlinhas; i++){
		if (nrlinhas == 0)
			Consola::clrscr();
		comando = executaFicheiro(nomeFicheiro, i+1);
		cout << "\n";
		
		vector<string> palavra = divideEmPalavras(comando);
		if (!comando.compare(0, 9, "defmundo ")) {
			Consola::clrscr();
			if (!(*inicio)) {
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					*defmundo = true;
				}
			}else {
				cerr << "A simulacao já se encontra a decorrer. Não pode fazer alterações a este campo!";
			}
		}
		else if (!comando.compare(0, 6, "defen ")) {
			Consola::clrscr();
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defen = true;
				if (*inicio)
					mundo.setEnergiaInicialNinhos(stod(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defpc ")) {
			Consola::clrscr();
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defpc = true;
				if (*inicio)
					mundo.setValorEnergia(stod(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defvt ")) {
			Consola::clrscr();
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defvt = true;
				if (*inicio)
					mundo.setEnergiaTransferida(stod(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defmi ")) {
			Consola::clrscr();
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defmi = true;
				if (*inicio)
					mundo.setPosComMigalhas(stoi(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defme ")) {
			Consola::clrscr();
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defme = true;
				if (*inicio)
					mundo.setEnergiaInicialMigalhas(stod(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defnm ")) {
			Consola::clrscr();
			if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
				*defnm = true;
				if (*inicio)
					mundo.setMaxMigalhas(stoi(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "ninho ")) {
			i1.mostraMundo(mundo);
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					if (!mundo.ocupada(stoi(palavra[2]), stoi(palavra[1]))) {
						mundo.addComunidade(stoi(palavra[1]), stoi(palavra[2]));
					}else
						cerr << "Ja existe um elemento nessa posicao!";
				}
			}
		}
		else if (!comando.compare(0, 6, "criaf ")) {
			i1.mostraMundo(mundo);
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				bool encontrou = false;
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					//cout << stoi(palavra[1]) << stoi(palavra[2]);
					//mundo.addComunidade(stoi(palavra[1]), stoi(palavra[2]));
					//VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[3])) {
							//ADICIONAR FORMIGAS AO NINHO
							for (int j = 0; j < (int)stoi(palavra[1]); j++)
								mundo.addFormiga2Ninho(mundo.getComunidades()[i]->getId(), palavra[2].at(0));
							encontrou = true;
						}
					}
					if (encontrou == false)
						cerr << "O Ninho nao foi encontrado (ID ERRADO?)";
				}
			}
		}
		else if (!comando.compare(0, 6, "cria1 ")) {
			i1.mostraMundo(mundo);   // cria1 <TIPO> <NINHO> <LINHA> <COLUNA>
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else{
				bool encontrou = false;
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					//VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[2])) {
							//ADICIONAR FORMIGA AO NINHO
							if (mundo.ocupada(stoi(palavra[4]), stoi(palavra[3]))) {
								cerr << "A posicao (" << stoi(palavra[4]) << ", " << stoi(palavra[3]) << ") ja se encontra ocupada.";
								encontrou = true;
								break;
							}
							else {
								mundo.addFormiga2Ninho(mundo.getComunidades()[i]->getId(), palavra[1].at(0), stoi(palavra[4]), stoi(palavra[3]));
								encontrou = true;
							}
						}
					}
					if (encontrou == false)
						cerr << "O Ninho nao foi encontrado (ID ERRADO?) :: ";
				}
			}
		}
		else if (!comando.compare(0, 5, "tempo") && palavra.size() < 4) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (palavra.size() == 3) {
					for(int i = 0; i < stoi(palavra[1]); i++)
						i1.movimentos(mundo);
				}
				else {
					i1.movimentos(mundo);
				}
				
			}
		}
		else if (!comando.compare(0, 6, "inicio")) {
			Consola::clrscr();
			if (*defmundo = *defen = *defpc = *defvt = *defmi = *defme = *defnm == true) {
				*inicio = true;
				iniciaSimul(limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida, mundo);
			}
			else {
				cerr << "Algumas configuracoes em falta!";
			}
		}
		else if (!comando.compare(0, 11, "listaninho ")) {
			i1.mostraMundo(mundo);
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				bool encontrou = false;
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					//VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[1])) {
							// SE EXISTIR
							i1.listaNinho(stoi(palavra[1]), mundo);
							encontrou = true;
						}
					}
					if (encontrou == false)
						cerr << "O Ninho nao foi encontrado (ID ERRADO?)";
				}
			}
		}
		else if (!comando.compare(0, 13, "listaposicao ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {

					//VERIFICAR SE A POSICAO EXISTE
					int x = stoi(palavra[2]);
					int y = stoi(palavra[1]);

					if (x < 1 || y < 1 || x > *limite || y > *limite) //SE NÃO ULTRAPASSAR OS LIMITES
						cerr << "Posicao Invalida.";
					else
						i1.listaPosicao(y, x, mundo);
				}
			}
		}
		else if (!comando.compare("listamundo")) {
			Consola::clrscr();
			if (*inicio)
				i1.listaMundo(mundo);
			else
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
		}
		else if (!comando.compare(0, 11, "energninho ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				bool encontrou = false;
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					//VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[1])) {
							//ADICIONAR ENERGIA AO NINHO
							mundo.addEnergia2Ninho(mundo.getComunidades()[i]->getId(), stoi(palavra[2]));
							encontrou = true;
						}
					}
					if (encontrou == false)
						cerr << "O Ninho não foi encontrado (ID ERRADO?)";

				}

			}
		}
		else if (!comando.compare(0, 13, "energformiga ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				bool encontrou = false;
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					//VERIFICAR SE EXISTE ALGUMA FORMIGA NA POSIÇÃO
					int posx = stoi(palavra[2]);
					int posy = stoi(palavra[1]);
					int valorEnergia = stoi(palavra[3]);


					if (posx < 1 || posy < 1 || posx > *limite || posy > *limite) //SE NÃO ULTRAPASSAR OS LIMITES
						cerr << "Posicao Invalida.";
					else {
						if (mundo.temFormiga(posx, posy))
							mundo.addEnergia2Formiga(posx, posy, valorEnergia);
						else
							cerr << "Nenhuma formiga foi encontrada na posicao (" << posx << ", " << posy << ")";
					}



				}

			}
		}
		else if (!comando.compare(0, 11, "inseticida ")) {
			bool encontrou = false;
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					// VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[1])) {
							// SE EXISTIR
							mundo.eliminaNinho(mundo.getComunidades()[i]->getId());
							encontrou = true;
						}
					}
					if (encontrou == false)
						cerr << "O Ninho não foi encontrado (ID ERRADO?)";
				}
			}
		}
		else if (!comando.compare(0, 5, "mata ")) {
			bool encontrou = false;
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					// VERIFICAR SE A POSICAO TEM FORMIGA
					int posx = stoi(palavra[2]);
					int posy = stoi(palavra[1]);

					if (posx < 1 || posy < 1 || posx > *limite || posy > *limite) //SE NÃO ULTRAPASSAR OS LIMITES
						cerr << "Posicao Invalida.";
					else {
						if (mundo.temFormiga(posx, posy))
							mundo.mataFormiga(posx, posy);
						else
							cerr << "Nenhuma formiga foi encontrada em (" << posx << ", " << posy << ").";
					}

				}
			}
		}
		else if (!comando.compare(0, 8, "migalha ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, limite, energiaInicialNinhos, valorEnergia, posComMigalhas, energiaInicialMigalhas, maxMigalhas, energiaTransferida)) {
					//VERIFICAR SE A POSICAO ESTÁ LIVRE
					int posx = stoi(palavra[2]);
					int posy = stoi(palavra[1]);

					if (!mundo.ocupada(posx, posy))
						mundo.addMigalha(posx, posy);
					else
						cerr << "A posicao (" << posx << ", " << posy << ") ja se encontra ocupada.";
				}

			}
		}
		else if (!comando.compare("sair")) {
			Consola::clrscr();
			//DESTRUIR PONTEIRO PARA NINHO
			for (int i = 0; i < mundo.getComunidades().size(); i++)
				mundo.getComunidades()[i]->destruir();

			cout << "Abortado. Clique em qualquer tecla para sair...";
			break;
		}
		else {
			cout << "Erro de Sintaxe!";
		}
	}

	return true; // TAREFA REALIZADA COM SUCESSO
}

// PROCESSA COMANDOS LIDOS DA LINHA DE COMANDOS
void Processador::processaComandos(bool *defmundo, bool *defen, bool *defpc, bool *defvt, bool *defmi, bool *defme, bool *defnm, bool *executa, bool *inicio, Interface &i1) {
	int limite;
	double energiaInicialNinhos;
	double valorEnergia;
	int posComMigalhas;
	double energiaInicialMigalhas;
	int maxMigalhas;
	double energiaTransferida = 1;
	string comando;
	Mundo mundo;
	int cnt = 0;
	cin.ignore();
	while (1) {
		if (*inicio) {
			if (mundo.getIniciado()) {
				i1.mostraMundo(mundo);
			}
		}
		cout << "\n> ";
		getline(cin, comando);
		vector<string> palavra = divideEmPalavras(comando);

		if (!comando.compare(0, 9, "defmundo ")) {
			Consola::clrscr();
			if (!(*inicio)) {
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
					*defmundo = true;
				}
			}
			else {
				cerr << "A simualcao ja se encontra a decorrer. Não pode fazer alteracoes a este campo!";
			}
		}
		else if (!comando.compare(0, 6, "defen ")) {
			Consola::clrscr();
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defen = true;
				if (*inicio)
					mundo.setEnergiaInicialNinhos(stod(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defpc ")) {
			Consola::clrscr();
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defpc = true;
				if (*inicio)
					mundo.setValorEnergia(stod(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defvt ")) {
			Consola::clrscr();
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defvt = true;
				if (*inicio)
					mundo.setEnergiaTransferida(stod(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defmi ")) {
			Consola::clrscr();
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defmi = true;
				if (*inicio)
					mundo.setPosComMigalhas(stoi(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defme ")) {
			Consola::clrscr();
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defme = true;
				if (*inicio)
					mundo.setEnergiaInicialMigalhas(stod(palavra[1]));
			}
		}
		else if (!comando.compare(0, 6, "defnm ")) {
			Consola::clrscr();
			if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
				*defnm = true;
				if (*inicio)
					mundo.setMaxMigalhas(stoi(palavra[1]));
			}
		}
		else if (!comando.compare(0, 8, "executa ")) {
			Consola::clrscr();
			*executa = true;
			processaComandos(palavra[1], defmundo, defen, defpc, defvt, defmi, defme, defnm, executa, inicio, &limite,
				&energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida, mundo, i1);
		}
		else if (!comando.compare(0, 6, "inicio")) {
			Consola::clrscr();
			if (*defmundo = *defen = *defpc = *defvt = *defmi = *defme = *defnm == true) {
				// INICIAR
				*inicio = true;
				i1.mostraMundo(mundo);
				iniciaSimul(&limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida, mundo);
			}
			else {
				cerr << "Algumas configurações em falta!";
			}
		}
		else if (!comando.compare("sair")) {
			cout << "Abortado. Clique em qualquer tecla para sair...";
			break;
		}
		else if (!comando.compare(0, 6, "ninho ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
					if (!mundo.ocupada(stoi(palavra[2]), stoi(palavra[1]))) {
						mundo.addComunidade(stoi(palavra[1]), stoi(palavra[2]));
					}
					else
						cerr << "Já existe um elemento nessa posição!";
				}
			}
		}
		else if (!comando.compare(0, 6, "criaf ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				bool encontrou = false;
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {

					//VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[3])) {
							//ADICIONAR FORMIGAS AO NINHO
							for (int j = 0; j < (int)stoi(palavra[1]); j++)
								mundo.addFormiga2Ninho(mundo.getComunidades()[i]->getId(), palavra[2].at(0));

							//mundo.getComunidades()[i]->getNinho()->addFormiga(palavra[2].at(0), mundo);
						//cout << stoi(palavra[3]);
							encontrou = true;
						}
					}
					if (encontrou == false)
						cerr << "O Ninho não foi encontrado (ID ERRADO?)";
				}
			}
		}
		else if (!comando.compare(0, 6, "cria1 ")) {
			i1.mostraMundo(mundo);   // cria1 <TIPO> <NINHO> <LINHA> <COLUNA>
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				bool encontrou = false;
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
					//VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[2])) {
							//ADICIONAR FORMIGA AO NINHO
							if (mundo.ocupada(stoi(palavra[4]), stoi(palavra[3]))) {
								cerr << "A posicao (" << stoi(palavra[4]) << ", " << stoi(palavra[3]) << ") ja se encontra ocupada.";
								encontrou = true;
								break;
							}
							else {
								mundo.addFormiga2Ninho(mundo.getComunidades()[i]->getId(), palavra[1].at(0), stoi(palavra[4]), stoi(palavra[3]));
								encontrou = true;
							}
						}
					}
					if (encontrou == false)
						cerr << "O Ninho nao foi encontrado (ID ERRADO?) :: ";
				}
			}
		}
		else if (!comando.compare(0, 5, "tempo") && palavra.size() < 4) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				
				if (palavra.size() == 3) {
					for (int i = 0; i < stoi(palavra[1]); i++)
						i1.movimentos(mundo);
				}
				else {
					i1.movimentos(mundo);
				}
				
			}
		}
		else if (!comando.compare("listamundo")) {
			Consola::clrscr();
			if(*inicio)
				i1.listaMundo(mundo);
			else
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
		}
		else if (!comando.compare(0, 11, "listaninho ")) {
			
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				bool encontrou = false;
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
					//VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[1])) {
							// SE EXISTIR
							i1.listaNinho(stoi(palavra[1]), mundo);
							encontrou = true;
						}
					}
					if (encontrou == false)
						cerr << "O Ninho não foi encontrado (ID ERRADO?)";
				}
			}
		}
		else if (!comando.compare(0, 13, "listaposicao ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {

					//VERIFICAR SE A POSICAO EXISTE
					int x = stoi(palavra[2]);
					int y = stoi(palavra[1]);

					if (x < 1 || y < 1 || x > limite || y > limite) //SE NÃO ULTRAPASSAR OS LIMITES
						cerr << "Posicao Invalida.";
					else
						i1.listaPosicao(x, y, mundo);
				}
			}
		}
		else if (!comando.compare(0, 11, "energninho ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				bool encontrou = false;
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
					//VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[1])) {
							//ADICIONAR ENERGIA AO NINHO
							mundo.addEnergia2Ninho(mundo.getComunidades()[i]->getId(), stoi(palavra[2]));
							encontrou = true;
						}
					}
					if (encontrou == false)
						cerr << "O Ninho não foi encontrado (ID ERRADO?)";
	
				}
				
			}
		}
		else if (!comando.compare(0, 13, "energformiga ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				bool encontrou = false;
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
					//VERIFICAR SE EXISTE ALGUMA FORMIGA NA POSIÇÃO
					int posx = stoi(palavra[2]);
					int posy = stoi(palavra[1]);
					int valorEnergia = stoi(palavra[3]);
					
					
					if (posx < 1 || posy < 1 || posx > limite || posy > limite) //SE NÃO ULTRAPASSAR OS LIMITES
						cerr << "Posicao Invalida.";
					else {
						if (mundo.temFormiga(posx, posy))
							mundo.addEnergia2Formiga(posx, posy, valorEnergia);
						else
							cerr << "Nenhuma formiga foi encontrada na posicao (" << posx << ", " << posy << ")";
					}
					
					

				}

			}
		}
		else if (!comando.compare(0, 11, "inseticida ")) {
			bool encontrou = false;
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
					// VERIFICAR SE O NINHO EXISTE
					for (int i = 0; i < mundo.getComunidades().size(); i++) {
						if (mundo.getComunidades()[i]->getId() == (int)stoi(palavra[1])) {
							// SE EXISTIR
							mundo.eliminaNinho(mundo.getComunidades()[i]->getId());
							encontrou = true;
						}
					}
					if (encontrou == false)
						cerr << "O Ninho não foi encontrado (ID ERRADO?)";
				}
			}
		}
		else if (!comando.compare(0, 5, "mata ")) {
			bool encontrou = false;
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
					// VERIFICAR SE A POSICAO TEM FORMIGA
					int posx = stoi(palavra[2]);
					int posy = stoi(palavra[1]);

					if (posx < 1 || posy < 1 || posx > limite || posy > limite) //SE NÃO ULTRAPASSAR OS LIMITES
						cerr << "Posicao Invalida.";
					else {
						if (mundo.temFormiga(posx, posy))
							mundo.mataFormiga(posx, posy);
						else
							cerr << "Nenhuma formiga foi encontrada em (" << posx << ", " << posy << ").";
					}
						
				}
			}
		}
		else if (!comando.compare(0, 8, "migalha ")) {
			Consola::clrscr();
			if (*inicio != true)
				cout << "Este comando so pode ser utilizado depois do inicio da simulacao.";
			else {
				if (valida(palavra, &limite, &energiaInicialNinhos, &valorEnergia, &posComMigalhas, &energiaInicialMigalhas, &maxMigalhas, &energiaTransferida)) {
					//VERIFICAR SE A POSICAO ESTÁ LIVRE
					int posx = stoi(palavra[2]);
					int posy = stoi(palavra[1]);

					if (!mundo.ocupada(posx, posy))
						mundo.addMigalha(posx, posy);
					else
						cerr << "A posicao (" << posx << ", " << posy << ") ja se encontra ocupada.";
				}

			}
		}
		else {
			Consola::clrscr();
			cout << "Erro de Sintaxe!";
		}
		cin.ignore(-1);
	}
}

void Processador::iniciaSimul(int *limite, double *energiaInicialNinhos, double *valorEnergia, int *posComMigalhas,
	double *energiaInicialMigalhas, int *maxMigalhas, double *energiaTransferida, Mundo &mundo) {
	mundo.Init(*limite, *energiaInicialNinhos, *valorEnergia, *posComMigalhas, *energiaInicialMigalhas, *maxMigalhas, *energiaTransferida);
}


Processador::Processador()
{
}


Processador::~Processador()
{
}

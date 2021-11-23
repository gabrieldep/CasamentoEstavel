#include <iostream>
#include "Cliente.h"
#include "Loja.h"
using namespace std;

int main(int argc, const char* argv[])
{
	//Tamanho do Grid
	int N = 0, M = 0, qtdLojas = 0;
	string result;
	char Linha[100];
	FILE* arquivo = fopen(argv[1], "rt");
	result = fgets(Linha, 100, arquivo);

	//Leitura para definir o tamanho do Grid
	int posicao = result.find(" ");
	N = stoi(result.substr(0, posicao));
	M = stoi(result.substr(posicao + 1, result.size()));

	//Leitura das lojas

	result = fgets(Linha, 100, arquivo);
	qtdLojas = stoi(result);
	Loja* lojas = new Loja[qtdLojas]();

	for(int i = 0; i < qtdLojas; i++)
	{
		result = fgets(Linha, 100, arquivo);
		if (result.size() == 0)break;
		int primeiroEspaco = result.find(" ");
		int segundoEspaco = result.find_last_of(" ");

		lojas[i] = *new Loja(i,
			stoi(result.substr(0, primeiroEspaco)),
			stoi(result.substr(primeiroEspaco + 1, segundoEspaco)),
			stoi(result.substr(segundoEspaco + 1, result.size())));
	}

	fclose(arquivo);
}

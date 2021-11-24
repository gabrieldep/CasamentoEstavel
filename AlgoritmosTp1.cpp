#include <iostream>
#include "Cliente.h"
#include "Loja.h"
#include <algorithm>

using namespace std;

bool MaiorTicket(Cliente* c1, Cliente* c2)
{
	return c1->GetTicket() == c2->GetTicket() ? 
		c1->GetIdentificacao() < c2->GetIdentificacao() : c1->GetTicket() < c2->GetTicket();
}

void SortClientes(vector<Cliente*>* clientes) {
	sort(clientes->begin(), clientes->end(), MaiorTicket);
}

int main(int argc, const char* argv[])
{
	//Tamanho do Grid
	int N = 0, M = 0, qtdLojas = 0, qtdClientes = 0;
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
	vector<Loja*>* lojas = new std::vector<Loja*>;

	for (int i = 0; i < qtdLojas; i++)
	{
		result = fgets(Linha, 100, arquivo);
		if (result.size() == 0)break;
		int primeiroEspaco = result.find(" ");
		int segundoEspaco = result.find_last_of(" ");

		lojas->push_back(new Loja(i,
			stoi(result.substr(0, primeiroEspaco)),
			stoi(result.substr(primeiroEspaco + 1, segundoEspaco)),
			stoi(result.substr(segundoEspaco + 1, result.size()))));
	}

	//Leitura dos clientes
	result = fgets(Linha, 100, arquivo);
	qtdClientes = stoi(result);
	vector<Cliente*>* clientes = new std::vector<Cliente*>;
	int* posicoes = new int[4]();
	for (int i = 0; i < qtdClientes; i++)
	{
		result = fgets(Linha, 100, arquivo);
		if (result.size() == 0)break;

		int aux = 0;
		for (int j = 0; j < result.size(); j++) {
			if (result[j] == ' ') {
				posicoes[aux] = j;
				aux++;
			}
		}

		string uf = result.substr(posicoes[0] + 1, posicoes[1] - 2);

		clientes->push_back(new Cliente(i,
			stoi(result.substr(0, posicoes[0])),
			result.substr(posicoes[0] + 1, 2),
			result.substr(posicoes[1] + 1, 6),
			stoi(result.substr(posicoes[2] + 1, result.size())),
			stoi(result.substr(posicoes[3] + 1, result.size()))));
	}
	SortClientes(clientes);
	fclose(arquivo);
}

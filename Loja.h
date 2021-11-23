#pragma once
#include <vector>
#include "Localizacao.h"
#include "Cliente.h"
class Cliente;

using namespace std;

class Loja
{
private:
	int identificacao;
	int estoque;
	int qtdClientes;
	Localizacao* localizacao;
	vector<Cliente*>* clientes;
public:
	Loja();
	Loja(int identificacao, int estoque, int x, int y);
	~Loja();
	void SetIdentificacao(int identificacao);
	void SetLocalizacao(Localizacao* localizacao);
	void SetEstoque(int estoque);
	int GetIdentificacao();
	Localizacao GetLocalizacao();
	int GetEstoque();
	void SomaEstoque(int i);
	void AddClienteFinal(Cliente* cliente);
	void AddClienteInicio(Cliente* cliente);
	void AddCliente(Cliente* cliente);
};


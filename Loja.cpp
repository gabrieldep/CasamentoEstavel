#include "Loja.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

Loja::Loja()
{
	this->identificacao = -1;
	this->estoque = -1;
	this->localizacao = new Localizacao();
	this->qtdClientes = -1;
	this->clientes = new std::vector<int>;
}

Loja::Loja(int identificacao, int estoque, int x, int y)
{
	this->identificacao = identificacao;
	this->estoque = estoque;
	this->localizacao = new Localizacao(x, y);
	this->qtdClientes = 0;
	this->clientes = new std::vector<int>;
}

Loja::~Loja()
{
	delete this->localizacao;
}

void Loja::SetIdentificacao(int identificacao)
{
	this->identificacao = identificacao;
}

void Loja::SetLocalizacao(Localizacao* localizacao)
{
	this->localizacao = localizacao;
}

void Loja::SetEstoque(int estoque)
{
	this->estoque = estoque;
}

int Loja::GetIdentificacao()
{
	return this->identificacao;
}

Localizacao Loja::GetLocalizacao()
{
	return *this->localizacao;
}

int Loja::GetEstoque()
{
	return this->estoque;
}

void Loja::SomaEstoque(int i)
{
	this->estoque += i;
}

bool Loja::AlocarClienteLoja(int idCliente, vector<Cliente*>* clientes)
{
	if (estoque == qtdClientes)
	{
		int maiorPosicaoNaFilaPrioridade = -1;
		int pessoaMenosPrioritariaAlocada = -1;
		for (int i = 0; i < estoque; i++)
		{
			int posicaoPessoaAtual = RetornaPosicaoCliente(idCliente, clientes);
			if (posicaoPessoaAtual > maiorPosicaoNaFilaPrioridade)
			{
				maiorPosicaoNaFilaPrioridade = posicaoPessoaAtual;
				pessoaMenosPrioritariaAlocada = clientes->at(i)->GetIdentificacao();
			}
		}

		int posicaoNaFilaPrioridadeNovaPessoa = RetornaPosicaoCliente(idCliente, clientes);
		if (posicaoNaFilaPrioridadeNovaPessoa < maiorPosicaoNaFilaPrioridade)
		{
			DesalocarClienteLoja(pessoaMenosPrioritariaAlocada);
			return AlocarClienteLoja(idCliente, clientes);
		}
		return false;
	}
	this->clientes->push_back(idCliente);
	qtdClientes++;

	return true;
}

void Loja::DesalocarClienteLoja(int idCliente)
{
	int posicaoPessoa = 0;
	for (int i = 0; i < estoque; i++)
	{
		if (this->clientes->at(i) == idCliente)
		{
			posicaoPessoa = i;
			break;
		}
	}

	this->clientes->erase(this->clientes->begin() + posicaoPessoa);

	qtdClientes--;
}

int Loja::RetornaPosicaoCliente(int idCliente, vector<Cliente*>* clientes)
{
	int i = 0;
	while (true)
	{
		if (clientes->at(i)->GetIdentificacao() == idCliente)
			return i;
		i++;
	}
	return -1;
}

void Loja::ListarClientesAlocadas()
{
	if (qtdClientes == 0)
		return;

	cout << this->identificacao << endl;
	for (int i = 0; i < qtdClientes; i++)
	{
		cout << this->clientes->at(i) << " ";
	}
	cout << endl;
}


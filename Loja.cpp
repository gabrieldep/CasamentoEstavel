#include "Loja.h"
#include <vector>

Loja::Loja()
{
	this->identificacao = 0;
	this->estoque = 0;
	this->localizacao = new Localizacao();
	this->qtdClientes = 0;
	this->clientes = new std::vector<Cliente*>;
}

Loja::Loja(int identificacao, int estoque, int x, int y)
{
	this->identificacao = identificacao;
	this->estoque = estoque;
	this->localizacao = new Localizacao(x, y);
	this->qtdClientes = 0;
	this->clientes = new std::vector<Cliente*>;
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

void Loja::AddClienteFinal(Cliente* cliente)
{
	this->clientes->push_back(cliente);
}

void Loja::AddClienteInicio(Cliente* cliente)
{
}

void Loja::AddCliente(Cliente* cliente, int posicao)
{

}

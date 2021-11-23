#include "Loja.h"

Loja::Loja()
{
	this->identificacao = 0;
	this->estoque = 0;
	this->localizacao = new Localizacao();
	*this->clientes = new Cliente[1]();
}

Loja::Loja(int identificacao, int estoque, int x, int y)
{
	this->identificacao = identificacao;
	this->estoque = estoque;
	this->localizacao = new Localizacao(x, y);
	*this->clientes = new Cliente[1]();
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

void Loja::SetClientes(int qtdClientes)
{
	*this->clientes = new Cliente[qtdClientes]();
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

Cliente* Loja::GetClientes()
{
	return *this->clientes;
}

void Loja::SomaEstoque(int i)
{
	this->estoque += i;
}

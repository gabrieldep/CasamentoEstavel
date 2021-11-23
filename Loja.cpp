#include "Loja.h"

Loja::Loja()
{
	this->identificacao = 0;
	this->estoque = 0;
	this->localizacao = new Localizacao();
}

Loja::Loja(int identificacao, int estoque, int x, int y)
{
	this->identificacao = identificacao;
	this->estoque = estoque;
	this->localizacao = new Localizacao(x, y);
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

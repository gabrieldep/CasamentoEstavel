#include "Loja.h"

void Loja::SetIdentificacao(int identificacao)
{
	this->identificacao = identificacao;
}

void Loja::SetLocalizacao(Localizacao* localizacao)
{
	this->localizacao = localizacao;
}

int Loja::GetIdentificacao()
{
	return this->identificacao;
}

Localizacao Loja::GetLocalizacao()
{
	return *this->localizacao;
}

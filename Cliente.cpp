#include "Cliente.h"

void Cliente::SetIdentificacao(int identificacao)
{
	this->identificacao = identificacao;
}

void Cliente::SetIdade(int idade)
{
	this->idade = idade;
}

void Cliente::SetUf(UF uf)
{
	this->uf = uf;
}

void Cliente::SetTipoPagamentoFrequente(TipoPagamento tipoPagamento)
{
	this->tipoPagamento = tipoPagamento;
}

void Cliente::SetLocalizacao(Localizacao* localizacao)
{
	this->localizacao = localizacao;
}

int Cliente::GetIdentificacao()
{
	return this->identificacao;
}

int Cliente::GetIdade()
{
	return this->idade;
}

UF Cliente::GetUf()
{
	return this->uf;
}

TipoPagamento Cliente::GetTipoPagamentoFrequente()
{
	return this->tipoPagamento;
}

Localizacao Cliente::GetLocalizacao()
{
	return *this->localizacao;
}

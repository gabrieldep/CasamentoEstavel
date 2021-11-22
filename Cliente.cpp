#include "Cliente.h"

Cliente::Cliente()
{
	this->idade = 0;
	this->identificacao = 0;
	this->localizacao = new Localizacao();
	this->uf = UF::NaoInformado;
	this->tipoPagamento = TipoPagamento::NaoInformado;
}

Cliente::~Cliente()
{
	delete this->localizacao;
}

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

#include "Cliente.h"

Cliente::Cliente()
{
	this->idade = 0;
	this->identificacao = 0;
	this->localizacao = new Localizacao();
	this->uf = UF::NaoInformado;
	this->tipoPagamento = TipoPagamento::NaoInformado;
	this->ticket = ((float)(60.0 - (float)this->idade) + static_cast<float>(this->uf)) / static_cast<float>(this->tipoPagamento);
	this->lojas = new vector<int>;
	this->lojaSelecionada = -1;
}

Cliente::Cliente(int identificacao, int idade, std::string uf, std::string tipoPagamento, int x, int y, vector<Loja*> lojas)
{
	this->identificacao = identificacao;
	this->idade = idade;
	this->uf = GetUfFromString(uf);
	this->tipoPagamento = GetTipoPagamentoFromString(tipoPagamento);
	this->localizacao = new Localizacao(x, y);
	this->ticket = ((float)(abs(60.0 - (float)this->idade)) + static_cast<float>(this->uf)) / static_cast<float>(this->tipoPagamento);
	this->lojas = new vector<int>;
	for (size_t i = 0; i < lojas.size(); i++)
	{
		this->lojas->push_back(lojas.at(i)->GetIdentificacao());
	}
	this->lojaSelecionada = -1;
}

Cliente::~Cliente()
{
	delete this->localizacao;
}

UF Cliente::GetUfFromString(std::string uf)
{
	if (uf == "MG") return UF::MG;
	else if (uf == "PR") return UF::PR;
	else if (uf == "SP") return UF::SP;
	else if (uf == "SC") return UF::SC;
	else if (uf == "RJ") return UF::RJ;
	else if (uf == "RN") return UF::RN;
	else if (uf == "RS") return UF::RS;
	else return UF::NaoInformado;
}

TipoPagamento Cliente::GetTipoPagamentoFromString(std::string tipoPagamento)
{
	if (tipoPagamento == "DINHEI") return TipoPagamento::Dinheiro;
	else if (tipoPagamento == "DEBITO") return TipoPagamento::Debito;
	else if (tipoPagamento == "CREDIT") return TipoPagamento::Credito;
	else return TipoPagamento::NaoInformado;
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

void Cliente::SetLojaSelecionada(int idLoja)
{
	this->lojaSelecionada = idLoja;
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

int Cliente::GetTicket()
{
	return this->ticket;
}

int Cliente::GetLojaSelecionada()
{
	return this->lojaSelecionada;
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

int Cliente::GetDistanciaLoja(Loja loja)
{
	return this->localizacao->CalcularDistancia(loja.GetLocalizacao());
}

bool Cliente::PrefereLojaNovaAAlocada(int idLoja)
{
	if (RetornaPosicaoLoja(idLoja) < RetornaPosicaoLoja(lojaSelecionada))
	{
		return true;
	}
	return false;
}

int Cliente::RetornaPosicaoLoja(int idLoja)
{
	int i = 0;
	while (true)
	{
		if (this->lojas->at(i) == idLoja)
			return i;
		i++;
	}
	return -1;
}
#pragma once
#include <string>
#include "Localizacao.h"

enum class UF { MG = 0, PR = 10, SP = 20, SC = 30, RJ = 40, RN = 50, RS = 60 };
enum class TipoPagamento { Dinheiro = 1, Debito = 2, Credito = 3 };

class Cliente
{
	private:
		int identificacao;
		int idade;
		Localizacao* localizacao;
		UF uf;
		TipoPagamento tipoPagamento;
	public:
		void SetIdentificacao(int identificacao);
		void SetIdade(int idade);
		void SetUf(UF uf);
		void SetTipoPagamentoFrequente(TipoPagamento tipoPagamento);
		void SetLocalizacao(Localizacao* localizacao);
		int GetIdentificacao();
		int GetIdade();
		UF GetUf();
		TipoPagamento GetTipoPagamentoFrequente();
		Localizacao GetLocalizacao();
};


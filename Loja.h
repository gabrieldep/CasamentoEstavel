#pragma once
#include "Localizacao.h"
class Loja
{
	private:
		int identificacao;
		int estoque;
		Localizacao* localizacao;
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
};


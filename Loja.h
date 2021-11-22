#pragma once
#include "Localizacao.h"
class Loja
{
	private:
		int identificacao;
		Localizacao* localizacao;
	public:
		void SetIdentificacao(int identificacao);
		void SetLocalizacao(Localizacao* localizacao);
		int GetIdentificacao();
		Localizacao GetLocalizacao();
};


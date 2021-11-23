#pragma once
#include "Localizacao.h"
#include "Cliente.h"

class Loja
{
	private:
		int identificacao;
		int estoque;
		Localizacao* localizacao;
		Cliente** clientes;
	public:
		Loja();
		Loja(int identificacao, int estoque, int x, int y);
		~Loja();
		void SetIdentificacao(int identificacao);
		void SetLocalizacao(Localizacao* localizacao);
		void SetEstoque(int estoque);
		void SetClientes(int qtdClientes);
		int GetIdentificacao();
		Localizacao GetLocalizacao();
		int GetEstoque();
		Cliente* GetClientes();
		void SomaEstoque(int i);
};


#pragma once
class Localizacao
{
	private:
		int x;
		int y;
	public:
		Localizacao();
		Localizacao(int x, int y);
		~Localizacao();
		void SetX(int x);
		void SetY(int y);
};


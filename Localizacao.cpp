#include "Localizacao.h"

Localizacao::Localizacao()
{
	this->x = 0;
	this->y = 0;
}

Localizacao::~Localizacao()
{
}

void Localizacao::SetX(int x)
{
	this->x = x;
}

void Localizacao::SetY(int y)
{
	this->y = y;
}

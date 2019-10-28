#include "Nut.h"

Nut::Nut() : x(10), y(5), symbol(NUT)
{

}
Nut::~Nut()
{

}

int Nut::get_x() const
{
	return x;
}

int Nut::get_y() const
{
	return y;
}

char Nut::get_symbol() const
{
	return symbol;
}

/*bool Nut::has_been_collected(const int x, const int y) const
{

}

bool Nut::is_at_position(const int x, const int y) const
{

}*/

void Nut::place_nut()
{

}
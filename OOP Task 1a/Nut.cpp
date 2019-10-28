#include "Nut.h"
#include "Constants.h"

Nut::Nut() : symbol(NUT)
{
	place_nut();
}
Nut::~Nut()
{

}

int Nut::get_x() const
{
	return this->x;
}

int Nut::get_y() const
{
	return this->x;
}

char Nut::get_symbol() const
{
	return this->symbol;
}

/*
bool Nut::has_been_collected(const int x, const int y) const
{

}

bool Nut::is_at_position(const int x, const int y) const
{

}
*/
void Nut::place_nut()
{
	x = 10;
	y = 5;
}
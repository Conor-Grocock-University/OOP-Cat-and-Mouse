#include "Nut.h"
#include "Constants.h"

Nut::Nut() : symbol(NUT)
{
	place_nut();

}

Nut::~Nut()
{

}

void Nut::set_collected(bool collected) {
	this->collected = collected;
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

bool Nut::is_at_position(const int x, const int y) const
{
	return (this->x == x) && (this->y == y);
}

bool Nut::has_been_collected() const
{
	return this->collected;
}

void Nut::place_nut()
{
	x = 17;
	y = 8;
}
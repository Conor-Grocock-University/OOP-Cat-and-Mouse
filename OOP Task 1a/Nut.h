#pragma once
#include "constants.h"

class Nut
{
	Nut();
	~Nut();
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
	bool has_been_collected(int x, int y) const;
	bool is_at_position(int x, int y) const;
	void place_nut();

private:
	const char symbol;
	int x, y;
};


#pragma once

#include <cassert>
#include <vector>
#include "constants.h"
#include "FixedGridItem.h"

using namespace std;

class Hole: public FixedGridItem
{
public:
    // constructors
    Hole();
    Hole(int x, int y);

		// assessors
		//int get_x() const;
		//int get_y() const;
		//char get_symbol() const;
		//bool is_at_position(int x, int y) const;

private:
    // data members
    //char symbol;
    //int x, y;
};

class Underground
{
public:
    Underground();
    Hole get_hole_no(int no) const;
    void set_hole_no_at_position(int no, int x, int y);
    Hole get_random_hole();
    bool is_valid_hole_number(int n) const;

    bool is_at_hole(int x, int y) const;

    vector<Hole> holes;
};
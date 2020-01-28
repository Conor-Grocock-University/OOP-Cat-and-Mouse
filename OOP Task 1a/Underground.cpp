#include "Underground.h"
#include "FixedGridItem.h"

Hole::Hole() : FixedGridItem(HOLE)
{
}

Hole::Hole(const int x, const int y): FixedGridItem(HOLE)
{
	
	this->x = x;
	this->y = y;
}
/*
int Hole::get_x() const
{
    return x;
}

int Hole::get_y() const
{
    return y;
}

char Hole::get_symbol() const
{
    return symbol;
}

bool Hole::is_at_position(const int x, const int y) const
{
    return this->x == x && this->y == y;
}
*/
// number of holes in underground
static const int MAXHOLES(3);

Underground::Underground() : holes(MAXHOLES)
{
}

Hole Underground::get_hole_no(const int no) const
{
    // pre-condition: valid hole number
    assert(is_valid_hole_number(no));

    return holes.at(no);
}

void Underground::set_hole_no_at_position(const int no, const int x, const int y)
{
    // pre-condition: valid hole number
    assert(is_valid_hole_number(no));

    const Hole h(x, y);

    holes.at(no) = h;
}

Hole Underground::get_random_hole()
{
    const int rand = ::rand() % (MAXHOLES - 1);
    return holes.at(rand);
}

bool Underground::is_valid_hole_number(int hole_no) const
{
    return hole_no >= 0 && hole_no < (int)holes.size();
}

bool Underground::is_at_hole(const int x, const int y) const
{
    for (int h_no = 0; h_no < (int)holes.size(); ++h_no)
    {
        Hole hole = get_hole_no(h_no);

        if (hole.is_at_position(x, y))
        {
            return true;
        }
    }
    return false;
}

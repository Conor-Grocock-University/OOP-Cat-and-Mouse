#include "MoveableGridItem.h"
#include "Constants.h"

int MoveableGridItem::get_y() const
{
    return y;
}

MoveableGridItem::MoveableGridItem(char symbol) : GridItem(symbol)
{
}

int MoveableGridItem::get_x() const
{
    return x;
}

bool MoveableGridItem::is_at_position(int x, int y) const
{
    if(get_x() == x && get_y() == y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MoveableGridItem::reset_position(int& x, int& y)
{
    x = SIZE / 2;
    y = SIZE / 2;
}

void MoveableGridItem::update_position(int dx, int dy) 
{
    x += dx;
    y += dy;
}

#include "FixedGridItem.h"


int FixedGridItem::get_y() const
{
    return y;
}

int FixedGridItem::get_x() const
{
    return x;
}

FixedGridItem::FixedGridItem(char symbol) : GridItem(symbol)
{
}

bool FixedGridItem::is_at_position(int x, int y) const
{
    if (get_x() == x && get_y() == y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#include "FixedGridItem.h"


int FixedGridItem::get_y() 
{
    return y;
}

int FixedGridItem::get_x()
{
    return x;
}

bool FixedGridItem::is_at_position(int x, int y)
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

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
    return get_x() == x && get_y() == y;
}

void MoveableGridItem::reset_position(int& x, int& y) const
{
    x = SIZE / 2;
    y = SIZE / 2;
}

void MoveableGridItem::update_position(int dx, int dy) 
{
    set_position(x + dx, y + dy);
}

void MoveableGridItem::set_position(int x, int y)
{
    this->x = x;
    this->y = y;
}



#pragma once
#include "GridItem.h"
class MoveableGridItem : public GridItem
{
public:
    MoveableGridItem(char symbol);
    int get_x() const;
    int get_y() const;
    bool is_at_position(int x, int y) const;
    void reset_position(int& x, int& y) const;
    void update_position(int dx, int dy);
    void set_position(int x, int y);

protected:
    int x;
    int y;
};


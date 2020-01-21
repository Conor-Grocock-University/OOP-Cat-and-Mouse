#pragma once
#include"GridItem.h"
class FixedGridItem : public GridItem
{
public:
    FixedGridItem(char symbol);
    int get_x() const;
    int get_y() const;
    bool is_at_position(int x, int y) const;

protected:
   int x;
   int y;
};



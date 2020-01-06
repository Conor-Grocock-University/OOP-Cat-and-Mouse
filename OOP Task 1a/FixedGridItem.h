#pragma once
#include"GridItem.h"
class FixedGridItem : GridItem
{
public:
    int get_x();
    int get_y();
    bool is_at_position(int x, int y);

private:
    const int x;
    const int y;
};



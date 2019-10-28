#include "Score.h"
#include <iostream>

int Score::get_amount() const
{
    return amount;
}

void Score::update_amount(const int amount)
{
    this->amount += amount;
    std::cout << "Score: " << amount << std::endl;
}

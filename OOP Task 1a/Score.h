#pragma once
class Score
{
public:
    int get_amount() const;
    void update_amount(int amount);

private:
    int amount = 0;
};


#pragma once
#include <string>
#include "Score.h"

class Player
{
public:
    Player(std::string playerName);

    std::string get_name() const;
    int get_score() const;


    void update_score(int amount);

private:
    std::string name;

    Score score;
};


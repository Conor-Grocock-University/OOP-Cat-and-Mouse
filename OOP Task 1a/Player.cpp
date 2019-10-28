#include "Player.h"

Player::Player(std::string playerName): name(playerName) {}

std::string Player::get_name() const
{
    return name;
}

int Player::get_score() const
{
    return score.get_amount();   
}
void Player::update_score(const int amount)
{
    return score.update_amount(amount);
}

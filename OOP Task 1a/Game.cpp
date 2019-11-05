#include "Game.h"
#include "Player.h"
#include <iostream>

void Game::set_up()
{
    // set up the holes
    underground.set_hole_no_at_position(0, 4, 3);
    underground.set_hole_no_at_position(1, 15, 10);
    underground.set_hole_no_at_position(2, 7, 15);

    // mouse state already set up in its contructor

    // set up snake
    snake.position_at_random();
    snake.spot_mouse(&mouse);
    nut.place_nut();
}

void Game::process_input(const int key)
{
    mouse.scamper(key);
    snake.chase_mouse();
    apply_rules();
}

bool valid_tail(vector<Tail> tails, int x, int y) {
    for (int i = 0; i < tails.size(); i++)
    {
        Tail t = tails[i];
        if (t.x == x && t.y == y) {
            return true;
        }
    }
    return false;
}

vector<vector<char>> Game::prepare_grid() const
{
    // create the 2D grid
    vector<vector<char>> grid;

    // for each row
    for (int row = 1; row <= SIZE; ++row)
    {
        // create a row to add to the 2D grid
        vector<char> line;

        // for each column
        for (int col = 1; col <= SIZE; ++col)
        {
            if (row == snake.get_y() && col == snake.get_x())
                // is the snake at this position?
                line.push_back(snake.get_symbol());
            else if (row == mouse.get_y() && col == mouse.get_x())
                // is the mouse at this position?
                line.push_back(mouse.get_symbol());
            else if (!snake.get_tail().empty() && valid_tail(snake.get_tail(), col, row))
                // Is the snakes tail empty, is not is the current position a part of the tail
                line.push_back(TAIL);
            else if (row == nut.get_y() && col == nut.get_x() && !nut.has_been_collected())
                // Is the Nut at this position and has it been eaten
                line.push_back(nut.get_symbol());
            else
            {
                // is there a hole at this position?
                const int hole_no = find_hole_number_at_position(col, row);

                if (hole_no != -1)
                {
                    line.push_back(underground.get_hole_no(hole_no).get_symbol());
                }
                else
                {
                    // none of the above, must be nothing at this position
                    line.push_back(FREECELL);
                }
            }
            // Check the line is the correct length
            assert(line.size() == col);
        }
        grid.push_back(line);

        // Check the grid is the correct size
        assert(grid.size() == row);
    }
    return grid;
}

int Game::find_hole_number_at_position(const int x, const int y) const
{
    for (int h_no = 0; h_no < underground.holes.size(); ++h_no)
    {
        if (underground.get_hole_no(h_no).is_at_position(x, y))
        {
            return h_no;
        }
    }

    return -1; // not a hole
}

void Game::apply_rules()
{
    if (snake.has_caught_mouse())
    {
        mouse.die();
        player->update_score(-1);
    }
    else if (mouse.has_eaten_nut(&nut))
    {
        nut.set_collected(true);
        nut.~Nut();
    }
    if (mouse.has_reached_a_hole(underground))
    {
        if (nut.has_been_collected() == true)
        {
            mouse.escape_into_hole(); // only go into hole if nut has been collected

            player->update_score(1);
        }
    }
}

bool Game::is_running() const
{
    return mouse.is_alive() && !mouse.has_escaped();
}

string Game::get_end_reason() const
{
    if (mouse.has_escaped())
        return "You escaped underground!";

    return "The snake ate you!";
}


Game::Game(Player *newPlayer)
{
    player = newPlayer;
}

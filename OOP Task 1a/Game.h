#pragma once

#include <string>		
#include <assert.h>	
#include <vector>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "Nut.h"
#include "Player.h"

using namespace std;

class Game
{

public:
	  Nut nut;
    Mouse mouse;
    Snake snake;
    Player* player = nullptr;
    Underground underground;

public:
      void set_up();
      void process_input(int key);
      vector<vector<char>> prepare_grid() const;
      void apply_rules();
      bool is_running() const;
      int find_hole_number_at_position(int x, int y) const;
      string get_end_reason() const;

public:
    Game();
    Game(Player *player);
};
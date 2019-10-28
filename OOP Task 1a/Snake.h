#pragma once

#include "Mouse.h"
#include "Tail.h"
#include "RandomNumberGenerator.h"

class Snake {
	public:
		Snake();

		bool is_at_position(int x, int y) const;  
		bool has_caught_mouse() const;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy) const;
		void position_at_random();
		void update_position(int dx, int dy);
        void move_tail();
        
        int get_x() const;
        int get_y() const;
        vector<Tail> get_tail() const;
        char get_symbol() const;
		
    private:
        const char symbol;
        int x, y;
        Mouse* p_mouse;
        vector<Tail> tail;
};
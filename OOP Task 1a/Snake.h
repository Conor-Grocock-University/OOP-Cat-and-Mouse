#pragma once

#include "Mouse.h"
#include "Tail.h"
#include "RandomNumberGenerator.h"
#include "MoveableGridItem.h"

class Snake : public MoveableGridItem {
	public:
		Snake();

		bool has_caught_mouse() const;
		void spot_mouse(Mouse* p_mouse);
        bool valid_tail(vector<Tail> tails, int& x, int& y) const;
		void chase_mouse();
		void set_direction(int& dx, int& dy) const;
		void position_at_random();

        void move_tail();
        
        vector<Tail> get_tail() const;
		
    private:
        Mouse* p_mouse;
        vector<Tail> tail;
};
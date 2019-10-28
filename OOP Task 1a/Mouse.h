#pragma once

#include "constants.h"
#include "Underground.h"
#include "Nut.h"

class Mouse
{
	public:
		// constructor
		Mouse();

		// accessors
		int get_x() const;
		int get_y() const;
		char get_symbol() const;

		bool is_at_position(int x, int y) const;
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(const Underground ug) const;
		bool has_eaten_nut(Nut* nut);

		// mutators
		void die();
		void escape_into_hole();
		void scamper(int key);


	private:
		const char symbol;
		int  x, y;
		Nut* nut;

		// data members
		bool alive;
		bool escaped;
		int mouse_dx;
		int mouse_dy;

		// supporting functions 
		void position_in_middle_of_grid();
		void update_position(int dx, int dy);
};
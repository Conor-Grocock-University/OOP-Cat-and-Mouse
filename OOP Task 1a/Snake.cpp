#include "Snake.h"
#include "Constants.h"
#include "Mouse.h"
#include "Tail.h"
#include "RandomNumberGenerator.h"

Snake::Snake() : MoveableGridItem(SNAKEHEAD)
{
	position_at_random();
    
	// make the pointer safe before the snake spots the mouse 
	p_mouse = nullptr;
}

bool Snake::has_caught_mouse() const
{
	return is_at_position(p_mouse->get_x(), p_mouse->get_y());

}

void Snake::spot_mouse(Mouse* p_mouse)
{
	// pre-condition: the mouse needs to exist 
	assert(p_mouse != nullptr);

	this->p_mouse = p_mouse;
}

void Snake::chase_mouse()
{
	int snake_dx, snake_dy;

	//identify direction of travel
	set_direction(snake_dx, snake_dy);

	//go in that direction
	update_position(snake_dx, snake_dy);
    move_tail();
}

void Snake::set_direction(int& dx, int& dy) const
{
	// pre-condition: The snake needs to know where the mouse is 
	assert(p_mouse != nullptr);

	// assume snake only moves when necessary
	dx = 0; dy = 0;

	// update coordinate if necessary
	if (get_x() < p_mouse->get_x())         // if snake on left of mouse
		dx = 1;                        // snake should move right
	else if (get_x() > p_mouse->get_x())    // if snake on left of mouse
		dx = -1;						       // snake should move left

	if (get_y() < p_mouse->get_y())         // if snake is above mouse
		dy = 1;                        // snake should move down
	else if (get_y() > p_mouse->get_y())    // if snake is below mouse
		dy = -1;						       // snake should move up
}


void Snake::move_tail()
{
    while (tail.size() > 2)
    {
        tail.erase(tail.begin());
    }
    Tail tailSegment(get_x(), get_y());
    tail.push_back(tailSegment);
}


vector<Tail> Snake::get_tail() const
{
    return this->tail;
}


void Snake::position_at_random()
{
	// WARNING: this may place on top of other things
    x = RandomNumberGenerator::get_random_value(SIZE);
    y = RandomNumberGenerator::get_random_value(SIZE);
}


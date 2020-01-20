#include "Mouse.h"
#include "Nut.h"

Mouse::Mouse() : MoveableGridItem(MOUSE), alive(true), escaped(false), mouse_dx(0), mouse_dy(0)
{
    reset_position(x,y);
}

//int Mouse::get_x() const
//{
//   return x;
//}
//
//int Mouse::get_y() const
//{
//   return y;
//}
//
//char Mouse::get_symbol() const
//{
//   return symbol;
//}
//
//bool Mouse::is_at_position(const int x, const int y) const
//{
//   return this->x == x && this->y == y;
//}

bool Mouse::has_eaten_nut(Nut* nut)
{
	bool has_eaten_nut = is_at_position(nut->get_x(), nut->get_y()); // if the mouse location is same as nut;
	return has_eaten_nut;
}

bool Mouse::is_alive() const
{
   return alive;
}

bool Mouse::has_escaped() const
{
   return escaped;
}

bool Mouse::has_reached_a_hole(const Underground& underground) const
{
   return underground.is_at_hole(x, y);
}

void Mouse::die()
{
   alive = false;
}

void Mouse::escape_into_hole()
{
   escaped = true;
}

void Mouse::scamper(const int key)
{
   switch (key)
   {
      case KEY_LEFT:
         this->update_position(-1,0);
         break;
      case KEY_RIGHT:
          this->update_position(+1, 0);
         break;
      case KEY_UP:
          this->update_position(0, -1);
         break;
      case KEY_DOWN:
          this->update_position(0, +1);
         break;
      default:
         // not a key we care about, so do nothing
         break;
   }

   // update mouse coordinates if move is possible
   if (((x + mouse_dx) >= 1) && ((x + mouse_dx) <= SIZE) && ((y + mouse_dy) >= 1) && ((y + mouse_dy) <= SIZE))
   {
      update_position(mouse_dx, mouse_dy);
   }
}

//void Mouse::update_position(const int dx, const int dy)
//{
//   x += dx;
//   y += dy;
//}

//void Mouse::position_in_middle_of_grid()
//{
//   x = SIZE / 2;
//   y = SIZE / 2;
//}
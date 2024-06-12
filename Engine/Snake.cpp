#include "Snake.h"

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for(int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i-1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
}

void Snake::Draw(Board& brd) const
{
}

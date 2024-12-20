#include "Snake.h"
#include <assert.h>

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
	//Increase the number of segments being used
	if(nSegments < nSegmentsMax)
	{
		nSegments++;
	}
}

void Snake::Draw(Board& brd) const
{
	for(int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor; //Segment is inside Snake, so it can access Snake's Private Members
}

void Snake::Segment::InitBody()
{
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.x) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}
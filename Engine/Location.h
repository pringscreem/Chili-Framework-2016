#pragma once

struct Location
{
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
		int x; //Not using encapsulation
		int y; //These represent the square locations (number of squares up/down/left/right)
};
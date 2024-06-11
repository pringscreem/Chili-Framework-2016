#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx) //Note that there are two different variables named "gfx" here (function parameter and class variable)
{
}

void Board::DrawCell(Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < gfx.ScreenWidth);
	assert(loc.y >= 0);
	assert(loc.y < gfx.ScreenHeight);
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, c);
}

int Board::GetGridHeight()
{
	return gfx.ScreenHeight / dimension;
}

int Board::GetGridWidth()
{
	return gfx.ScreenWidth / dimension;
}

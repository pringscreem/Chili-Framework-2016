#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx) //Note that there are two different variables named "gfx" here (function parameter and class variable)
{
}

void Board::DrawCell(Location& loc, Color c)
{
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension);
}

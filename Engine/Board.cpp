#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx) //Note that there are two different variables named "gfx" here (function parameter and class variable)
{
	LifeInitLifeBoard(LifeBoard);
}

void Board::DrawCell(const Location& loc, Color c)
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

void Board::LifeInitLifeBoard(std::vector<std::vector<int>>& LifeBoard)
{
	int x = GetGridWidth();
	int y = GetGridHeight();
	LifeBoard.resize(x);
	for(int i = 0; i < x; i++)
	{
		LifeBoard[i].resize(y);
	}
	 
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
		{
			LifeBoard[i][j] = 0;
		}
}

void Board::LifeFlipPosition(const Location& position)
{
	int x = position.x;
	int y = position.y;
	if(LifeBoard[x][y] == 0)
	{
		LifeBoard[x][y] = 1;
	}
	else
	{
		LifeBoard[x][y] = 0;
	}
}

void Board::LifeDrawBoard() //Is there any point in passing the reference?
{
	int x = GetGridWidth();
	int y = GetGridHeight();
	Location drawPos = { 0, 0 };
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
		{
			if(LifeBoard[i][j] == 1)
			{
				drawPos.x = i;
				drawPos.y = j;
				DrawCell(drawPos, Colors::Green); //Maybe the {i, j} will work as a struct
			}
		}
}

void Board::LifeDrawColorBoard(Color c)
{
	int x = GetGridWidth();
	int y = GetGridHeight();
	Location drawPos = { 0, 0 };
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
		{
			//if(LifeBoard[i][j] == 1)
			//{
				drawPos.x = i;
				drawPos.y = j;
				DrawCell(drawPos, c); //Maybe the {i, j} will work as a struct
			//}
		}
}

//Returns the value stored at the LifeBoard position
int Board::GetLifeBoardPositionValue(const Location& loc)
{
	return LifeBoard[loc.x][loc.y];
}

void Board::SetLifeBoardPositionValue(const Location& loc, int inputInt)
{
	LifeBoard[loc.x][loc.y] = inputInt;
}

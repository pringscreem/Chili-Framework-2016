#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
	public:
		Board(Graphics& gfx);
		void DrawCell(Location& loc, Color c);
		int squareWidth = gfx.ScreenWidth / dimension;
		int squareHeight = gfx.ScreenHeight/ dimension;
		int GetGridHeight();
		int GetGridWidth();
	private:
		static constexpr int dimension = 20; //These are the pixel dimensions of the squares
		static constexpr int width = 10;
		static constexpr int height = 10;
		Graphics& gfx; //We can store a reference to something so that we don't have to put it in the function parameters every time.
};
#pragma once

#include "Board.h"



class Snake
{
	public:
		//
	private:
		//Declaring the segment class inside because it is tightly coupled to the snake
		class Segment
		{
			private:
				Location loc;
				Color c;
		};

	private:
		Segment segments[];
};


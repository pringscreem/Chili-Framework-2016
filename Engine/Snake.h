#pragma once

#include "Board.h"



class Snake
{
	private:
		//Declaring the segment class inside because it is tightly coupled to the snake
		class Segment
		{
			public:
				void InitHead(const Location& loc);
				void InitBody();
				void Follow(const Segment& next);
				void MoveBy(const Location& delta_loc);
				void Draw(Board& brd) const;
			private:
				Location loc;
				Color c;
		};
	public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;

	private:
		static constexpr int nSegmentsMax = 100;
		Segment segments[nSegmentsMax];
		int nSegments = 1;
};


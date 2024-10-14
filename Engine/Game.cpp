/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Location.h"
#include <string>
#include <chrono>
#include <thread>


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd(gfx),
	rng(std::random_device()())
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
	//std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	//std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	//std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

}

void Game::UpdateModel()
{
	//Snake
	//CheckKeys(wnd.kbd);

	//Check for Goal collision - make a Goal class (copy from Poo Game)
	//						   - call snake.Grow() (position the new Segment properly)
	//Check for tail collision
	//Check for wall collision
	//Update Snake position

	LifeUpdateModel();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Game::ComposeFrame()
{
	//Draw the Snake
	//Draw the Goal

	LifeComposeFrame();
}

void Game::MyTestBoard() //This renders each square with a slightly different colour in a gradient
{
	int red = 0;
	int green = 0;
	int blue = 0;
	Color colour(red, green, blue);
	Location loc = { 0, 0 };
	for (int i = 0; i < brd.squareWidth; i++) //He made some functions for calculating grid width/height (probably more flexible e.g. resolution change during play)
	{
		for (int j = 0; j < brd.squareHeight; j++)
		{
			brd.DrawCell(loc, colour);
			loc.y = j;
			red += 26;
			green += 26;
			blue += 26;
			colour = (red, green, blue);
		}
		loc.x = i;
		red += 26;
		green += 26;
		blue += 26;
		colour = (red, green, blue);
	}
}

void Game::HisTestBoard() //This renders each square with a random colour
{
	std::uniform_int_distribution<int> colorDist(0, 255);
	for(int y = 0; y < brd.GetGridHeight(); y++)
	{
		for(int x = 0; x < brd.GetGridWidth(); x++)
		{
			Location loc = { x, y };
			Color c(colorDist(rng), colorDist(rng), colorDist(rng));
			brd.DrawCell(loc, c);
		}
	}
}

void Game::CheckKeys(const Keyboard& kbd)
{
	if(kbd.KeyIsPressed(VK_RIGHT))
	{
		delta_loc.x = 1;
		delta_loc.y = 0;
		//delta_loc.Add({ 1, 0 }); //Prediction
	}
	if(kbd.KeyIsPressed(VK_LEFT))
	{
		delta_loc.x = -1;
		delta_loc.y = 0;
	}
	if(kbd.KeyIsPressed(VK_DOWN))
	{
		delta_loc.x = 0;
		delta_loc.y = 1;
	}
	if(kbd.KeyIsPressed(VK_UP))
	{
		delta_loc.x = 0;
		delta_loc.y = -1;
	}
}

void Game::LifeComposeFrame()
{
	//LifeFrameRateFlash();
	brd.LifeDrawBoard();
	LifeDrawPosition(position);
	
}

void Game::LifeUpdateModel()
{
	//LifeRandomizeBoard();
	LifeCheckKeys(wnd.kbd);
	if(!gameIsPaused)
	{
		LifeCheckCells();
	}
	//LifeTestFrameTime();
}

void Game::LifeCheckKeys(const Keyboard& kbd)
{
	//Add a modulo frame counter check here to slow it down.
	if(kbd.KeyIsPressed(VK_PAUSE))
	{
		if(gameIsPaused)
		{
			gameIsPaused = false;
		}
		else
		{
			gameIsPaused = true;
		}
	}
	if(kbd.KeyIsPressed(VK_RIGHT))
	{
		position.Add({1, 0});
	}
	if(kbd.KeyIsPressed(VK_LEFT))
	{
		position.Add({-1, 0});
	}
	if(kbd.KeyIsPressed(VK_DOWN))
	{
		position.Add({0, 1});
	}
	if(kbd.KeyIsPressed(VK_UP))
	{
		position.Add({0, -1});
	}
	LifeClampPosition();
	if(kbd.KeyIsPressed(VK_SPACE))
	{
		if(spacebarTimerCounter % spacebarDelayFrames == 0)
		{
			//brd.LifeDrawColorBoard(Colors::Magenta);
			brd.LifeFlipPosition(position);
		}
		spacebarTimerCounter++;
	}
	else
	{
		spacebarTimerCounter = 0;
	}
}

void Game::LifeDrawPosition(const Location& position)
{
	brd.DrawCell(position, Colors::Cyan);
}

void Game::LifeClampPosition()
{
	if(position.x < 0)
	{
		position.x = 0;
	}
	if(position.x > brd.GetGridWidth() - 1)
	{
		position.x = brd.GetGridWidth() - 1;
	}
	if(position.y < 0)
	{
		position.y = 0;
	}
	if(position.y > brd.GetGridHeight() - 1)
	{
		position.y = brd.GetGridHeight() - 1;
	}
}

void Game::LifeCheckCells()
{
	int x = brd.GetGridWidth();
	int y = brd.GetGridHeight();
	Location loc = {0, 0};
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
		{
			loc.x = i;
			loc.y = j;
			if(LifeCellShouldLive(loc)) //Currently returns true all the time
			{
				brd.SetLifeBoardPositionValue(loc, 1);
			}
			else
			{
				brd.SetLifeBoardPositionValue(loc, 0);
			}
		}
}

bool Game::LifeCellShouldLive(const Location& loc) //This function is kind of long.
{
	const int x = loc.x; //It's not very efficient to declare a bunch of variables every frame like this.
	const int y = loc.y;
	const int right = brd.GetGridWidth() - 1;
	const int left = 0;
	const int top = 0;
	const int bottom = brd.GetGridHeight() - 1;
	int neighboursCount = 0;
	Location testLoc = {0, 0};

	//Test the location of the cell and apply the middle or one of the edge tests
	//Middle
	if(	   (x > left) 
		&& (x < right) 
		&& (y > top) 
		&& (y < bottom)	) //The closing parenthesis seems awkward.
	{
		//Middle
		//This is the wrong loop.
		//This loop should happen in the "LifeCheckCells" function, not here.
		//What should happen here is a neighbour test for all eight neighbours of a cell that 
		//is somewhere in the middle.
		int testX = x - 1;//Probably don't need these two.
		int testY = y - 1;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
			{
				if((i == 1) && (j == 1))
				{
					continue;
				}
				else
				{
					testLoc = { testX + i, testY + j }; //This should add the value of the offset to the test location's point.
					LifeTestNeighbour(testLoc, neighboursCount);
				}
			}
	}
	//Left Side
	else if(x == left)
	{
		if(y == top)
		{
			//Top Left Corner
			testLoc.x = left; //testLoc = {left, top + 1}; //The space below the current cell
			testLoc.y = top + 1;
			LifeTestNeighbour(testLoc, neighboursCount); //A function is better, but not great
			testLoc.x = left + 1;//The space to the right of the current cell
			testLoc.y = top;
			LifeTestNeighbour(testLoc, neighboursCount);
			testLoc.x = left + 1;//The space diagonal from the current cell
			testLoc.y = top + 1;
			LifeTestNeighbour(testLoc, neighboursCount);
		}
		else if(y == bottom)
		{
			//Bottom Left Corner
			testLoc.x = left + 1;
			testLoc.y = bottom;
			LifeTestNeighbour(testLoc, neighboursCount);
			testLoc.x = left;
			testLoc.y = bottom + 1;
			LifeTestNeighbour(testLoc, neighboursCount);
			testLoc.x = left + 1;
			testLoc.y = bottom + 1;
			LifeTestNeighbour(testLoc, neighboursCount);
		}
		else
		{
			//Left Edge
			// testLoc.x = left;
			// testLoc.y = y - 1;
			// LifeTestNeighbour(testLoc, neighboursCount);
			// //Loop through six positions instead of hardcoding it.

			//It is going out of bounds in this loop.
			for(int i = 0; i < 2; i++)
				for(int j = -1; j < 2; j++)
				{
					testLoc.x = x + i;
					testLoc.y = y + j;
					if(testLoc.x != x && testLoc.y != y) 
					{ //Only do the test if it's not the position of the cell in question.
						LifeTestNeighbour(testLoc, neighboursCount);
					}
				}


			// for(int i = 1; i < bottom; i++) //The corners ("0") are already being tested.
			// {
			// 	testLoc.y = i;
			// 	LifeTestNeighbour(testLoc, neighboursCount);//This just goes through all the
			// 												//cells on the edge and counts the
			// 												//living ones.
			// 												//The algorithm we want is more 
			// 												//different.
			// 												//Remember that we are only testing 
			// 												//a single cell.
			// 												//So, it should just test all the neighbours 
			// 												//of the selected cell.
			// 												//The loop through each cell happens 
			// 												//in the "parent" (calling) function. 
			// 												//This function is just conducting the 
			// 												//test on a single cell.
			// }
		}
	}
	//Right Side
	else if(x == right)
	{
		if(y == top)
		{
			//Top Right Corner
			testLoc.x = right;
			testLoc.y = top + 1;
			LifeTestNeighbour(testLoc, neighboursCount);
			testLoc.x = right - 1;
			testLoc.y = top;
			LifeTestNeighbour(testLoc, neighboursCount);
			testLoc.x = right - 1;
			testLoc.y = top + 1;
			LifeTestNeighbour(testLoc, neighboursCount);
		}
		else if(y == bottom)
		{
			//Bottom Right Corner
			testLoc.x = right;
			testLoc.y = bottom - 1;
			LifeTestNeighbour(testLoc, neighboursCount);
			testLoc.x = right - 1;
			testLoc.y = bottom;
			LifeTestNeighbour(testLoc, neighboursCount);
			testLoc.x = right - 1;
			testLoc.y = bottom - 1;
			LifeTestNeighbour(testLoc, neighboursCount);
		}
		else
		{
			//Right Edge
			testLoc.x = right;
			for(int i = 1; i < bottom; i++)//The corners ("0") are already being tested.
			{
				testLoc.y = i;
				LifeTestNeighbour(testLoc, neighboursCount);
			}
		}
	}

	//Top Side
	else if((y == top) 
		 && (x > left) 
		 && (x < right))
	{
		//Top Middle
		testLoc.y = top;
		for(int i = 1; i < right; i++)//The corners ("0") are already being tested.
		{
			testLoc.x = i;
			LifeTestNeighbour(testLoc, neighboursCount);
		}
	}
	//Bottom Side
	else if((y == bottom)
		&& (x > left)
		&& (x < right))
	{
		//Bottom Middle
		testLoc.y = bottom;
		for(int i = 1; i < right; i++)//The corners ("0") are already being tested.
		{
			testLoc.x = i;
			LifeTestNeighbour(testLoc, neighboursCount);
		}
	}
	return (neighboursCount > 1) && (neighboursCount < 4); //If it satisfies the survival rules, return true.
}

//More like "LifeHasNeighbour"...  This increments the neighbour count.
//This is a weird function that should probably be rewritten (return a bool, no change to neighboursCount)
void Game::LifeTestNeighbour(const Location& testLoc, int& neighboursCount)
{
	if(brd.GetLifeBoardPositionValue(testLoc) != 0)
	{
		neighboursCount++;
	}
}

void Game::LifeRandomizeBoard()
{
	if(!isRandomizedBoard)
	{
		isRandomizedBoard = true;
		int x = brd.GetGridWidth();
		int y = brd.GetGridHeight();
		Location loc;

		//Random Number Generating Variables
		std::random_device rd;
		std::mt19937 rng(rd());
		const int min = 0;
		const int max = 1;
		std::uniform_int_distribution<int> aliveRandom(min, max); //0, 1
		int randomInt = 0;

		for(int i = 0; i < x; i++)
			for(int j = 0; j < y; j++)
			{
				loc.x = i;
				loc.y = j;
				randomInt = aliveRandom(rng);
				brd.SetLifeBoardPositionValue(loc, randomInt);
			}
	}
}

void Game::LifeTestFrameTime()
{
	if(!startFlag)
	{
		LineInOutputTxt();
		//start = std::chrono::high_resolution_clock::now();
		OutputFrameAverage();
		startFlag = true;
	}
	else
	{
		if(!endFlag)
		{
			endFlag = true;
			//end = std::chrono::high_resolution_clock::now();
			//duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			//int myBool = true;
		}
	}

	if(frameCounter % 2 == 0)
	{
		frameCounter++;
		start2 = std::chrono::high_resolution_clock::now();
	}
	else
	{
		frameCounter++;
		end2 = std::chrono::high_resolution_clock::now();
		duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);
		RequestOutputTxt(static_cast<float>(duration2.count()));
	}
}

void Game::LifeFrameRateFlash()
{
	//This flashes blue and black on alternating frames.
	if(flip % 60 == 0)
	{
		brd.LifeDrawColorBoard(Colors::Blue);
		flip++;
	}
	else
	{
		brd.LifeDrawColorBoard(Colors::Black);
		flip++;
	}
}

void Game::RequestOutputTxt(/*std::string requestedOutput1,*/ float requestedOutputNum/*, std::string requestedOutput2*/)
{
	//The output file is in :
	//C:\msys64\home\ssonn\GitHub2023\Chili-Framework-2016\Debug
	std::ofstream MyOutputFile;
	MyOutputFile.open("MyOutput.txt", std::ios_base::app);

	static int outputFrameCounter = 0; //"static" keeps the variable alive between function calls (value continues counting up instead of recreating the variable each time)
	//MyOutputFile << "The value of requested output string is " << requestedOutputN1 << '\n';
	MyOutputFile << "Frame[ "<< outputFrameCounter << "]: " << requestedOutputNum << "ns = " 
				 << requestedOutputNum / 1000000 << "ms\n";
	//MyOutputFile << "The value of requested output 2 is " << requestedOutput2 << '\n';
	outputFrameCounter++;

	MyOutputFile.close();
}

void Game::LineInOutputTxt()
{
	//C:\msys64\home\ssonn\GitHub2023\Chili-Framework-2016\Debug
	std::ofstream MyOutputFile;
	MyOutputFile.open("MyOutput.txt", std::ios_base::app);
	MyOutputFile << "**************************************************************************************"
		<< "\n**************************************************************************************\n"; //172x *'s
	MyOutputFile.close();
}

void Game::OutputTxtToFile(std::string requestedOutputStr, float requestedOutputNum)
{
	//C:\msys64\home\ssonn\GitHub2023\Chili-Framework-2016\Debug
	std::ofstream MyOutputFile;
	MyOutputFile.open("MyOutput2.txt", std::ios_base::app);
	MyOutputFile << requestedOutputStr;
	MyOutputFile << requestedOutputNum;
	MyOutputFile.close();

}

void Game::OutputFrameAverage()
{
	float sum = 0;
	float average = 0;
	std::string frameTimeInMS = "0";
	//std::ofstream MyOutputFile;
	std::ofstream MyOutputFile2;
	//MyOutputFile.open("MyOutput.txt", std::ios_base::app);
	MyOutputFile2.open("MyOutput2.txt", std::ios_base::app);

	float myArray[] = {
					43.3975,
					22.9742,
					24.1581,
					22.4492,
					21.9283,
					22.3337,
					21.3142,
					22.5225,
					21.0439,
					21.1852,
					21.4104,
					21.3299,
					21.8046,
					21.4588,
					20.8562,
					21.8234,
					20.7501,
					20.3282,
					24.3657,
					21.3778,
					21.1660,
					21.3496,
					21.2805,
					21.2039,
					20.4719,
					20.1261,
					21.4728,
					20.2878,
					24.0992,
					20.5033,
					20.3523,
					20.0926,
					20.1309,
					20.0015,
					20.1610,
					20.2437,
					20.3311,
					20.1583 
					};

	for(int i = 1; i < sizeof(myArray) / sizeof(myArray[0]); i++)
	{
		sum += myArray[i];
	}
	average = sum / ( ( sizeof(myArray) / sizeof(myArray[0]) ) - 1);

	MyOutputFile2 << "Sum: " << sum << std::endl;
	MyOutputFile2 << "Average: " << average << std::endl;
	MyOutputFile2 << "sizeof(myArray) / sizeof(myArray[0]): " 
				  << sizeof(myArray) / sizeof(myArray[0]) << std::endl;
	MyOutputFile2.close();
	//MyOutputFile.close();
}
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
	brd.LifeDrawBoard();
	LifeDrawPosition(position);
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

void Game::LifeUpdateModel()
{
	LifeCheckKeys(wnd.kbd);
	LifeTestFrameTime();
}

void Game::LifeCheckKeys(const Keyboard& kbd)
{
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
			brd.LifeDrawColorBoard(Colors::Magenta);
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

void Game::LifeTestFrameTime()
{
	if(!startFlag)
	{
		LineInOutputTxt();
		start = std::chrono::high_resolution_clock::now();
		startFlag = true;
	}
	else
	{
		if(!endFlag)
		{
			endFlag = true;
			end = std::chrono::high_resolution_clock::now();
			duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			int myBool = true;
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

void Game::RequestOutputTxt(/*std::string requestedOutput1,*/ float requestedOutputNum/*, std::string requestedOutput2*/)
{
	//The output file is in :
	//C:\msys64\home\ssonn\GitHub2023\Chili-Framework-2016\Debug
	std::ofstream MyOutputFile;
	MyOutputFile.open("MyOutput.txt", std::ios_base::app);

	static int outputFrameCounter = 0;
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

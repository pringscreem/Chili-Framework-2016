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
}

void Game::UpdateModel()
{
	CheckKeys(wnd.kbd);
	//Check for Goal collision - make a Goal class (copy from Poo Game)
	//						   - call snake.Grow() (position the new Segment properly)
	//Check for tail collision
	//Check for wall collision
	//Update Snake position
}

void Game::ComposeFrame()
{
	//Draw the Snake
	//Draw the Goal
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

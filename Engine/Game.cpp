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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
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
}

void Game::ComposeFrame()
{
	gfx.PutPixel(700, 500, 0, 0, 255); //ctrl + shift + space to pull up Intellisense function info
	for(int i = 0; i < gfx.ScreenWidth; i++) //800
		for(int j = 0; j < gfx.ScreenHeight; j++) //600
		{ 
			gfx.PutPixel(i, j, 0, 0, 255);
		}
	int startX = (gfx.ScreenWidth / 2) - 50;
	int startY = (gfx.ScreenHeight / 2) - 50;
			for (int k = startX; k < startX + 100; k++)
				for (int m = startY; m < startY + 100; m++)
					gfx.PutPixel(k, m, 0, 255, 0);
}

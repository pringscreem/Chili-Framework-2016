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
 #pragma once

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
	bool flag = false;
	int x = 0;
	int y = 0;
	while(x < 600)
	{
		gfx.PutPixel(x, 500, 255, 255, 255);
		gfx.PutPixel(x, y, 255 - x, 255 - x, 255 - x);
		x++;
		y++;
	}

	for(int x = 100; x < 600; x++)
	{
		gfx.PutPixel(x, 100, 255, 255, 255);
	}

	x = 100;
	y = 100;
	do
	{
		gfx.PutPixel(100, y, 255 + x, 255 + x, 255 + x);
		x++;
		y++;
	} while (x < gfx.ScreenWidth && y < gfx.ScreenHeight);

	DrawRectangle();
}

void Game::DrawRectangle()
{
	//Draw a rectangle
	for (int i = recX - recXSize / 2; i < recX + recXSize / 2; i++) //x
		for (int j = recY - recYSize / 2; j < recY + recYSize / 2; j++) //j
		{
			gfx.PutPixel(i, j, 255, 255, 255);
			CheckRectangleKeys();
			ClampToScreen();
		}
}

void Game::CheckRectangleKeys()
{
	if (wnd.kbd.KeyIsPressed('W'))
	{
		recYSize++;
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		recXSize--;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		recYSize--;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		recXSize++;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		recX++;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		recX--;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		recY++;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		recY--;
	}

}

void Game::ClampToScreen()
{
	int width = recXSize / 2;
	int height = recYSize / 2;
	int x = recX;
	int y = recY;
	const int right = x + width;
	if (x < 0)
	{
		x = 0;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - width;
	}

	const int bottom = y + height;
	if (y < 0)
	{
		y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
	}
}

//
//int recX = gfx.ScreenWidth / 2;
//int recY = gfx.ScreenHeight / 2;
//int recXSize = 100;
//int recYSize = 100;
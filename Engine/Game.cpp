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
#include "MyRectangle.h"

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
	} while(x < gfx.ScreenWidth && y < gfx.ScreenHeight);

	//CheckRectangleKeys(myRect.x, myRect.y, myRect.width, myRect.height);
	//DrawRectangle(myRect.x, myRect.y, myRect.width, myRect.height);

	Color c;
	//Color c(255, 255, 0); //Use the constructor to set RGB values
	//e.g. Colors::Magenta; //Use the predefined colours that he set up
	//c.SetR(255);
	//c.SetG(255);
	//c.SetB(0);
	//CheckRectangleKeys(xPos, yPos, width, height);
	HisCheckRectangleKeys(x0, y0, x1, y1);
	HisClampRectToScreen(x0, y0, x1, y1);
	//gfx.DrawRect(xPos, yPos, xPos + width, yPos + height, c);
	gfx.DrawRect(x0, y0, x1, y1, Colors::Magenta);
}

void Game::DrawRectangle(int& x, int& y, int& width, int& height, Color c)
{
	ClampMyRectToScreen(x, y, width, height);
	//Draw a rectangle
	for(int i = x - width / 2; i < x + width / 2; i++) //x
		for(int j = y - height / 2; j < y + height / 2; j++) //y
		{
			gfx.PutPixel(i, j, 255, 255, 255);
		}
}

void Game::CheckRectangleKeys(int& x, int& y, int& width, int& height)
{
	//WASD Keys
	if(wnd.kbd.KeyIsPressed('W'))
	{
		height++;
	}
	if(wnd.kbd.KeyIsPressed('A'))
	{
		width--;
	}
	if(wnd.kbd.KeyIsPressed('S'))
	{
		height--;
	}
	if(wnd.kbd.KeyIsPressed('D'))
	{
		width++;
	}

	//Arrow Keys
	if(wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x++;
	}
	if(wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x--;
	}
	if(wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y++;
	}
	if(wnd.kbd.KeyIsPressed(VK_UP))
	{
		y--;
	}
}

void Game::ClampMyRectToScreen(int& x, int& y, int& width, int& height)
{
	//Check Width
	if(width >= Graphics::ScreenWidth)
	{
		width = Graphics::ScreenWidth - 1;
	}
	if (width < 0)
	{
		width = 0;
	}
	const int right = x + (width / 2);
	const int left = x - (width / 2);
	//Check Left and Right Screen Edges
	if(left < 0)
	{
		x = 1 + (width / 2);
	}
	else if(right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - (width / 2) - 1;
	}

	//Check Height
	if(height >= Graphics::ScreenHeight)
	{
		height = Graphics::ScreenHeight - 1;
	}
	if (height < 0)
	{
		height = 0;
	}
	//Check Top and Bottom Screen Edges
	const int bottom = y + (height / 2);
	const int top = y - (height / 2);
	if(top < 0)
	{
		y = 1 + (height / 2);
	}
	else if(bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - (height / 2) - 1;
	}
}

void Game::HisClampRectToScreen(int& x0, int& y0, int& x1, int& y1)
{
	//Check x1 (Right)
	if (x1 >= Graphics::ScreenWidth)
	{
		x1 = Graphics::ScreenWidth - 1;
	}
	//Check x0 (Left)
	if (x0 < 0)
	{
		x0 = 0;
	}
	//Check x0 (Right)
	if (x0 >= Graphics::ScreenWidth)
	{
		x0 = Graphics::ScreenWidth - 1;
	}
	//Check x1 (Left)
	if (x1 < 0)
	{
		x1 = 0;
	}

	//Check y1 (Bottom)
	if (y1 >= Graphics::ScreenHeight)
	{
		y1 = Graphics::ScreenHeight - 1;
	}
	//Check y0 (Top)
	if (y0 < 0)
	{
		y0 = 0;
	}
	//Check y0 (Bottom)
	if (y0 >= Graphics::ScreenHeight)
	{
		y0 = Graphics::ScreenHeight - 1;
	}
	//Check y1 (Top)
	if (y1 < 0)
	{
		y1 = 0;
	}
}

//This still behaves badly if you deliberately crash into the wall
void Game::HisCheckRectangleKeys(int& x0, int& y0, int& x1, int& y1)
{
	//WASD Keys
	if (wnd.kbd.KeyIsPressed('W'))
	{
		y1--;
	}
	if (wnd.kbd.KeyIsPressed('A'))
	{
		x1--;
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		y1++;
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		x1++;
	}

	//Arrow Keys
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x0++;
		x1++;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x0--;
		x1--;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y0++;
		y1++;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y0--;
		y1--;
	}
}

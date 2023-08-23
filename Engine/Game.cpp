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
	int x = 400, y = 300;
	int red = 255, green = 255, blue = 255;

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= 100;
	}
	else if(wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += 100;
	}
	else
	{
		x = 400;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= 100;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += 100;
	}
	else
	{
		y = 300;
	}

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		red = 255;
		green = 0;
		blue = 0;
	}
	else
	{
		red = 255;
		green = 255;
		blue = 255;
	}

	if(wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		//Square Pixels
		//Top Right
		gfx.PutPixel(+5 + x, -5 + y, red, green, blue);
		gfx.PutPixel(+5 + x, -4 + y, red, green, blue);
		gfx.PutPixel(+5 + x, -3 + y, red, green, blue);
		gfx.PutPixel(+4 + x, -5 + y, red, green, blue);
		gfx.PutPixel(+3 + x, -5 + y, red, green, blue);

		//Top Left
		gfx.PutPixel(-5 + x, -5 + y, red, green, blue);
		gfx.PutPixel(-5 + x, -4 + y, red, green, blue);
		gfx.PutPixel(-5 + x, -3 + y, red, green, blue);
		gfx.PutPixel(-4 + x, -5 + y, red, green, blue);
		gfx.PutPixel(-3 + x, -5 + y, red, green, blue);

		//Bottom Left
		gfx.PutPixel(-5 + x, +5 + y, red, green, blue);
		gfx.PutPixel(-5 + x, +4 + y, red, green, blue);
		gfx.PutPixel(-5 + x, +3 + y, red, green, blue);
		gfx.PutPixel(-4 + x, +5 + y, red, green, blue);
		gfx.PutPixel(-3 + x, +5 + y, red, green, blue);

		//Bottom Right
		gfx.PutPixel(+5 + x, +5 + y, red, green, blue);
		gfx.PutPixel(+5 + x, +4 + y, red, green, blue);
		gfx.PutPixel(+5 + x, +3 + y, red, green, blue);
		gfx.PutPixel(+4 + x, +5 + y, red, green, blue);
		gfx.PutPixel(+3 + x, +5 + y, red, green, blue);
	}
	else
	{
		//Reticle Pixels:
		gfx.PutPixel(-5 + x,     y, red, green, blue);
		gfx.PutPixel(-4 + x,     y, red, green, blue);
		gfx.PutPixel(-3 + x,     y, red, green, blue);
		gfx.PutPixel(+5 + x,     y, red, green, blue);
		gfx.PutPixel(+4 + x,     y, red, green, blue);
		gfx.PutPixel(+3 + x,     y, red, green, blue);
		gfx.PutPixel(     x,-5 + y, red, green, blue);
		gfx.PutPixel(     x,-4 + y, red, green, blue);
		gfx.PutPixel(     x,-3 + y, red, green, blue);
		gfx.PutPixel(     x,+5 + y, red, green, blue);
		gfx.PutPixel(     x,+4 + y, red, green, blue);
		gfx.PutPixel(     x,+3 + y, red, green, blue);
		gfx.PutPixel(     x,     y, red, green, blue); //shift + ctrl + space to pull up Intellisense function info
	}
}

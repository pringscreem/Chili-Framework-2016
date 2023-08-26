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
	//Velocity Change
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (inhibitLeft)
		{
			//Do nothing
		}
		else
		{
			vx -= 1;
			inhibitLeft = true;
		}
	}
	else
	{
		inhibitLeft = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if(inhibitRight)
		{
			//Do nothing
		}
		else
		{
			vx += 1;
			inhibitRight = true;
		}
	}
	else
	{
		inhibitRight = false;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (inhibitUp)
		{
			//Do nothing
		}
		else
		{
			vy -= 1;
			inhibitUp = true;
		}
	}
	else
	{
		inhibitUp = false;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (inhibitDown)
		{
			//Do nothing
		}
		else
		{
			vy += 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}

	//Position Change
	x = x + vx;
	y = y + vy;
	//Check Screen Boundaries
	if(x + 5 >= gfx.ScreenWidth) //5 == cursor radius
	{
		x = gfx.ScreenWidth - 6;//6 == cursor radius + 1
		vx = 0.0;
	}
	if (x - 5 < 0)
	{
		x = 0 + 5;
		vx = 0.0;
	}
	
	if (y - 5 < 0)
	{
		y = 0 + 5;
		vy = 0.0;
	}
	if (y + 5 >= gfx.ScreenHeight)
	{
		y = gfx.ScreenHeight - 6;
		vy = 0.0;
	}

	////Check Screen Boundaries
	//if ((x > gfx.ScreenWidth - 5 || x < 0 + 5) || (y > gfx.ScreenHeight - 5 || y < 0 + 5))
	//{
	//	vx = 0.0;
	//	vy = 0.0;
	//	x = 400; //This just resets the position to the centre
	//	y = 300; //His version (leave it at the nearest edge position) 
	//			 //is better, but he uses hardcoded values.
	//}

	//Colour Change
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
		shapeIsChanged = true;
	}
	else if (!wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		shapeIsChanged = false; //a.k.a. "shiftIsPressed" or "controlIsPressed"
	}
}


void Game::ComposeFrame()
{
	if(shapeIsChanged)
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

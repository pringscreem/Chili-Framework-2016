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
 *	The Chili Directx_mobileFramework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili Directx_mobileFramework.  If not, see <http://www.gnu.org/licenses/>.  *
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
			vx_mobile -= 1;
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
			vx_mobile += 1;
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
			vy_mobile -= 1;
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
			vy_mobile += 1;
			inhibitDown = true;
		}
	}
	else
	{
		inhibitDown = false;
	}

	//Position Change
	x_mobile = x_mobile + vx_mobile;
	y_mobile= y_mobile+ vy_mobile;
	//Check Screen Boundaries
	if(x_mobile + 5 >= gfx.ScreenWidth) //5 == cursor radius
	{
		x_mobile= gfx.ScreenWidth - 6;//6 == cursor radius + 1
		vx_mobile = 0;
	}
	if (x_mobile- 5 < 0)
	{
		x_mobile= 0 + 5;
		vx_mobile = 0;
	}
	
	if (y_mobile- 5 < 0)
	{
		y_mobile= 0 + 5;
		vy_mobile = 0;
	}
	if (y_mobile+ 5 >= gfx.ScreenHeight)
	{
		y_mobile= gfx.ScreenHeight - 6;
		vy_mobile = 0;
	}

	//Colour Change
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		red_mobile = 255;
		green_mobile = 0;
		blue_mobile = 255;
	}
	else if (!wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		red_mobile = 255;
		green_mobile = 255;
		blue_mobile = 255;
	}

	//Shape Change
	if(wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		shapeIsChanged = true;
	}
	else if (!wnd.kbd.KeyIsPressed(VK_SHIFT))
	{
		shapeIsChanged = false; //a.k.a. "shiftIsPressed" or "controlIsPressed"
	}

	//Collision Check and Colour Change 
	hasCollided = OverlapTest(x_fixed, y_fixed, x_mobile, y_mobile);
	//He does the colour change in ComposeFrame

}


void Game::ComposeFrame()
{
	//Draw Reticle or Box
	if (hasCollided)
	{
		red_mobile = 255;
		green_mobile = 0;
		blue_mobile = 0;
	}
	if(shapeIsChanged)
	{
		DrawBox(x_mobile, y_mobile, red_mobile, green_mobile, blue_mobile);
	}
	else
	{
		DrawReticle(x_mobile, y_mobile, red_mobile, green_mobile, blue_mobile);
	}

	//Draw Second Box
	DrawBox(x_fixed, y_fixed, red_fixed, green_fixed, blue_fixed);
}

//Draw 5x5 box (corners only)
void Game::DrawBox(const int x, const int y, const int red, const int green, const int blue)
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

//Draw 5x5 reticle (with middle dot)
void Game::DrawReticle(const int x, const int y, const int red, const int green, const int blue)
{
	//Reticle Pixels:
	gfx.PutPixel(-5 + x,      y, red, green, blue);
	gfx.PutPixel(-4 + x,      y, red, green, blue);
	gfx.PutPixel(-3 + x,      y, red, green, blue);
	gfx.PutPixel(+5 + x,      y, red, green, blue);
	gfx.PutPixel(+4 + x,      y, red, green, blue);
	gfx.PutPixel(+3 + x,      y, red, green, blue);
	gfx.PutPixel(     x, -5 + y, red, green, blue);
	gfx.PutPixel(     x, -4 + y, red, green, blue);
	gfx.PutPixel(     x, -3 + y, red, green, blue);
	gfx.PutPixel(     x, +5 + y, red, green, blue);
	gfx.PutPixel(     x, +4 + y, red, green, blue);
	gfx.PutPixel(     x, +3 + y, red, green, blue);
	gfx.PutPixel(     x,      y, red, green, blue);
}

//Check if two 5x5 pixel objects overlap
bool Game::OverlapTest(const int x_box0, const int y_box0, const int x_box1, const int y_box1)
{
	//Helper Variables
	bool hasCollided = false; //Default fail, check for pass
	//Box 1 (User-Controlled Box)
	const int x_box0Min = x_box0 - 5;
	const int x_box0Max = x_box0 + 5;
	const int y_box0Min = y_box0- 5;
	const int y_box0Max = y_box0+ 5;
	//Box 2 (Target Box)
	const int x_box1Min = x_box1 - 5;
	const int x_box1Max = x_box1 + 5;
	const int y_box1Min = y_box1 - 5;
	const int y_box1Max = y_box1 + 5;

	//The actual check:
	if(((x_box1Min <= x_box0Max) && (x_box1Min >= x_box0Min)) || ((x_box1Max >= x_box0Min) && (x_box1Max <= x_box0Max)))
	{ //My check is different from his, but it has the same number of condition checks
		//The left (min) edge of Box 2 is in bounds.
		if((y_box1Min <= y_box0Max) && (y_box1Min >= y_box0Min))
		{
			//Top of Box 2 is in bounds.
			hasCollided = true;
		}
		if((y_box1Max >= y_box0Min) && (y_box1Max <= y_box0Max))
		{
			//Bottom of Box 2 is in bounds.
			hasCollided = true;
		}
	}
	return hasCollided;
}
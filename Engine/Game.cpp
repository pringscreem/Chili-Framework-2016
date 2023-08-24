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

	int x = 400, y = 300;
	int red = 255, green = 255, blue = 255;
void Game::ComposeFrame()
{

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x -= 3; //This is only  executed once because everytime the frame is drawn the variables are remade.
	}			  //This is a consequence of the way we have it set up right now (variable declaration in ComposeFrame).
	else if(wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x += 3;
	}
	//else //We don't need the else statements because the frame creates the variables and resets them during creation everytime.
	//{	 //It seems like the frame is drawn at the end of the ComposeFrame function.
	//	x = 400;
	//}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y -= 3;
	}
	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y += 3;
	}
	//else
	//{
	//	y = 300;
	//}

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

	int mouseRed = 0, mouseGreen = 0, mouseBlue = 255;
	int mouseX = 400, mouseY = 300;
	if(wnd.mouse.GetPosX() < gfx.ScreenWidth && wnd.mouse.GetPosX() > 0)
	{
		mouseX = wnd.mouse.GetPosX();	
	}
	if (wnd.mouse.GetPosY() < gfx.ScreenHeight && wnd.mouse.GetPosY() > 0)
	{
		mouseY = wnd.mouse.GetPosY();
	}
	if(wnd.mouse.LeftIsPressed() == true)
	{
		mouseRed = 255;
	}
	gfx.PutPixel(-5 + mouseX,     mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(-4 + mouseX,     mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(-3 + mouseX,     mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(+5 + mouseX,     mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(+4 + mouseX,     mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(+3 + mouseX,     mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(     mouseX,-5 + mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(     mouseX,-4 + mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(     mouseX,-3 + mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(     mouseX,+5 + mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(     mouseX,+4 + mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(     mouseX,+3 + mouseY, mouseRed, mouseGreen, mouseBlue);
	gfx.PutPixel(     mouseX,     mouseY, mouseRed, mouseGreen, mouseBlue);
}

#pragma once

#include "MyRectangle.h"
#include "Graphics.h"

void MyRectangle::MyDrawRectangle(Graphics& gfx) const
{
		//MyClampRectToScreen(x, y, width, height);
		//Draw a rectangle
		for (int i = x - width / 2; i < x + width / 2; i++) //x
			for (int j = y - height / 2; j < y + height / 2; j++) //y
			{
				gfx.PutPixel(i, j, 255, 255, 255);
			}
}


void MyRectangle::MyClampRectToScreen(int& x, int& y, int& width, int& height)
{
	//Check Width
	if (width >= Graphics::ScreenWidth)
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
	if (left < 0)
	{
		x = 1 + (width / 2);
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - (width / 2) - 1;
	}

	//Check Height
	if (height >= Graphics::ScreenHeight)
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
	if (top < 0)
	{
		y = 1 + (height / 2);
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - (height / 2) - 1;
	}
}

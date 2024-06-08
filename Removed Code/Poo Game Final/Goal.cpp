#pragma once

#include "Goal.h"
#include "Graphics.h"
#include "Dude.h"
#include <assert.h>

void Goal::Init(int in_x, int in_y, int in_vx, int in_vy)
{
	assert(initialized == false);
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	initialized = true;
}

void Goal::Update()
{
	assert(initialized == true);
	x += vx;
	y += vy;

	const int right = x + width;
	if (x < 0)
	{
		x = 0;
		vx = -vx;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - width;
		vx = -vx;
	}

	const int bottom = y + height;
	if (y < 0)
	{
		y = 0;
		vy = -vy;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
		vy = -vy;
	}
}

void Goal::ProcessConsumption(const Dude& dude)
{
	assert(initialized == true);
	const int duderight = dude.GetX() + dude.GetWidth();
	const int dudebottom = dude.GetY() + dude.GetHeight();
	const int goalright = x + width;
	const int goalbottom = y + height;

	if (duderight >= x &&
		dude.GetX() <= goalright &&
		dudebottom >= y &&
		dude.GetY() <= goalbottom
		)
	{
		isEaten = true;
	}
}

void Goal::Draw(Graphics& gfx)
{
	assert(initialized == true);
	//Update colour
	if (goingUp)
	{
		green += 5;
		blue += 5;
		if (green > 250 || blue > 250)
		{
			goingUp = false;
		}
	}
	else
	{
		green -= 5;
		blue -= 5;
		if (green < 5 || blue < 5)
		{
			goingUp = true;
		}
	}
	Color colour(red, green, blue);
	gfx.DrawRectDim(x, y, width, height, colour);
}

bool Goal::IsEaten() const
{
	assert(initialized == true);
	return isEaten;
}

void Goal::SetX(int in_x)
{
	assert(initialized == true);
	x = in_x;
}

void Goal::SetY(int in_y)
{
	assert(initialized == true);
	y = in_y;
}


void Goal::ClampToScreen()
{

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
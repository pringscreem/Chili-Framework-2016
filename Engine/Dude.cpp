#pragma once

#include "Dude.h"
#include "Graphics.h"

//void Dude::Update()
//{
//	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
//	{
//		dude.x += 1;
//	}
//	if (wnd.kbd.KeyIsPressed(VK_LEFT))
//	{
//		dude.x -= 1;
//	}
//	if (wnd.kbd.KeyIsPressed(VK_DOWN))
//	{
//		dude.y += 1;
//	}
//	if (wnd.kbd.KeyIsPressed(VK_UP))
//	{
//		dude.y -= 1;
//	}
//}

void Dude::ClampToScreen()
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

void Dude::Asdf()
{
}


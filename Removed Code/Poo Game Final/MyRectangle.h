#pragma once

#include "Graphics.h"

class MyRectangle
{
	public:
		void MyDrawRectangle(Graphics& gfx) const;
		void MyClampRectToScreen(int& x, int& y, int& width, int& height);
		int x = 500;
		int y = 500;
		int width = 100;
		int height = 100;

	private:
		//
};


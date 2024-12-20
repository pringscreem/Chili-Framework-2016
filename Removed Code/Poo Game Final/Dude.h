#pragma once

//#include "MainWindow.h"
#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
	public:
		void Update(const Keyboard& kbd);
		void ClampToScreen();
		void Draw(Graphics& gfx) const;
		void SetX(int in_x);
		int GetX() const;
		void SetY(int in_y);
		int GetY() const;
		int GetWidth() const; //Keeping these non-static makes it less likely that later changes will break stuff.
		int GetHeight() const;
	private:
		int x = 400;
		int y = 300;

		static constexpr int speed = 4;
		static constexpr int width = 20;
		static constexpr int height = 20;
};
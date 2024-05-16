#pragma once

//#include "MainWindow.h"
#include "Graphics.h"

class Dude
{
	public:
		//void Update();
		void ClampToScreen();
		void Draw(Graphics& gfx) const;
		int x = 400;
		int y = 300;
		static constexpr int width = 20;
		static constexpr int height = 20;
	private:
};
#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
	public:
		void Update();
		void ProcessConsumption(const Dude& dude);
		void Draw(Graphics& gfx) const; //This const means it doesn't change any class members
		int x;
		int y;
		int vx;
		int vy;
		static constexpr int width = 24; //All the instances of the class share the variable
		static constexpr int height = 24;
		bool isEaten = false;
	private:
};//The semi-colon after classes is a common error (reminder)
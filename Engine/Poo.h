#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
	public:
		Poo(int in_x, int in_y, int in_vx, int in_vy)
		{
			x = in_x;
			y = in_y;
			vx = in_vx;
			vy = in_vy;
		}
		void Update();
		void ProcessConsumption(const Dude& dude); //This const means it doesn't change the argument's data
		void Draw(Graphics& gfx) const; //This const means it doesn't change any class members
		bool IsEaten() const; //Getter
	private:
		int x;
		int y;
		int vx;
		int vy;
		static constexpr int width = 24; //All the instances of the class share the variable
		static constexpr int height = 24;
		bool isEaten = false;
};//The semi-colon after classes is a common error (reminder)
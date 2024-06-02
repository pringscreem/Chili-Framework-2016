#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
	public:
		void Init(int in_x, int in_y, int in_vx, int in_vy);
		void Update();
		void ProcessConsumption(const Dude& dude); //This const means it doesn't change the argument's data
		void Draw(Graphics& gfx) const; //This const means it doesn't change any class members
		bool IsEaten() const; //Getter
		void SetX(int in_x);
		void SetY(int in_y);
	private:
		int x;
		int y;
		int vx;
		int vy;
		static constexpr int width = 24; //All the instances of the class share the variable
		static constexpr int height = 24;
		bool isEaten = false;
		bool initialized = false;
};//The semi-colon after classes is a common error (reminder)
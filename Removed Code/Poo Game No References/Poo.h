#pragma once

class Poo
{
	public:
		void Update();
		void ProcessConsumption(int dudex, int dudey, int dudewidth, int dudeheight);
		int x;
		int y;
		int vx;
		int vy;
		static constexpr int width = 24; //All the instances of the class share the variable
		static constexpr int height = 24;
		bool isEaten = false;
	private:
};//The semi-colon after classes is a common error (reminder)
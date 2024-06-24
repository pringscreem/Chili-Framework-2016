/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Board.h"
#include <random>
#include <chrono>
#include <fstream>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void MyTestBoard();
	void HisTestBoard();
	void CheckKeys(const Keyboard& kbd);
	//Life Functions
	void LifeComposeFrame();
	void LifeUpdateModel();
	void LifeCheckKeys(const Keyboard& kbd);
	void LifeDrawPosition(const Location& position);
	void LifeClampPosition();
	void LifeTestFrameTime();
	void LifeFrameRateFlash();

	//Output to Text File
	void RequestOutputTxt(/*std::string requestedOutput1,*/ float requestedOutputNum/*, std::string requestedOutput2*/);
	void LineInOutputTxt();
	void OutputTxtToFile(std::string requestedOutputStr, float requestedOutputNum);
	void OutputFrameAverage();
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	Board brd;
	std::mt19937 rng;
	int slowCount = 0;
	Color keepColour;

	Location delta_loc = {0, 0};
	//Life Variables
	Location position = {0, 0};
	int spacebarDelayFrames = 10;
	int spacebarTimerCounter = 0;
	int flip = 0;
	bool startFlag = false;
	bool endFlag = false;
	
	//Frame Rate Testing Variables
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	
	//Repeated Test for Text Output
	int frameCounter = 0;
	std::chrono::high_resolution_clock::time_point start2 = std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point end2 = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	/********************************/
};
	////Blue background and a black square in the middle
	//for(int i = 0; i < gfx.ScreenWidth; i++) //800
	//	for(int j = 0; j < gfx.ScreenHeight; j++) //600
	//	{ 
	//		gfx.PutPixel(i, j, 0, 0, 255);
	//	}
	//int startX = (gfx.ScreenWidth / 2) - 50;
	//int startY = (gfx.ScreenHeight / 2) - 50;
	//		for (int k = startX; k < startX + 100; k++)
	//			for (int m = startY; m < startY + 100; m++)
	//				gfx.PutPixel(k, m, 0, 0, 0);
	
	
	////Put dots on the screen every 100 pixels
	//int xFlag = 0, yFlag= 0;
	//int red = 255, green = 255, blue = 255;
	//while (yFlag < gfx.ScreenHeight)
	//{
	//		while(xFlag < gfx.ScreenWidth)
	//		{
	//			if((xFlag % 100 == 0) && (yFlag % 100 == 0))
	//				{
	//					gfx.PutPixel(xFlag, yFlag, red, green, blue);
	//				}
	//			//xFlag++;
	//			xFlag += 100;
	//		}
	//	xFlag = 0;
	//	yFlag += 100;
	//	//yFlag++;
	//}

	////Write the value of iterationCounter to a file named MyCounter.txt
	////The previous location of this file (when using the Debug builder) was:
	//// C:\msys64\home\ssonn\GitHub2023\Chili-Framework-2016\Debug
	//#include <fstream>
	//int iterationCounter = 0;
	//std::ofstream MyCounterFile;
	//MyCounterFile.open("MyCounter.txt");
	//MyCounterFile << "The value of iterationCounter is " << iterationCounter;
	//MyCounterFile.close();


////Homework 3:
//void Game::ComposeFrame()
//{
//	int x = 400, y = 300;
//	int red = 255, green = 255, blue = 255;
//
//	if (wnd.kbd.KeyIsPressed(VK_LEFT))
//	{
//		x -= 100; //This is only  executed once because everytime the frame is drawn the variables are remade.
//	}			  //This is a consequence of the way we have it set up right now (variable declaration in ComposeFrame).
//	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
//	{
//		x += 100;
//	}
//	else //We don't need the else statements because the frame creates the variables and resets them during creation everytime.
//	{	 //It seems like the frame is drawn at the end of the ComposeFrame function.
//		x = 400;
//	}
//
//	if (wnd.kbd.KeyIsPressed(VK_UP))
//	{
//		y -= 100;
//	}
//	else if (wnd.kbd.KeyIsPressed(VK_DOWN))
//	{
//		y += 100;
//	}
//	else
//	{
//		y = 300;
//	}
//
//	if (wnd.kbd.KeyIsPressed(VK_SPACE))
//	{
//		red = 255;
//		green = 0;
//		blue = 0;
//	}
//	else
//	{
//		red = 255;
//		green = 255;
//		blue = 255;
//	}
//
//	if (wnd.kbd.KeyIsPressed(VK_SHIFT))
//	{
//		//Square Pixels
//		//Top Right
//		gfx.PutPixel(+5 + x, -5 + y, red, green, blue);
//		gfx.PutPixel(+5 + x, -4 + y, red, green, blue);
//		gfx.PutPixel(+5 + x, -3 + y, red, green, blue);
//		gfx.PutPixel(+4 + x, -5 + y, red, green, blue);
//		gfx.PutPixel(+3 + x, -5 + y, red, green, blue);
//
//		//Top Left
//		gfx.PutPixel(-5 + x, -5 + y, red, green, blue);
//		gfx.PutPixel(-5 + x, -4 + y, red, green, blue);
//		gfx.PutPixel(-5 + x, -3 + y, red, green, blue);
//		gfx.PutPixel(-4 + x, -5 + y, red, green, blue);
//		gfx.PutPixel(-3 + x, -5 + y, red, green, blue);
//
//		//Bottom Left
//		gfx.PutPixel(-5 + x, +5 + y, red, green, blue);
//		gfx.PutPixel(-5 + x, +4 + y, red, green, blue);
//		gfx.PutPixel(-5 + x, +3 + y, red, green, blue);
//		gfx.PutPixel(-4 + x, +5 + y, red, green, blue);
//		gfx.PutPixel(-3 + x, +5 + y, red, green, blue);
//
//		//Bottom Right
//		gfx.PutPixel(+5 + x, +5 + y, red, green, blue);
//		gfx.PutPixel(+5 + x, +4 + y, red, green, blue);
//		gfx.PutPixel(+5 + x, +3 + y, red, green, blue);
//		gfx.PutPixel(+4 + x, +5 + y, red, green, blue);
//		gfx.PutPixel(+3 + x, +5 + y, red, green, blue);
//	}
//	else
//	{
//		//Reticle Pixels:
//		gfx.PutPixel(-5 + x, y, red, green, blue);
//		gfx.PutPixel(-4 + x, y, red, green, blue);
//		gfx.PutPixel(-3 + x, y, red, green, blue);
//		gfx.PutPixel(+5 + x, y, red, green, blue);
//		gfx.PutPixel(+4 + x, y, red, green, blue);
//		gfx.PutPixel(+3 + x, y, red, green, blue);
//		gfx.PutPixel(x, -5 + y, red, green, blue);
//		gfx.PutPixel(x, -4 + y, red, green, blue);
//		gfx.PutPixel(x, -3 + y, red, green, blue);
//		gfx.PutPixel(x, +5 + y, red, green, blue);
//		gfx.PutPixel(x, +4 + y, red, green, blue);
//		gfx.PutPixel(x, +3 + y, red, green, blue);
//		gfx.PutPixel(x, y, red, green, blue); //shift + ctrl + space to pull up Intellisense function info
//	}
//}
//
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
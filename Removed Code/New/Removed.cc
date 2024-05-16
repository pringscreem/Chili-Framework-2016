void TestAndSwap(int& a, int& b);
void Graphics::TestAndSwap(int& a, int& b)
{
	if (a > b)
	{
		//a += b;
		//b = a - b;
		const int temp = a;
		a = b;
		b = temp;
	}
}


void Game::ComposeFrame()
{
	bool flag = false;
	int x = 0;
	int y = 0;
	while (x < 600)
	{
		gfx.PutPixel(x, 500, 255, 255, 255);
		gfx.PutPixel(x, y, 255 - x, 255 - x, 255 - x);
		x++;
		y++;
	}

	for (int x = 100; x < 600; x++)
	{
		gfx.PutPixel(x, 100, 255, 255, 255);
	}

	x = 100;
	y = 100;
	do
	{
		gfx.PutPixel(100, y, 255 + x, 255 + x, 255 + x);
		x++;
		y++;
	} while (x < gfx.ScreenWidth && y < gfx.ScreenHeight);

	//MyCheckRectangleKeys(myRect.x, myRect.y, myRect.width, myRect.height);
	//MyDrawRectangle(myRect.x, myRect.y, myRect.width, myRect.height);

	Color c;
	//Color c(255, 255, 0); //Use the constructor to set RGB values
	//e.g. Colors::Magenta; //Use the predefined colours that he set up
	//c.SetR(255);
	//c.SetG(255);
	//c.SetB(0);
	//MyCheckRectangleKeys(xPos, yPos, width, height);
	HisCheckRectangleKeys(x0, y0, x1, y1);
	HisClampRectToScreen(x0, y0, x1, y1);
	//gfx.DrawRect(xPos, yPos, xPos + width, yPos + height, c);
	gfx.DrawRect(x0, y0, x1, y1, Colors::Magenta);
}
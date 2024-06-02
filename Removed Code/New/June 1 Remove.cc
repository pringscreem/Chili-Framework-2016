//Previous version of Game Constructor
Game::Game(MainWindow& wnd)
	: //This colon starts the initializer list for the constructor
	wnd(wnd),
	gfx(wnd),
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570),
	pooArr{
			{xDist(rng), yDist(rng), 1, -1}, //The syntax for initializing an array of classes like this is a mess.
			{xDist(rng), yDist(rng), -1, 1}, //You have to use curly braces instead of parentheses because
			{xDist(rng), yDist(rng), -1, 1}, // otherwise it misinterprets what you want to be the element 
			{xDist(rng), yDist(rng), 1, -1}, // values as function arguments instead.
			{xDist(rng), yDist(rng), 1, 1},
			{xDist(rng), yDist(rng), -1, 1},
			{xDist(rng), yDist(rng), -1, 1},
			{xDist(rng), yDist(rng), 1, -1},
			{xDist(rng), yDist(rng), 1, -1}
}
{
	//RequestOutputTxt("The Game constructor has been called. \n");
}


//Remove Constructor from Poo
Poo();
Poo::Poo()
{
	x = 100;
	y = 100;
	vx = 1;
	vy = 1;
}
Poo(int in_x, int in_y, int in_vx, int in_vy);
Poo::Poo(int in_x, int in_y, int in_vx, int in_vy)
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
}

//From the Game Constructor Initialization List
pooArr{
		{xDist(rng), yDist(rng), 1, -1}, //The syntax for initializing an array of classes like this is a mess.
		{xDist(rng), yDist(rng), -1, 1}, //You have to use curly braces instead of parentheses because
		{xDist(rng), yDist(rng), -1, 1}, // otherwise it misinterprets what you want to be the element 
		{xDist(rng), yDist(rng), 1, -1}, // values as function arguments instead.
		{xDist(rng), yDist(rng), 1, 1},
		{xDist(rng), yDist(rng), -1, 1},
		{xDist(rng), yDist(rng), -1, 1},
		{xDist(rng), yDist(rng), 1, -1},
		{xDist(rng), yDist(rng), 1, -1}
}

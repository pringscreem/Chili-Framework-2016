#include <fstream>
//Class Declaration
void RequestOutputTxt(/*std::string requestedOutput1,*/ int requestedOutputNum/*, std::string requestedOutput2*/);

//Definition

void Game::RequestOutputTxt(/*std::string requestedOutput1,*/ int requestedOutputNum/*, std::string requestedOutput2*/)
{
	//The output file is in :
	//C:\msys64\home\ssonn\GitHub2023\Chili - Framework - 2016\Debug
	std::ofstream MyOutputFile;
	MyOutputFile.open("MyOutput.txt", std::ios_base::app);

	MyOutputFile << "The value of requested output number is " << requestedOutputNum << '\n';
	//MyOutputFile << "The value of requested output 2 is " << requestedOutput2 << '\n';

	MyOutputFile.close();
}
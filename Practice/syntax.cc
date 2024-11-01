#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
	std::vector<int> myVector = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for(auto i : myVector)
	{
		std::cout << "myVector[" << i << "]: " << myVector[i] << std::endl;
	}

	std::cout << "It worked.\n";
	return 0;
}
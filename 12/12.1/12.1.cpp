#include <iostream>
#include <string>

int main()
{
	std::string sernames[10];
	int doors[10];
	std::cout << "input sernames\n";
	for (int i = 0; i < 10; i++)
	{
		//std::cout << "input sernames\n";
		std::cin >> sernames[i];
	}
	for (int i = 0; i < 3; i++)
	{
		int j;
		std::cin >> j;
		if (j > 0 && j < 11)
			std::cout << sernames[j - 1] << "\n";
		else
			std::cout << "incorrect input\n";
	}
}
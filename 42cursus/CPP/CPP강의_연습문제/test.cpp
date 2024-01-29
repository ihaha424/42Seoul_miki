#include <iostream>

int main() 
{
	int a = 4;
	{
		std::cout << "1. " << a << std::endl;
		int a = 3;
		std::cout << "2. " << a << std::endl;
	}
	std::cout << "3. " << a << std::endl;
}
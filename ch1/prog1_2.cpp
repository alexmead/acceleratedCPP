#include <iostream>
#include <string>

int main()
{
	const std::string exclaim = "!";
	const std::string message = "Hello" + ", world" + exclaim; // wont work because both operands to the + operator are string literals
	
	std::cout << exclaim << std::endl;
    std::cout << message << std::endl;
	
	return 0;
}

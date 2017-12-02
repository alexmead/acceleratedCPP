// testing some string properties
#include <string>
#include <iostream>

int main()
{
    // This program works because ", world" is a string literal and "!" is a char
    const std::string hello = "Hello?";
    const std::string message = hello + ", world" + "!";
    
    std::cout << hello << std::endl;
    std::cout << message << std::endl;
    
    return 0;
}

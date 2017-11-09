#include <iostream>
#include <string>

int main()
{
    { std::string s = "a string";
    { std::string x = s + ", reality";
        std::cout << s << std::endl; }
        std::cout << x << std::endl; // The error here is a scope issue. x was defined inside another block, so it has been deleted upon exiting that block
    }
    return 0;
}

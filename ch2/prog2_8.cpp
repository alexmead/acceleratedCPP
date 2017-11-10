// simple output game with a while loop
#include <iostream>

int main(){

    std::cout << "Enter first integer between 1 and 9: ";
    int first, second;
    std::cin >> first;
    std::cout << "Enter second integer between 1 and 9: ";
    std::cin >> second;
    
    std::cout << "Their product is: " << first * second << std::endl;
    
}

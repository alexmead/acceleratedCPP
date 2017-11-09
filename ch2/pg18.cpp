// ask for a person's name, and generate a framed greeting
#include <iostream>
#include <string>

int main()
{
    // ask for the person's name
    std::cout << "Please enter your first name: ";
    
    // read the name
    std::string name; // define name
    std::cin >> name; // read into name
    
    // build the message that we intend to write
    const std::string greeting = "Hello, " + name + "!";
    
    // seperate output from the input
    std::cout << std::endl;
    
    const int pad = 1;// number of blanks surrounding greeting
    const int rows = pad * 2 + 3; // total number of rows
    const std::string::size_type cols = greeting.size() + pad * 2 +2
    
    // write rows rows of output
    int r = 0;
    
    // invarient: we have written r rows so far
    while (r != rows) {
        // write a row
        std::string::size_type c = 0;
        // invarient: we have written c characters so far for the current row
        while (c != cols){
            // write one or more characters
            // addjust c
        }
        ++r;
    }
    
    return 0;
}

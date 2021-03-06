// ask for a person's name, and generate a framed greeting
#include <iostream>
#include <string>

// Create shorter names for standard library objects we use a lot
using std::cin; using std::endl;
using std::cout; using std::string;

int main()
{
    // ask for the person's name
    cout << "Please enter your first name: ";
    
    // read the name
    string name; // define name
    cin >> name; // read into name
    
    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";
    
    // seperate output from the input, i.e. give space on the terminal output for better viewing.
    cout << endl;
    
    const int padVertical = 3;// number of blanks surrounding greeting
    const int padHorizontal = 10;
    const int rows = padVertical * 2 + 3; // total number of rows
    const string::size_type cols = greeting.size() + padHorizontal * 2 + 2;
    
    // invarient: we have written r rows so far
    for (int r=0; r != rows; ++r) {
        
        // write a row
        string::size_type c = 0;
        
        // invarient: we have written c characters so far for the current row
        while (c != cols){
            
            // Check greeting first
            if (r == padVertical + 1 && c == padHorizontal +1) {
                std::cout << greeting;
                c += greeting.size();
                
            // Else, it is a boarder or white space
            } else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    std::cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        
        cout << endl;
    }
    
    return 0;
}

// testing stream output width, setw()

// This series of exercises, 4-2, 4-3, 4-4 is a bit nondescript in
// the exact goal of the program. I think my work fulfills the
// spirit of the exercises as the columns line up, but I'm not totally
// sure if this is what is intended.

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::string;

int main(){
    // how high, but not including, do you want to display?
    int maxSquaredValue = 101;
    
    // Based on the largest value, what is a good baseWidth?
    int baseWidth = 22 + (int)std::to_string(maxSquaredValue).size() - 3;
    
    for (double i = 0; i != maxSquaredValue; ++i){
        int widthAdjustment;
        string integer, square;
        integer = std::to_string(i);
        square = std::to_string(std::pow(i,2));
        widthAdjustment = baseWidth - (int)integer.size();
        
        cout << "Integer: " << integer
        << std::setw(widthAdjustment) << " Squared: " << square << std::endl;
    }
}

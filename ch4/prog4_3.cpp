// testing stream output width, setw()
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::string;

int main(){
    // how high, but not including, do you want to display?
    int maxSquaredValue = 1000;
    
    // Based on the largest value, what is a good baseWidth?
    int baseWidth = 15 + (int)std::to_string(maxSquaredValue).size() - 3;
    
    for (int i = 0; i != maxSquaredValue; ++i){
        int widthAdjustment;
        string integer, square;
        integer = std::to_string(i);
        square = std::to_string((long)std::pow(i,2));
        widthAdjustment = baseWidth - (int)integer.size();
        
        cout << "Integer: " << integer
        << std::setw(widthAdjustment) << " Squared: " << square << std::endl;
    }
}

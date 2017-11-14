// testing stream output width, setw()
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::string;

int main(){
    int maxSquaredValue = 100;
    int baseWidth = 15;
    
    for (int i = 0; i != 101; ++i){
        int widthAdjustment;
        string integer, square;
        integer = std::to_string(i);
        square = std::to_string((int)std::pow(i,2));
        widthAdjustment = baseWidth - (int)integer.size();
        
        cout << "Integer: " << integer
        << std::setw(widthAdjustment) << " Squared: " << square << std::endl;
    }
}

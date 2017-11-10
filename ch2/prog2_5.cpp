//a simple program to draw shapes using '*'

#include <string>
#include <iostream>

using std::cout; using std::cin;
using std::string; using std::endl;

int main(){
    // Ask user what type of shape they would like to 'draw'
    cout << "What type of shape would you like to draw? ('S'::square || 'R'::rectagle || 'T':: triangle) ";
    
    // read inpt
    char shape;
    cin >> shape;
    
    if (shape == 'S'){
        // inquire the desired size
        cout << "Enter side length as a positive integer of \"*\" ";
        int dimension;
        cin >> dimension;
        
        // 'paint' the shape to the terminal
        int rows = dimension;
        int cols = dimension;
        for (int r = 0; r != rows; ++r){
            for (int c = 0; c != cols; ++c){
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
        
    }
    
    if (shape == 'R'){
        // inquire the desired size
        cout << "Enter length as a positive integer of \"*\" ";
        int length;
        cin >> length;
        
        cout << "Enter height as a positive integer of \"*\" ";
        int height;
        cin >> height;
        
        // 'paint' the shape to the terminal
        int rows = height;
        int cols = length;
        for (int r = 0; r != rows; ++r){
            for (int c = 0; c != cols; ++c){
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
    
    if (shape == 'T'){
        // get the leg lengths
        cout << "Enter leg one length as a positive integer of \"*\" ";
        int legOne;
        cin >> legOne;
        cout << "Enter leg two length as a positive integer of \"*\" ";
        int legTwo;
        cin >> legTwo;
        
        // 'paint' the shape to the terminal
        int rows = legOne;
        int cols = legTwo;
        int hypotenusIncrement = legTwo / legOne;
        for (int r = 0; r != rows; ++r){
            for (int c = 0; c != cols; ++c){
                if (r == rows - 1 || c == 0 || (c % hypotenusIncrement == 0 && r * hypotenusIncrement == c - hypotenusIncrement))
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
        
        
    }
    
}

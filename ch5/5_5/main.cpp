// the main program file to play with the framer function
#include <vector>
#include <string>
#include <iostream>
#include "strStuff.h"


using std::cin;      using std::cout;
using std::endl;
using std::string;   using std::vector;


int main() {
    
    cout << "Please enter the pad size: " << endl;
    int padWidth;
    string s;
    read(cin,s);
    padWidth = std::stoi(s);
    cout << "Please enter the \"picture:\" " << endl;
    
    // import the "picture"
    vector<string> thePicture;
    //string s;
    while(read(cin,s)){
        thePicture.push_back(s);
    }
    
    // pad the "picture" with framer
    vector<string> paddedPicture;
    paddedPicture = framer(thePicture, padWidth);
    
    // dislay the newly padded "picture"
    vector<string>::const_iterator iter = paddedPicture.begin();
    while(iter != paddedPicture.end()){
        cout << *iter << endl;
        ++iter;
    }
    
    
    
    
    return 0;
}

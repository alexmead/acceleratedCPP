// permuted index program
// To begin, I'm a little confused on the problem premise,
// but this is my best effort to interpret it.
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "permuted.h"
#include "str.h"

using std::cin;         using std::endl;
using std::cout;        using std::string;
using std::vector;      using std::max;

int numberOfRotationsToPrint = 2;
int positionOfSpace = 2;
typedef vector<string>::const_iterator c_iter;
typedef string::size_type str_size;


int main() {
    
    // read in the input lines
    vector<Input> theInputLines;
    Input in;
    while (getline(cin,in.rawInputLine)) {
        in.inputVector = split(in.rawInputLine);
        theInputLines.push_back(in);
    }
    cout << endl;
    
    //for (vector<string>::size_type i = 0; i != theInputLines.size(); ++i)
    //    cout << theInputLines[i].rawInputLine << endl;
    
    // first get the printable area lenth, i.e. the longest input string
    string::size_type maxLength = 0, currentLength = 0;
    
    for (vector<Input>::const_iterator iter = theInputLines.begin(); iter != theInputLines.end(); ++iter) {
        for (c_iter iter2 = iter->inputVector.begin(); iter2 != iter->inputVector.end(); ++iter2) {
            currentLength += iter2->size() + 1;
        }
        maxLength = max(maxLength,currentLength);
        currentLength = 0;
    }
    
    
    // for each line, build the rotation vector, using iterators
    for (vector<Input>::size_type i = 0; i != theInputLines.size(); ++i) {
        
        vector<string> stringBuilder;
        string::size_type leftPad = 0, rightPad = 0;
        for (c_iter iter = theInputLines[i].inputVector.begin(); iter != theInputLines[i].inputVector.end();++iter) {
            string leftString, rightString;
            str_size lSize=0, rSize=0;
            for (c_iter iter2 = iter; iter2 != theInputLines[i].inputVector.end(); ++iter2)
                leftString += *iter2 + " ";
            lSize = leftString.size();
            cout << string(maxLength - lSize, ' ') << leftString << string(5,' ');
            for (c_iter iter3 = theInputLines[i].inputVector.begin(); iter3 != iter; ++iter3)
                rightString += *iter3 + " ";
            rSize = rightString.size();
            cout << rightString << string(maxLength - rSize, ' ') << endl;
            
            theInputLines[i].inputRotatedVectorVector.push_back(stringBuilder);
            stringBuilder.clear(); // clear vector to restart
            lSize=0;rSize=0;
        }
        cout << string(maxLength + 5,' ');
        for (vector<string>::size_type l = 0; l != theInputLines[i].inputVector.size(); ++l){
            cout << theInputLines[i].inputVector[l] << " ";
        }
        cout << endl;
        
    }
    cout << endl;
    
        return 0;
}


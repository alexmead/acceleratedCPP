// student processor two: uses vectors and indices to extract information

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include "str.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::setprecision;
using std::streamsize;
using std::list;

typedef list<string> lstStr;

int main() {
    
    // read the content in here
    lstStr theWords;
    while(read(cin,theWords)){}
    
    // display words for debugging
    /*
    list<string>::const_iterator it = theWords.begin();
    while (it != theWords.end()){
        cout << *it << endl;
        ++it;
    }
    */
    
    // sort the lists into cap and not cap
    lstStr upperCase;
    upperCase = extract_uppercase(theWords);
    
    cout << "The lowercase words: " << endl;
    list<string>::const_iterator iter = theWords.begin();
    while (iter != theWords.end()){
        cout << *iter << endl;
        ++iter;
    }
    
    
    cout << endl << "The uppercase words: " << endl;
    list<string>::const_iterator iter2 = upperCase.begin();
    while (iter2 != upperCase.end()){
        cout << *iter2 << endl;
        ++iter2;
    }
    
    return 0;
}

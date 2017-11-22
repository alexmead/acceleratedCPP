#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include "pg103.h"


using std::cin;         using std::cout;
using std::string;      using std::vector;
using std::getline;     using std::endl;


int main() {
    
    typedef vector<string>::const_iterator iter;

    
    // import a line
    /*
    string inputLine;
    getline(cin,inputLine);
    
    vector<string> inputLineVector = split(inputLine);
    
    typedef vector<string>::const_iterator iter;
    iter i = inputLineVector.begin();
    while (i != inputLineVector.end()) {
        bool palindrome = is_palindrome(*i);
        cout << *i << ": " << palindrome << endl;
        ++i;
    }
    */
    
    // import a line
    string inputLine;
    getline(cin,inputLine);
    
    // check for url
    vector<string> theURLS;
    theURLS = find_urls(inputLine);
    
    // display any urls found
    iter j = theURLS.begin();
    while (j != theURLS.end()){
        
        cout << *j << endl;
        
        ++j;
    }
    
    return 0;
}

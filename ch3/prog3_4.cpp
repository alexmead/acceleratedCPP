// computer quartiles of an abstract vector
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ios>
#include <string>

using std::cin;    using std::setprecision;
using std::cout;   using std::string;
using std::endl;   using std::streamsize;
using std::sort;   using std::vector;

int main() {
    // ask for the vector of values
    cout << "Enter in a set of words ending with a new line symbol: ";
    
    // read in variables to the vector
    string x;
    vector<string> words;
    
    while (cin >> x) words.push_back(x);
    
    // do some type defining for easier reading of the code
    typedef vector<string>::size_type vec_sz;
    vec_sz wordCount = words.size();
    typedef string::size_type string_sz;
    
    string_sz shortest = 100;// start with this as it is highly unlikely there are no words shorter than this in the input
    string_sz longest = 0;
    int shortIndex = 0;
    int longIndex = 0;
    
    // loop through and check the words for length
    for (int i = 0; i != wordCount; ++i) {
        string_sz size = words[i].size();
        if (size < shortest){
            shortest = size;
            shortIndex = i;
        }
        if (size > longest) {
            longest = size;
            longIndex = i;
        }
        
    }
    
    // Tell the user what you have found regarding word length
    cout << endl << "The short word is of length " << shortest << " and is " << words[shortIndex] << endl;
    cout << "The longest word is of length " << longest << " and is " << words[longIndex] << endl;
    
    return 0;
}

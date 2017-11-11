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
    
    vector<int> wordNumber[wordCount];
    
    // loop through and check the words for length
    for (int i = 0; i != wordCount; ++i) {
        string currentWord = words[i];
        
        for (int j = 0; j != wordCount; ++j) {
            if (i != j && wordCount[j] == currentWord) {
                ++wordNumbe[i];
            }
        }
    }
    
    // check for repeats
    vector<bool> repeat[wordCount];
    vector<int> locationOfRepeat[wordCount];
    
    for (int i = 0; i != wordCount; ++i) {
        string nowWord = words[i];
        for (int j = 0; j != wordCount; ++j) {
            if (i != j && nowWord == words[j]) {
                repeat[i] = true;
                location[i] = j;
            }
                
        }
    }
    
    
    // Tell the user the number of distinct word repeats
    for (int i = 0; i != wordCount; ++i) {
        cout << "word: " <<  words[i] << " count: " << wordNumber[i] << endl;
    }
    
    return 0;
}

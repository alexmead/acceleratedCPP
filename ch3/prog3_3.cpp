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
    
    // loop through and start counting the word counts
    vector<int> wordNumber(wordCount);
    
    for (int i = 0; i != wordCount; ++i) {
        string testWord = words[i];
        for (int j = 0; j != wordCount; ++j) {
            if (testWord == words[j]) {
                ++wordNumber[i];
            }
        }
    }

    vector<string> displayedWords;
    
    // Tell the user the number of distinct word repeats
    for (int i = 0; i != wordCount; ++i) {
        
        if (i ==0) {
        
            cout << "word: " <<  words[0] << " count: " << wordNumber[0] << endl;
            displayedWords.push_back(words[0]);
        
        } else {
            
            bool repeat = false;
            
            for (int j = 0; j != displayedWords.size(); ++j){
                
                if (words[i] == displayedWords[j]) {
                    repeat = true;
                    break;
                }
            }
            if (!repeat){
                cout << "word: " <<  words[i] << " count: " << wordNumber[i] << endl;
                displayedWords.push_back(words[i]);
            }
        }
    }
    
    return 0;
}

// read words and put in vector
// count the total words on input
// frequency of each word on input

#include <string>
#include <vector>
#include <iostream>
#include <istream>
#include <algorithm>
#include "wordStuff.h"
#include <iomanip>
#include <ios>


using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;
//using std::sort;


int main() {
    
    // prompt user to enter word sequence
    cout << "Enter a sequence of words to be analyzed: " << endl;
    
    // read in word prompt
    std::vector<string> inputStreamStrings;
    inputStreamStrings = vecInputStream(std::cin);
    
    // process word prompt
    std::vector<word> rawWords;
    rawWords = countTheWords(inputStreamStrings);
    
    vector<word> unsortedWords;
    unsortedWords = eliminateRepeatWords(rawWords);
    
    //vector<word> sortedList;
    //sortedList = sortWordsAlphabetically(unsortedWords);
    
    sort(unsortedWords.begin(),unsortedWords.end(),compareWordsAlphabetically);
    
    // update because the list is now sorted, I know this is not the most efficient program.c
    vector<word> sortedList = unsortedWords;
    
    // return statists to the user, and I'm adding in alphabetical order
    
    // get longest work input
    string::size_type maxlen = 10;
    for (vector<word>::size_type i = 0; i != sortedList.size(); ++i)
        maxlen = max(maxlen,sortedList[i].syntax.size());
    
    // display the word and count to the user in alphabetical order
    for (vector<word>::size_type i = 0; i != sortedList.size(); ++i) {
        cout << sortedList[i].syntax
        << ":" << string(maxlen + 1 - sortedList[i].syntax.size(), ' ')
        << sortedList[i].number << endl;
    }
    
    return 0;
}

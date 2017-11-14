// vectorizeInputStream() source code file

#include <string>
#include <istream>
#include <iostream>
#include <vector>
#include <algorithm>
#include "wordStuff.h"

using std::vector;
using std::cin;
using std::string;
using std::istream;

bool compareWordsAlphabetically(const word& wordOne,const word& wordTwo){
    
    return wordOne.syntax < wordTwo.syntax;
    
}

std::vector<std::string> vecInputStream( istream& myStream ) {
    
    std::vector<std::string> wordOnStreamVector;
    
    if(myStream) {
        
        // declare vector to hold the words
       
        string holder;
        wordOnStreamVector.clear();
        
        // read in the words on the stream
        while (myStream >> holder) {
            wordOnStreamVector.push_back(holder);
        }
        
        myStream.clear();
        
    }
    
    // return vector to user
    return wordOnStreamVector;
}

std::vector<word> countTheWords(vector<string> wordOnStreamVector){
    // takes a vector of strings each containing a word
    // returns a vector of word objects concerning the work vector input
    
    // Count each word's recurrent number
    std::vector<long long> theWordAmounts(wordOnStreamVector.size());
    
    for (std::vector<word>::size_type i = 0; i != wordOnStreamVector.size(); ++i){
        string currentWord = wordOnStreamVector[i];
        theWordAmounts[i]=0;
        for(vector<word>::size_type j = 0; j != wordOnStreamVector.size(); ++j){
            if (currentWord == wordOnStreamVector[j])
                ++theWordAmounts[i];
        }
    }
    
    // create the holder for each word on the input stream
    std::vector<word> theWords(wordOnStreamVector.size());
    for (std::vector<word>::size_type i = 0; i != wordOnStreamVector.size(); ++i ) {
        theWords[i].syntax = wordOnStreamVector[i];
        theWords[i].number = theWordAmounts[i];
    }
    
    return theWords;
}

std::vector<word> eliminateRepeatWords(std::vector<word> theTotalWords){
    std::vector<word> theOnlyWords;
    
    for (vector<word>::size_type i = 0; i != theTotalWords.size(); ++i) {
        word currentWord = theTotalWords[i];
        if (i == 0) {
            theOnlyWords.push_back(currentWord);
        }
        else {
            bool repeat = false;
            for (vector<word>::size_type j = 0; j != theOnlyWords.size(); ++j) {
                if (currentWord.syntax == theOnlyWords[j].syntax) {
                    repeat = true;
                    break;
                }
            }
            if (!repeat) {
                theOnlyWords.push_back(currentWord);
            }
        }
    }
    return theOnlyWords;
}




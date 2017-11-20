// str.cpp, source file for string manipulation
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "str.h"

using std::string;
using std::vector;
using std::max;
using std::istream;
using std::list;

// splits a string literal of multiple words into a
// vector with each word being an element within it.
vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;
    
    while (i != s.size()) {
        // burn up multiple white spaces which might lead off the input
        while ( i != s.size() && isspace(s[i]))
            ++i;
        
        // First real character, now step j forward
        string_size j = i;
        while (j != s.size() && !isspace(s[j]))
            ++j;
        
        // Assuming progress of at least one character is made, the string is
        // subtracted and push_back() on the vector
        if (i != j) {
            ret.push_back(s.substr(i,j - i));
            i = j;
        }
        
    }
    return ret;
}

typedef vector<string> vecString;
typedef list<string> lstStr;

istream& read(istream& is, lstStr& lstOfStrings)
{
    string s;
    if (!getline(is, s))
        return is;
    else {
        vecString lineInput = split(s);
        for (vecString::size_type i = 0; i != lineInput.size(); ++i){
            lstOfStrings.push_back(lineInput[i]);
        }
        
        return is;
    }
}

lstStr extract_uppercase(lstStr& wordList)
{
    lstStr uppercase;
    
    lstStr::iterator iter = wordList.begin();
    while (iter != wordList.end()){
        
        if(hasCapitals(*iter)){
            
            uppercase.push_back(*iter);
            iter = wordList.erase(iter);
            
        } else {
            
            ++iter;
        
        }
    }
    
    return uppercase;
}

bool hasCapitals(string& word)
{
    for (std::string::const_iterator letter = word.begin(); letter != word.end(); ++letter){
        if(isupper(*letter))
            return true;
    }
    return false;
}








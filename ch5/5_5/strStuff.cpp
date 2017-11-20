#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::istream;


typedef vector<string> vecOfStr;

istream& read(istream& is, string& s)
{
    if (!getline(is, s))
        return is;
    else {
        return is;
    }
}


vector<string> framer(const vector<string>& picture, int padWidth)
{
    
    // get the maximum length line
    vecOfStr::const_iterator line = picture.begin()+1;
    string::size_type maxlen = picture[0].size();
    while (line != picture.end()) {
        maxlen = max(maxlen,line->size());
        ++line;
    }
           
    // to simplify, make max and even number
    
    
           
           vecOfStr thePaddedPicture;
           thePaddedPicture.push_back(string(maxlen+2*padWidth+2, '*'));
           
           string::size_type spaceNeeded, padL, padR;
        
           // loop through each line, add with the needed white spaces on both sides
           // add into the vector
           for(vecOfStr::const_iterator line = picture.begin(); line != picture.end(); ++line){
               // how wide is the current line?
               spaceNeeded = maxlen - line->size();
               // build up the needed spacing
               if (spaceNeeded % 2 == 0)
                   padL = padR = spaceNeeded / 2;
               else {
                   padL = (spaceNeeded - 1) / 2;
                   padR = padL + 1;
               }
               // construct and push_back() the new padded line
               string newLine = "*" + string(padWidth+padL, ' ') + *line + string(padR+padWidth,' ') + "*";
               thePaddedPicture.push_back(newLine);
               
           }
           
           thePaddedPicture.push_back(string(maxlen+2*padWidth+2, '*'));

    return thePaddedPicture;
}

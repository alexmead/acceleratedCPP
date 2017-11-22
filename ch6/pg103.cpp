#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "pg103.h"


using std::isspace;
using std::vector;
using std::string;
using std::find_if;
using std::equal;

// true if the argument is whitespace, false otherwise
bool space(char c)
{
    return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c)
{
    return !isspace(c);
}

// On page 104, the authors explain the functions 'space' and
// 'not_space' are needed as containers because else the compiler
// won't know what type of "isspace()" from the standard library
// we want, because we haven't given any arugments yet to the
// variables on which that is called, they are only iterator to
// a string, hence they could be wchar_t and not just char.


// the new split
vector<string> split(const string& str)
{
    typedef string::const_iterator iter;
    vector<string> ret;
    
    iter i = str.begin();
    while (i != str.end()) {
        // ignore beginning blanks
        i = find_if(i, str.begin(), not_space);
        // find end of next word
        iter j = find_if(i, str.end(),space);
        
        if (i != str.end())
            ret.push_back(string(i,j));
        i = j;
        
    }
    return ret;
}

bool is_palindrome(const string& s)
{
    return equal(s.begin(),s.end(),s.rbegin());
}

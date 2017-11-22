#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cctype>
#include "pg103.h"


using std::isspace;
using std::vector;
using std::string;
using std::find_if;
using std::equal;
using std::isalnum;
using std::isalpha;
using std::find;
using std::search;


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

bool not_url_char(char c)
{
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";
    
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(),c) != url_ch.end());
}


string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
    return find_if(b,e,not_url_char);
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
    
    static const string sep = "://";
    
    typedef string::const_iterator iter;
    
    iter i = b;
    
    while ((i = search(i, e, sep.begin(), sep.end())) != e) {
        
        if (i != b && i + sep.size() != e){
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;
            
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }
        
        i += sep.size();
    }
           return e;
}
           

vector<string>find_urls(const string& s)
{
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();
    
    while (b != e) {
        
        b = url_beg(b,e);
        
        if (b != e) {
            iter after = url_end(b,e);
            
            ret.push_back(string(b,after));
            
            b = after;
        }
    }
    return ret;
}























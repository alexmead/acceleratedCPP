// str.cpp, source file for string manipulation
#include <string>
#include <vector>
#include <algorithm>
#include "str.h"

using std::string;
using std::vector;
using std::max;

string::size_type width(const vector<string>& v)
{
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i){
        maxlen = max(maxlen,v[i].size());
    }
    return maxlen;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');
    
    ret.push_back(border);
    
    for (vector<string>::size_type i = 0; i != v.size(); ++i) {
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");
    }
    
    ret.push_back(border);
    
    return ret;
}

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
    vector<string> ret = top;
    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
        ret.push_back(*it);
    
    return ret;
    // ret.insert(ret.end(), bottom.begin(), bottom.end());
}

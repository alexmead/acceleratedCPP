#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::string;



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
        while (j != s.size() && !isspace(s[i]))
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

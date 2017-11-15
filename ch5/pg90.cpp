#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;



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


int main() {
    
    string s;
    
    // read input
    while (getline(cin,s)) {
        vector<string> v = split(s);
        
        for (vector<string>::size_type i = 0; i != v.size(); ++i){
            cout << v[i] << endl;
        }
    }
    return 0;
}

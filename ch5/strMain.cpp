// playing with picture cat and boarding

#include <string>
#include <vector>
#include <iostream>
#include "str.h"

using std::cin;
using std::cout;
using std::endl;
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
        
        cout << endl;
        
        for (vector<string>::size_type i = 0; i != v.size(); ++i){
            cout << v[i] << endl;
        }
        cout << endl << endl;
        // frame the words
        vector<string> framed_v = frame(v);
        
        for (vector<string>::size_type i = 0; i != framed_v.size(); ++i) {
            cout << framed_v[i] << endl;
        }
        
        cout << endl << endl;
        // frame the words
        vector<string> vcat_v = vcat(v, framed_v);
        
        for (vector<string>::size_type i = 0; i != vcat_v.size(); ++i) {
            cout << vcat_v[i] << endl;
        }
        
        cout << endl << endl;
        // frame the words
        vector<string> hcat_v = hcat(v, framed_v);
        
        for (vector<string>::size_type i = 0; i != hcat_v.size(); ++i) {
            cout << hcat_v[i] << endl;
        }
        
    }
    
    
    
    
    
    return 0;
}

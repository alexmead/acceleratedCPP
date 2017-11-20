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

int main() {
    
    string s;
    
    // read input
    while (getline(cin,s)) {
        
        vector<string> v = split(s);
        
        cout << endl;
        
        /*
        for (vector<string>::size_type i = 0; i != v.size(); ++i){
            cout << v[i] << endl;
        }
        cout << endl << endl;
         */
        
        //vector<string> v;
        // frame the words
        vector<string> framed_v = frame(v);
        
        for (vector<string>::size_type i = 0; i != framed_v.size(); ++i) {
            cout << framed_v[i] << endl;
        }
        
        /*
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
         */
        
    }
    
    
    
    
    
    return 0;
}

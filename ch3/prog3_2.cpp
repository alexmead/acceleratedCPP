// computer quartiles of an abstract vector
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ios>
#include <string>

using std::cin;    using std::setprecision;
using std::cout;   using std::string;
using std::endl;   using std::streamsize;
using std::sort;   using std::vector;

int main() {
    // ask for the vector of values
    cout << "Enter all the vector values (doubles) followed by end-of-file: ";
    
    // read in variables to the vector
    double x;
    vector<double> homework;
    
    while (cin >> x) homework.push_back(x);
    
    // vector size is stored for multiple uses in this scope
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    
    // check min size
    if (size < 4) {
        cout << endl << "Your vector must be at least 4 double long as we are displaying the quartiles." << endl;
        return 1;
    }
    
    // sort the vector of grades in non-decreasing order
    sort(homework.begin(),homework.end());
    
    // define some nice text to show the user
    //vector<string> quads[] = { "1st quartile:", "2nd quartile:", "3rd quartile:", "4th quartile:" };
    
    for (int i = 0; i < 4; ++i) {
        cout << "Quartile " << i+1 << ":" << endl;
        for (int j = i*size/4; j < (i+1)*size/4; ++j) {
            cout << homework[j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

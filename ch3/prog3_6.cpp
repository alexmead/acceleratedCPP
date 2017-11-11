// This question is odd as the problem was already addressed in the nexter iteration of
// this program, presented in full on pace 46 and 47. Here, to account for a possible 0
// length entry, we do a check and simply return '1', indicating an error, to the
// implementation.  I played around with another example using my Mac (Yosemite) and
// determined my implementation will return a 'nan' value if I did by 0.


// I see it now, the check for zero length is actually on the median calculating version,
// hence it is somewhat helpful to rethink the question with respect to the average calculating
// version of the program as well.




// first pass at grade calculator, uses a vector allowing for the computation of the median
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;    using std::setprecision;
using std::cout;   using std::string;
using std::endl;   using std::streamsize;
using std::sort;   using std::vector;

int main(){
    // ask for and read students first name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    
    // ask for and read in, MT, Final grade
    cout << "Please end your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;
    
    // ask for HW grades
    cout << "Enter all your HW grades, "
            "followed by end-of-file: ";
    
    // read in variable
    double x;
    vector<double> homework;
    
    // invarient: count grades read, sum is total summation of those grades so far
    while (cin >> x) {
        homework.push_back(x);
    }
    
    // vector size is stored for multiple uses in this scope
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    
    // check for 0 length hw vector
    if (size == 0) {
        cout << endl << "You must enter your grades. Please try again. " << endl;
        //return 1;
    }
    
    // calculate average machinery
    int count = 0;
    double sum = 0;
    for (int i = 0; i != size; ++i) {
        ++count;
        sum += homework[i];
    }
    
    // write results
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) << endl;
    
    return 0;
}

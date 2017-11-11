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
        return 1;
    }
    
    // sort the vector of grades in non-decreasing order
    sort(homework.begin(),homework.end());
    
    //find middle element(s)
    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];
    
    // write results
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;
    
    return 0;
}

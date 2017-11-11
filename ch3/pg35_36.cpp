// first pass at grade calculator
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;    using std::setprecision;
using std::cout;   using std::string;
using std::endl;   using std::streamsize;

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
    
    // number and sum of grades read so far
    int count =0;
    double sum = 0;
    
    // read in variable
    double x;
    
    // invarient: count grades read, sum is total summation of those grades so far
    while (cin >> x) {
        ++count;
        sum += x;
    }
    
    // write results
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(prec) << endl;
    
    return 0;
}

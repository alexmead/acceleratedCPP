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

typedef vector<double>::size_type vec_sz;
typedef vector<string>::size_type vec_str_sz;

int main(){
    
    
    
    vector<string> studentNames;
    vector<double> studentGrades;
    bool anotherStudent = true;
    
    while (anotherStudent) {
        // ask for the student name;
        cout << "Please enter your name: ";
        string currentName;
        cin >> currentName;
        studentNames.push_back(currentName);
        
        // ask the student to enter their grades
        // ask for and read in, MT, Final grade
        cout << "Please enter your midterm and final exam grades: ";
        double m, f;
        cin >> m >> f;
        // ask for homework grades
        cout << "Please enter your homework grades followed by end-of-file: ";
        double x;
        vector<double> homeworkTemp;
        // assume 4 homework grades
        // invarient: count grades read, sum is total summation of those grades so far
        for (int i = 0; i != 4; ++i){
            cin >> x;
            homeworkTemp.push_back(x);
        }
        
        // vector size is stored for multiple uses in this scope

        vec_sz size = homeworkTemp.size();
        
        // check for 0 length hw vector
        if (size == 0) {
            cout << endl << "You must enter your grades. Please try again. " << endl;
            return 1;
        }
        
        // calculate homework average
        int count = 0;
        double sum = 0;
        for (int i = 0; i != size; ++i){
            ++count;
            sum += homeworkTemp[i];
        }
        
        // calculate the student's total grade
        studentGrades.push_back(0.2 * m + 0.4 * f + 0.4 * sum / count);
        
        // check in there is another student
        cout << "Another student? (yes/no): " << endl;
        string answer;
        cin >> answer;
        if (answer == "yes"){
            anotherStudent = true;
        } else {
            anotherStudent = false;
        }
    }
    
    
    // Print the student names and grades
    vec_str_sz studentNumber = studentNames.size();
    for (int i = 0; i != studentNumber; ++ i) {
        cout << endl << "name: " << studentNames[i] << "    grade: " << studentGrades[i];
    }
    
    
    
    
    
    
    return 0;
}

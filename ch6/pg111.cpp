// the main() for the student grading example
#include <vector>
#include <iostream>
#include "student_info.h"

using std::cin;      using std::cout;
using std::vector;   using std::endl;


int main(){
    
    // student vectors who did and didn't do all the hws
    vector<Student_info> did, didnt;
    
    // read in the student records
    Student_info student;
    while (read(cin,student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }
    
    //check both groups contain data
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    } else {
        cout << endl << "Number of students who did all hw: " << did.size() << endl;
    }
        
    if (didnt.empty()) {
        cout << "Every Student did all the homework!" << endl;
        return 1;
    } else {
        cout << endl << "Number of students who didn't all hw: " << didnt.size() << endl << endl;
    }
    
    // do the analysis
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    write_analysis(cout, "median of homeword turned in", optimistic_median_analysis, did, didnt);
    
    return 0;
}

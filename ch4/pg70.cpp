#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "grade.h"
#include "Student_info.h"

using std::cin;          using std::setprecision;
using std::cout;         using std::sort;
using std::domain_error; using std::streamsize;
using std::endl;         using std::string;
using std::max;          using std::vector;

int main()
{
    // vector of student infor
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // read and store student information
    while (read(cin,record)) {
        maxlen = max(maxlen,record.name.size());
        students.push_back(record);
    }
    
    // alphabetical sort
    sort(students.begin(),students.end(),compare);
    
    // write names and grades to standar out.
    for (vector<Student_info>::size_type i = 0; i != students.size();++i) {
        cout << students[i].name
        << string(maxlen + 1 - students[i].name.size(), ' ');
        
        // compute and generate the final grade if possible
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3)
            << final_grade << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    
    return 0;
    
    
}

// student processor two: uses vectors and indices to extract information

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <list>
#include "Student_info.h"

using std::list
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::setprecision;
using std::streamsize;

int main() {
    std::clock_t t_start = std::clock();
    // vector of student infor
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;  // longest name, needed for spacing purposes
    
    // read and store student information
    while (read(cin,record)) {
        maxlen = max(maxlen,record.name.size());
        students.push_back(record);
    }
    
    
    // vector methods to seperate failures
    list<Student_info> fails;
    fails = extract_fails(students);
    
    
    /*
    streamsize prec = cout.precision();
    cout << endl << "Vector based erase took: " << setprecision(3) << ((end - start) / CLOCKS_PER_SEC) << setprecision(prec) << " seconds\n";
    */
    /*
    // display the passing then failing
    cout << endl << "Passing Students: " << endl;
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name << " " << students[i].grade << endl;
    }
    
    cout << endl << "Failing Students: " << endl;
    for (vector<Student_info>::size_type i = 0; i != fails.size(); ++i) {
        cout << fails[i].name << " " << fails[i].grade << endl;
    }
    */
    cout << "Time taken: " << (double)(std::clock()-t_start)/CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}

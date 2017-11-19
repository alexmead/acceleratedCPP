// student processor two: uses vectors and indices to extract information

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>
#include <ctime>
#include "Student_info.h"

using std::vector;
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::setprecision;
using std::streamsize;


typedef vector<Student_info> theStudents;
//typedef list<Student_info> theStudents;


int main(int argc, char *argv[]) {
    
    // The code below allows you to change the structure at run time, however, I'm
    // pretty sure is not what actually happens, because the compiler has already
    // commited to the vector or list type. Playing around with timing seems to agree
    // with this conclusion because the vector type is much longer than the  list type.
    // Uncomment and play around with it yourself!
    /*
    typedef list<Student_info> theStudents;
    
    if (*argv[1] == 1){
        typedef vector<Student_info> theStudents;
    } else {
        typedef list<Student_info> theStudents;
    }
    */
    std::clock_t t_start = std::clock();
    // vector of student infor
    theStudents students;
    Student_info record;
    string::size_type maxlen = 0;  // longest name, needed for spacing purposes
    
    // read and store student information
    while (read(cin,record)) {
        maxlen = max(maxlen,record.name.size());
        students.push_back(record);
    }
    
    theStudents::size_type studNum = students.size();
    
    
    // vector methods to seperate failures
    theStudents fails;
    fails = extract_fails_iterator(students);
    
    
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
    //cout << "Time taken: " << (double)(std::clock()-t_start)/CLOCKS_PER_SEC << " seconds" << endl;
    
    cout << "Vector length,"<< studNum <<", time taken: " << (double)(std::clock()-t_start)/CLOCKS_PER_SEC << " seconds" << endl;
    
    return 0;
}

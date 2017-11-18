// source file for Student_info - related functions
#include "Student_info.h"

using std::istream;
using std::vector;
using std::cin;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final; // s.x references change the origanl data structure, pass-by-reference
    
    read_hw(is, s.homework); // read and store all the student's hw grades
    
    return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
    if (in){
        // get rid of previous contents
        hw.clear();
        
        // read in hw grades
        double x;
        while (cin >> x)
            hw.push_back(x);
        
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> pass, fail;
    
    for(vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        if (fgrade(students[i]))
            fail.push_back(students[i]);
        else
            pass.push_back(students[i]);
    }
    students = pass;
    return fail;
}

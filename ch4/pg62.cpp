#include <string>
#include <vector>
#include <iostream>


struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
}; // note semicolon, it's required.

istream* read(istream& is, Student_info& ss)
{
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final; // s.x references change the origanl data structure, pass-by-reference
    
    read_hw(is, s.homework); // read and store all the student's hw grades
    return is;
}

double grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

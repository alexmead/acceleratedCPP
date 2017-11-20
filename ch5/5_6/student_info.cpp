// source file for Student_info - related functions
#include <list>
#include <vector>
#include <string>
#include "Student_info.h"
#include "grade.h"
#include "str.h"

using std::istream;
using std::vector;
using std::cin;
using std::list;
using std::string;


bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    string inputLine; // holds the input
    if (!getline(is, inputLine))// takes input from stdin
        return is;
    vector<string> inputVector;
    inputVector = split(inputLine); // split along spaces
    s.name =inputVector[0];
    s.midterm = stod(inputVector[1]);
    s.final = stod(inputVector[2]);
    
    for(vector<string>::size_type i = 3; i != inputVector.size(); ++i) {
        s.homework.push_back(stod(inputVector[i]));
    }
    double finalGrade;
    finalGrade = grade(s);
    s.grade = finalGrade;
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
    
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        if (fgrade(students[i]))
            fail.push_back(students[i]);
        else {
            fail.push_back(students[i]);
        }
    }
    students = pass;
    return fail;

}

vector<Student_info> extract_fails2(vector<Student_info>& students)
{
    vector<Student_info> fail;
    vector<Student_info>::size_type i = 0;
    
    while (i != students.size()) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        } else {
            ++i;
        }
    }
    return fail;
}

vector<Student_info> extract_fails_iterator(vector<Student_info>& students)
{
    
    vector<Student_info> fail;
    vector<Student_info>::size_type numPassStuds = 0, position = 0;
    
    while ((numPassStuds + position) != students.size()) {
        if (fgrade(students[position+numPassStuds])) {
            fail.push_back(students[position+numPassStuds]);
             // returns the iterator right after the one which was just deleted.
            ++position;
        } else {
            students.insert(students.begin(),students[position+numPassStuds]);
            ++numPassStuds;
            ++position;
        }
    }
    // trim the students vector to size
    students.resize(numPassStuds);
    return fail;
}

// overload extract_fails_iterator
list<Student_info> extract_fails_iterator(list<Student_info>& students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
    
    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter); // returns the iterator right after the one which was just deleted.
        } else {
            ++iter;
        }
    }
    return fail;
}

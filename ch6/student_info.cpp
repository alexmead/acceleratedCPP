// source file for Student_info - related functions
#include <list>
#include <numeric>
#include <algorithm>
#include <ostream>
#include <istream>
#include "Student_info.h"
#include "median.h"
#include "grade.h"
#include "str.h"

using std::istream;
using std::ostream;
using std::vector;
using std::cin;
using std::cout;
using std::transform;
using std::accumulate;
using std::domain_error;
using std::string;
using std::endl;

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
bool did_all_hw(const Student_info& s)
{
    return ((find(s.homework.begin(),s.homework.end(),0)) == s.homework.end());
}


double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm,s.final,0);
    }
}

double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(),students.end(),back_inserter(grades),grade_aux);
    
    return median(grades);
}

double average(const vector<double>& v)
{
    return accumulate(v.begin(),v.end(),0.0)/v.size();
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm,s.final,average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(),students.end(),back_inserter(grades),average_grade);
    
    return median(grades);
}

double optimistic_median(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(),s.homework.end(),back_inserter(nonzero),0);
    
    if (nonzero.empty())
        return grade(s.midterm,s.final,0);
    else
        return grade(s.midterm,s.final,median(s.homework));
    
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    
    transform(students.begin(),students.end(),back_inserter(grades),optimistic_median);
    
    return median(grades);
}

void write_analysis(ostream& out, const string& name, double analysis(const vector<Student_info>&), const vector<Student_info>& did, const vector<Student_info>& didnt)
{
    cout << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}



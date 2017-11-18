// source file for Student_info - related functions
#include "student_info_2.h"
#include "median.h"
#include <stdexcept>
#include <algorithm>

using std::istream;
using std::vector;
using std::cin;
using std::domain_error;
using std::sort;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    typedef vector<double>::size_type vec_sz;
    
    double md, fl;
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> md >> fl; // s.x references change the origanl data structure, pass-by-reference
    
    //std::cout << std::endl << s.name << std::endl;
    
    vector<double> homework;
    if (is){
        homework.clear();
    
    double loader;
    while (cin >> loader)
        homework.push_back(loader);
    is.clear();
    }
    //read_hw(is, hwPt); // read and store all the student's hw grades
    double hold;
    
    vec_sz size = homework.size();
    
    std::cout << "vector size: " << size << std::endl;
    
    if (size == 0)
        throw domain_error("median of an empty vector");
    sort(homework.begin(),homework.end());
    
    vec_sz mid = size/2;
    
    double med = size % 2 ? (homework[mid] + homework[mid-1]) / 2 : homework[mid];

    
    hold = 0.2 * md + 0.4 * fl + 0.4 * med;
    std::cout << "the grad: " << hold << std::endl;
    s.aNumber = hold;
    
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

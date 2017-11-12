// first pass at grade calculator, uses a vector allowing for the computation of the median
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;      using std::setprecision;
using std::cout;     using std::string;
using std::endl;     using std::streamsize;
using std::sort;     using std::vector;
using std::iostream; using std::domain_error;
using std::istream;  using std::max;

double median(vector<double> vec)
{
    
    typedef vector<double>::size_type vec_sz;
    
    vec_sz size = vec.size();
    if (size == 0)
        throw domain_error("median of an empty vector");
    sort(vec.begin(),vec.end());
    
    vec_sz mid = size/2;
    
    return size % 2 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
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

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
}; // note semicolon, it's required.

istream& read(istream& is, Student_info& s)
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


int main(){
    // vector of student infor
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    
    // read and store student information
    while (read(cin,record)) {
        maxlen = max(maxlen,record.name.size());
        students.push_back(record);
    }
    
    sort(students.begin(),students.end(),compare);
    
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

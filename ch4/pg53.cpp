// the beginning of the function definition

#include <vector>
#include <stdexcept>
#include <iostream>

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
    if (hw.size == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

iostream& read_hw(iostream& in, vector<double>& hw)
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

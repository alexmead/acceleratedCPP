#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include <iostream>
#include <string>
#include <vector>
#include <list>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);
std::vector<Student_info> extract_fails2(std::vector<Student_info>&);
std::vector<Student_info> extract_fails_iterator(std::vector<Student_info>&);
std::vector<Student_info> extract_fails_iterator(std::list<Student_info>&);
#endif

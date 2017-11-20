#ifndef GUARD_string_h
#define GUARD_string_h

#include <string>
#include <vector>
#include <algorithm>
#include <istream>
#include <list>

std::vector<std::string> split(const std::string&);
std::istream& read(std::istream&, std::list<std::string>&);
std::list<std::string> extract_uppercase(std::list<std::string>&);
bool hasCapitals(std::string&);

#endif

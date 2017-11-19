#ifndef GUARD_string_h
#define GUARD_string_h

#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> split(const std::string&);
std::string::size_type width(const std::vector<std::string>&);
std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> vcat(const std::vector<std::string>&,const std::vector<std::string>&);
std::vector<std::string> hcat(const std::vector<std::string>&,const std::vector<std::string>&);

#endif

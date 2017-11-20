#ifndef GUARD_strStuff_h
#define GUARD_strStuff_h

// strStuff.h - some functions for doing stuff with picture
#include <vector>
#include <string>
#include <iostream>

std::istream& read(std::istream&, std::string&);
std::vector<std::string> framer(const std::vector<std::string>&, int);

#endif

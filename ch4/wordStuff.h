#ifndef wordStuff_h
#define wordStuff_h

// wordStuff.h header file

#include <string>
#include <istream>
#include <vector>

struct word {
  std::string syntax;
  long long number;
  };

std::vector<std::string> vecInputStream(std::istream&);
std::vector<word> countTheWords(std::vector<std::string>);
std::vector<word> eliminateRepeatWords(std::vector<word>);
bool compareWordsAlphabetically(const word&, const word&);

#endif /* wordStuff_h */

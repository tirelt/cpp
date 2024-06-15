#ifndef UTILS_H
#define UTILS_H
#include <string>
std::string& replace_in_substring(std::string& s,unsigned pos1,unsigned pos2, const char old_c = ',', const char new_c = '-');
#endif
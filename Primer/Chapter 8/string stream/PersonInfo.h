#ifndef PERSON_INFO_H
#define PERSON_INFO_H

#include <string>
#include <vector>

// members are public by default; see § 7.2 (p. 268)
struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

#endif
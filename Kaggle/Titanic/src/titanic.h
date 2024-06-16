#ifndef TITANIC_H
#define TITANIC_H

#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>

#include "passenger.h"

class Titanic{
    public:
        Titanic()=delete;
        Titanic(std::istream& in);
        Passenger& get(int i) {
            return *passengers[i];
        }
        std::map<std::string,std::pair<unsigned,unsigned>> stat_sex;
    private:
        std::vector<std::shared_ptr<Passenger>> passengers;
        
};

#endif
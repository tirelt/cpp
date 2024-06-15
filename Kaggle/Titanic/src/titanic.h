#ifndef TITANIC_H
#define TITANIC_H

#include <iostream>
#include <vector>
#include <memory>

#include "passenger.h"

class Titanic{
    public:
        Titanic()=delete;
        Titanic(std::istream& in);
        Passenger& get(int i) {
            return *passengers[i];
        }
    private:
        std::vector<std::shared_ptr<Passenger>> passengers;
};

#endif
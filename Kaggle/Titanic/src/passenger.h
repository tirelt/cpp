#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>

class Passenger{
        //using LineTypePtr = tuple<unsigned Passenger::*, bool Passenger::*, unsigned Passenger::*,string Passenger::*,string Passenger::*,unsigned Passenger::*,unsigned Passenger::*,
        //    unsigned Passenger::*,string Passenger::*,double Passenger::*,string Passenger::*,string Passenger::*>;
        //Passenger()=default;
        //Passenger(string& line);
        //enum Features {PASSENGERID,SURVIVED,pClass,name,sex,age,sibSp,parch,ticket,fare,cabin,embarked};
        //template<typename T> void set(Features f, T value);      
    
    public:
        Passenger();
        Passenger(const Passenger&);
        //Passenger(Passenger&&);

        unsigned passengerId;
        bool survived;
        unsigned pClass;
        std::string name;
        std::string sex;
        unsigned age;
        unsigned sibSp;
        unsigned parch;
        std::string ticket;
        double fare;
        std::string cabin;
        std::string embarked;
};

#endif
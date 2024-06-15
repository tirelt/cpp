#include <string>
#include "passenger.h"

Passenger::Passenger(){
    passengerId = 0;
    survived = 0;
    pClass = 0;
    name = " ";
    sex = " ";
    age = 0;
    sibSp = 0;
    parch = 0;
    ticket = " ";
    fare = 0;
    cabin= " ";
    embarked = " ";
}
Passenger::Passenger(const Passenger& p){
        passengerId = p.passengerId;
        survived = p.survived;
        pClass = p.pClass;
        name = p.name;
        sex = p.sex;
        age = p.age;
        sibSp = p.sibSp;
        parch = p.parch;
        ticket = p.ticket;
        fare = p.fare;
        cabin= p.cabin;
        embarked = p.embarked;
}
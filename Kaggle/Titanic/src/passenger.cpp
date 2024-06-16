#include <string>
#include <iostream>
#include <vector>
#include "passenger.h"
#include "utils.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

Passenger::Passenger(string& line){

    auto start_name = line.find('"');
    auto end_name = line.rfind('"');
    string name(line,start_name,end_name-start_name+1);
    replace_in_substring(line,start_name,end_name);
    line.erase(start_name,1);
    line.erase(end_name-1,1);

    vector<string> values = split_line(line);

    if( values.size() != 12 )
        throw std::runtime_error("Line doesn't have 12 elements");    
    
    try{
    passengerId = values[0].empty()?0:stoi(values[0]);
    survived = values[1].empty()?0:stoi(values[1]);;
    pClass = values[2].empty()?0:stoi(values[2]);;
    fullName = values[3];
    sex = values[4];
    age = values[5].empty()?0:stoi(values[5]);;
    sibSp = values[6].empty()?0:stoi(values[6]);;
    parch = values[7].empty()?0:stoi(values[7]);;
    ticket = values[8];
    fare = values[9].empty()?0:stod(values[9]);;
    cabin = values[10];
    embarked = values[11];
    } catch(...) {
        cout << line << endl;
        throw;
    }
};

void Passenger::print(){
    cout << "passengerId: " << passengerId << endl;
    cout << "survived:    " << survived << endl;
    cout << "pClass:      " << pClass << endl;
    cout << "fullName:    " << fullName << endl;
    cout << "sex:         " << sex << endl;
    cout << "age:         " << age << endl;
    cout << "sibSp:       " << sibSp << endl;
    cout << "parch:       " << parch << endl;
    cout << "ticket:      " << ticket << endl;
    cout << "fare:        " << fare << endl;
    cout << "cabin:       " << cabin << endl;
    cout << "embarked:    " << embarked << endl;

}
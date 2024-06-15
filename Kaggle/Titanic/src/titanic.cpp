#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <tuple>
#include <vector>
#include <memory>

#include "utils.h"
#include "passenger.h"
#include "titanic.h"

using std::ifstream;
using std::istringstream;
using std::cout;
using std::endl;
using std::string;
using std::tuple;
using std::make_tuple;
using std::get;
using std::vector;
using std::istream;
using std::make_shared;
using std::shared_ptr;

Titanic::Titanic(istream& train){
    string line,entry;
    if(!getline(train,line)){
        throw std::runtime_error("empty file");
    }
    while(getline(train,line)){

        auto start_name = line.find('"');
        auto end_name = line.rfind('"');
        string name(line,start_name,end_name-start_name+1);
        replace_in_substring(line,start_name,end_name);
        string entry;
        istringstream ss(line);
        shared_ptr<Passenger> ptr(new Passenger);
    
        getline(ss,entry,',');
        ptr->passengerId = stoi(entry);
    
        getline(ss,entry,',');
        ptr->survived = stoi(entry);

        getline(ss,entry,',');
        ptr->pClass = stoi(entry);

        getline(ss,entry,',');
        ptr->name = entry;

        getline(ss,entry,',');
        ptr->sex = entry;

        getline(ss,entry,',');
        ptr->age = stoi(entry);

        getline(ss,entry,',');
        ptr->sibSp = stoi(entry);

        getline(ss,entry,',');
        ptr->parch = stoi(entry);

        getline(ss,entry,',');
        ptr->ticket = entry;

        getline(ss,entry,',');
        ptr->fare = stod(entry);

        getline(ss,entry,',');
        ptr->cabin = entry;

        getline(ss,entry,',');
        ptr->embarked = entry;
        
        passengers.push_back(ptr);
        //cout << p.passengerId <<  p.survived  << p.pClass << p.name <<p.sex <<p.age <<p.sibSp <<p.parch <<p.ticket <<p.fare <<p.cabin <<p.embarked<<endl;
    }

}
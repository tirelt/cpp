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
using std::make_pair;

Titanic::Titanic(istream& train){
    string line,entry;
    if(!getline(train,line)){
        throw std::runtime_error("empty file");
    }
    while(getline(train,line)){
        shared_ptr<Passenger> ptr(new Passenger(line));
        passengers.push_back(ptr);
        if (!(ptr->sex).empty())
            stat_sex[ptr->sex].first += ptr->survived?1:0;
            stat_sex[ptr->sex].second += 1;
        //cout << p.passengerId <<  p.survived  << p.pClass << p.name <<p.sex <<p.age <<p.sibSp <<p.parch <<p.ticket <<p.fare <<p.cabin <<p.embarked<<endl;
    }

}
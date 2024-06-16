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
        
        obs+=1;
        unsigned has_survived = ptr->survived?1:0;
        survived+=has_survived;

        if(ptr->pClass){
            stat_pClass[ptr->pClass].first += has_survived;
            stat_pClass[ptr->pClass].second += 1;
        }
        if (!(ptr->sex).empty()){
            stat_sex[ptr->sex].first += has_survived;
            stat_sex[ptr->sex].second += 1;
        }
        if(ptr->age){
            stat_age[ptr->age].first += has_survived;
            stat_age[ptr->age].second += 1;
        }
        stat_sibSp[ptr->sibSp].first += has_survived;
        stat_sibSp[ptr->sibSp].second += 1;
       
        stat_parch[ptr->parch].first += has_survived;
        stat_parch[ptr->parch].second += 1;
        
        if(ptr->fare){
            stat_fare[ptr->fare].first += has_survived;
            stat_fare[ptr->fare].second += 1;
        }
        if(!(ptr->cabin).empty()){
            stat_cabin[ptr->cabin].first += has_survived;
            stat_cabin[ptr->cabin].second += 1;
        }
        if(!(ptr->embarked).empty()){
            stat_embarked[ptr->embarked].first += has_survived;
            stat_embarked[ptr->embarked].second += 1;
        }
        //cout << p.passengerId <<  p.survived  << p.pClass << p.name <<p.sex <<p.age <<p.sibSp <<p.parch <<p.ticket <<p.fare <<p.cabin <<p.embarked<<endl;
    }
}



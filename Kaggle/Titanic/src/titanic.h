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
        template <typename T> void show_stat(std::map<T,std::pair<unsigned,unsigned>>& stat,std::ostream& out = std::cout);

        unsigned survived;
        unsigned obs;

        std::map<unsigned,std::pair<unsigned,unsigned>> stat_pClass;
        std::map<std::string,std::pair<unsigned,unsigned>> stat_sex;
        std::map<double,std::pair<unsigned,unsigned>> stat_age;
        std::map<unsigned,std::pair<unsigned,unsigned>> stat_sibSp;
        std::map<unsigned,std::pair<unsigned,unsigned>> stat_parch;
        std::map<double,std::pair<unsigned,unsigned>> stat_fare;
        std::map<std::string,std::pair<unsigned,unsigned>> stat_cabin;
        std::map<std::string,std::pair<unsigned,unsigned>> stat_embarked;

        std::vector<std::shared_ptr<Passenger>> passengers;
};


template <typename T>
void Titanic::show_stat(std::map<T,std::pair<unsigned,unsigned>>& stat, std::ostream& out){
    int total_obs(passengers.size());int obs(0);
    for(auto p: stat){
        obs += p.second.second;
    } 
    out << "obs: " << obs << " - %" << double(obs)/total_obs*100 << std::endl;
    for(auto p: stat){
        out << p.first << " / survived: %"<< double(p.second.first)/p.second.second*100 << " / obs %" << double(p.second.second) / obs*100<< std::endl;
    }
}
#endif
#include <iostream>
#include <fstream>
#include <map>

#include "utils.h"
#include "passenger.h"
#include "titanic.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::map;


int main(){
    //ifstream train("data/train_test.csv");
    ifstream train("data/train.csv");
    Titanic t(train);
    ofstream out("stats/stats");
    //Passenger p = t.get(1);
    //p.print();

    cout << "Obs: " << t.passengers.size() << endl;
    
    //Sex
    out << "stat_sex: " << endl;
    t.show_stat(t.stat_sex,out);
    out << " " << endl;
    out << "stat_pClass: " << endl;
    t.show_stat(t.stat_pClass,out);
    out << " " << endl;
    out << "stat_sibSp: " << endl;
    t.show_stat(t.stat_sibSp,out);
    out << " " << endl;
    out << "stat_parch: " << endl;
    t.show_stat(t.stat_parch,out);
    out << " " << endl;
    out << "stat_cabin: " << endl;
    t.show_stat(t.stat_cabin,out);
    out << " " << endl;
    out << "stat_embarked: " << endl;
    t.show_stat(t.stat_embarked,out);
    out << " " << endl;
    out << "stat_age: " << endl;
    t.show_stat(t.stat_age,out);
    out << " " << endl;
    return 0;
}
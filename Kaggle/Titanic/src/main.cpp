#include <iostream>
#include <fstream>

#include "utils.h"
#include "passenger.h"
#include "titanic.h"

using std::cout;
using std::endl;
using std::ifstream;

int main(){
    //ifstream train("data/train_test.csv");
    ifstream train("data/train.csv");
    Titanic t(train);
    //Passenger p = t.get(1);
    //p.print();
    //cout << p.passengerId <<  p.survived  << p.pClass << p.name <<p.sex <<p.age <<p.sibSp <<p.parch <<p.ticket <<p.fare <<p.cabin <<p.embarked<<endl;
    for(auto p: t.stat_sex){
        cout<< "sex: " << p.first << " / survived: "<< p.second.first << " / total: "<< p.second.second << " / porba: " << double(p.second.first)/p.second.second << endl;
    }
    return 0;
}
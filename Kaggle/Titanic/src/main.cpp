#include <iostream>
#include <fstream>

#include "utils.h"
#include "passenger.h"
#include "titanic.h"

using std::cout;
using std::endl;
using std::ifstream;

int main(){
    ifstream train("data/train_test.csv");
    Titanic t(train);
    Passenger p = t.get(0);
    cout << p.passengerId <<  p.survived  << p.pClass << p.name <<p.sex <<p.age <<p.sibSp <<p.parch <<p.ticket <<p.fare <<p.cabin <<p.embarked<<endl;
    return 0;
}
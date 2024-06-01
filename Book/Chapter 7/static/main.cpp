#include <string>
#include <iostream>
#include <vector>
#include "class.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main(){
    Account myAccount("theo",99.9);
    cout << myAccount.rate() << endl;
    cout << Account::rate() << endl;
    cout << Account::interestRate << endl;
    return 0;
};

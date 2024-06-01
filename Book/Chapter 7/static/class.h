#ifndef CLASS_H
#define CLASS_H

#include <string>

class Account {
    public:
        Account(std::string o = "", double a = 0 ) : owner(o), amount(a) {}
        void calculate() { amount += amount * interestRate; }
        static double rate() { return interestRate; }
        static void rate(double);
        static double interestRate;
    private:
        std::string owner;
        double amount;
        //static double interestRate;
        //static double initRate();
        static constexpr int period = 30;
        double daily_tbl[period];
};

void Account::rate(double newRate)
{
    interestRate = newRate;
}

double initRate() {return 0.05;}

// define and initialize a static class member
double Account::interestRate = initRate();

constexpr int Account::period;

#endif
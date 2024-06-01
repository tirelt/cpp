#ifndef CLASS_H
#define CLASS_H

class ConstRef {
    public:
        ConstRef(int ii);
    private:
        int i;
        const int ci;
        int &ri;
};

ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }

#endif
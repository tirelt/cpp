#ifndef CLASS_X
#define CLASS_X

class ClassY;

class ClassX {
    public:
        ClassY* ptrY;
};

class ClassY {
    public:
        ClassX itemX;
};

#endif
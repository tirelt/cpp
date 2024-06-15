#include "class.h"

int main(){
    ClassX itemX;
    ClassY itemY;
    
    itemX.ptrY = &itemY;
    itemY.itemX = itemX;
    
    return 0;
};


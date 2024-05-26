#include <iostream>

int main() 
{
    int i = 1, &r1 = i;
    double d = 0, &r2 = d;
    std::cout << "i = " << i << "\n"<< "r1 = " << r1 << "\n" << "d = " << d << "\n"<< "r2 = " << r2 << "\n"<< std::endl;
    
    //r2 = 3.14159;
    //std::cout << "i = " << i << "\n"<< "r1 = " << r1 << "\n" << "d = " << d << "\n"<< "r2 = " << r2 << "\n"<< std::endl;
    
    r2 = r1;
    std::cout << "i = " << i << "\n"<< "r1 = " << r1 << "\n" << "d = " << d << "\n"<< "r2 = " << r2 << "\n"<< std::endl;
    
    //i = r2;
    //std::cout << "i = " << i << "\n"<< "r1 = " << r1 << "\n" << "d = " << d << "\n"<< "r2 = " << r2 << "\n"<< std::endl;
    
    //r1 =d;
    //std::cout << "i = " << i << "\n"<< "r1 = " << r1 << "\n" << "d = " << d << "\n"<< "r2 = " << r2 << "\n"<< std::endl;
    
    std::cout << "adress i = " << &i << std::endl;
    std::cout << "adress r1 = " << &r1 << std::endl;

    int j = 0, *p = &j;

    std::cout << "adress j = " << &j << std::endl;
    std::cout << "adress p = " << &p << std::endl;
    std::cout << "adress *p = " << &*p << std::endl;
    return 0;
}

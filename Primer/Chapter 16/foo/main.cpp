#include <vector>

template <typename T> class Foo {
    public:
        static std::size_t count() { return ctr; }
    // other interface members
        static std::size_t ctr;
       
    // other implementation members
};

template <typename T> std::size_t Foo<T>::ctr = 0;

int main(){
    return 0;
}

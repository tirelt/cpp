#include <stdexcept>

class SmallInt {
    public:
        SmallInt(int i = 0): val(i)
        {
            if (i < 0 || i > 255)
                throw std::out_of_range("Bad SmallInt value");
        }
        explicit operator int() const { return val; }
    private:
        std::size_t val;
};

int main(){
    SmallInt si;
    si = 4; // implicitly converts 4 to SmallInt then calls SmallInt::operator=
    // si + 3; // implicitly converts si to int followed by integer addition
    static_cast<int>(si) + 3; // ok: explicitly request the conversion
    return 0;
}
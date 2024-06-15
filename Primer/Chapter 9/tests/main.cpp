#include <vector>
#include <deque>
#include <list>
#include <array>

using std::list;
using std::vector;
using std::deque;
using std::array;
int main(){
    array<int,10> myArray;
    deque<int> element(10,1);
    list<deque<int>> myComplicatedList(10,element);
    return 0;
}

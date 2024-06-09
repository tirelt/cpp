#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::string;

template <typename T> int compare(const T &v1, const T &v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

// ok: same type used for the return type and parameter
template <typename T> T foo(T* p)
{
    T tmp = *p; // tmp will have the type to which p points
    return tmp;
}

template<unsigned N, unsigned M> int compare(const char (&p1)[N], const char (&p2)[M])
{
    return strcmp(p1, p2);
}

template<typename Iter,typename Value> Iter myFind(Iter beg,Iter end, Value value){
    while(beg!=end && *beg!=value){
        ++beg;
    }
    return beg;
}

int main(){
    //cout << compare(0,1) << endl;
    vector<int> myVect{5,3,4,2,7};
    int lookFor(5);
    cout <<  (myFind(myVect.begin(),myVect.end(),lookFor) == find(myVect.begin(),myVect.end(),lookFor)) << endl;

    list<string> myList{"a","c","t"};
    string lookForStr("c");
    cout <<  (myFind(myList.begin(),myList.end(),lookForStr) == find(myList.begin(),myList.end(),lookForStr)) << endl;
    return 0;
}
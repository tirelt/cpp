#include <map>
#include <iostream>
#include <string>

using std::map;
using std::cout;
using std::endl;
using std::string;
using std::pair;

template <typename T> void show(map<T,pair<unsigned,unsigned>>& m){
    for( auto el: m){
        cout<< el.first << ": " << el.second.first <<endl;
    }
}

int main(){
    map<string,pair<unsigned,unsigned>> m1 = {{"theo",{1,0}},{"tirel",{2,0}} };
    show(m1);
    map<int,pair<unsigned,unsigned>> m2 = {{0,{3,0}},{1,{4,0}} };
    show(m2);
    return 0;
}
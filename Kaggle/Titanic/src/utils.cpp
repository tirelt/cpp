#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::istringstream;
using std::vector;
using std::string;

string& replace_in_substring(string& s,unsigned pos1,unsigned pos2, const char old_c = ',', const char new_c = '-'){  
    for(unsigned i=pos1;i<=pos2;++i){
        char& c = s[i];
        if( c == old_c){
            c = new_c;
        }
    }
    return s;
}

vector<string> split_line(string& line, const char delimiter = ','){  
    vector<string> ret;
    string entry;
    istringstream ss(line);
    while(getline(ss,entry,delimiter))
        ret.push_back(entry);
    if(line.back()==',')
        ret.push_back(string());
    return ret;
}

string& erase_non_print(string& line){
    unsigned i=0;
    while( i<line.size()){
        if(std::isprint(line[i])){
            ++i;
        } else{
            line.erase(i,1);
        }
    }
    return line;
}
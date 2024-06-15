#include <string>

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

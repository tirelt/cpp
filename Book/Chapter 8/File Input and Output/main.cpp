#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream; 
using std::ofstream; 

int main(){
    vector<string> lineVect,wordVect;
    ifstream in("file");
    string line,word;
    while (getline(in, line)){
        lineVect.push_back(line);
    }
    while (in >> word){
        wordVect.push_back(word);
    }
    in.close();
    for( const string w : lineVect) {
        cout << w << endl;
        ofstream out(w,ofstream::app);
        out << w;
    }
    return 0;
};

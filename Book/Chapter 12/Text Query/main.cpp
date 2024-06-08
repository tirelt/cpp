#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <functional>
#include <memory>
#include <map>
#include <set>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::shared_ptr;
using std::make_shared;
using std::initializer_list;


class QueryResult; // declaration needed for return type in the query function
class TextQuery {
    public:
        using line_no = std::vector<std::string>::size_type;
        TextQuery(std::ifstream&);
        QueryResult query(const std::string&) const;
    private:
        std::shared_ptr<std::vector<std::string>> file; // input file
        // map of each word to the set of the lines in which that word appears
        std::map<std::string,std::shared_ptr<std::set<line_no>>> wm;
};

// read the input file and build the map of lines to line numbers


string strToLower(string s){
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}
TextQuery::TextQuery(std::ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) { // for each line in the file
        file->push_back(text); // remember this line of text
        int n = file->size() - 1; // the current line number
        std::istringstream line(text); // separate the line into words
        string word;
        while (line >> word) { // for each word in that line
            // if word isn’t already in wm, subscripting adds a new entry
            auto &lines = wm[strToLower(word)]; // lines is a shared_ptr
            if (!lines) // that pointer is null the first time we see word
                lines.reset(new std::set<line_no>); // allocate a new set
            lines->insert(n); // insert this line number
        }
    }
}


class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
    friend std::ostream& operator<<(std::ostream&,const QueryResult&);
    public:
        QueryResult(std::string s,std::shared_ptr<std::set<TextQuery::line_no>> p, std::shared_ptr<std::vector<std::string>> f):sought(s), lines(p), file(f) { }
    private:
        std::string sought; // word this query represents
        std::shared_ptr<std::set<TextQuery::line_no>> lines; // lines it’s on
        std::shared_ptr<std::vector<std::string>> file; // input file
};

QueryResult
TextQuery::query(const string &sought) const
{
    // we’ll return a pointer to this set if we don’t find sought
    static shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    // use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file); // not found
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " " << ((qr.lines->size() >1)? "times":"time") << endl;
    // print each line in which the word appeared
    string line,word;
    for (auto num : *qr.lines){ // for every element in the set
        line = (*qr.file)[num];
        std::istringstream in(line);
        std::ostringstream out;
        while (in >> word ){
            if( strToLower(word) == qr.sought )
                std::transform(word.begin(), word.end(), word.begin(), ::toupper);
            out << word << " "; 
        }   
        // don’t confound the user with text lines starting at 0
        //os << "\t(line " << num + 1 << ") "<< *(qr.file->begin() + num) << endl;
        os << "\t(line " << num + 1 << ") " << out.str() << endl;
        }
    return os;
}

std::ostream& operator<<(std::ostream& os,const QueryResult &qr){
    return print(os, qr);
}


void runQueries(std::ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile); // store the file and build the query map
    // iterate with the user: prompt for a word to find and print results
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        // stop if we hit end-of-file on the input or if a ’q’ is entered
        if (!(std::cin >> s) || s == "q") break;
        // run the query and print the results
            //print(cout, tq.query(s)) << endl;
            cout << tq.query(strToLower(s)) << endl;
    }
}

int main(){
    std::ifstream file("data");
    runQueries(file);
    return 0;
}
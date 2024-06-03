#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::bind;
using namespace std::placeholders;
/*
string make_plural(size_t ctr, const string& word, const string& ending )
{
    return (ctr > 1) ? word + ending : word;
}
*/
void elimDups(vector<string> &words)
{
    // sort words alphabetically so we can find the duplicates
    sort(words.begin(), words.end());
    // unique reorders the input range so that each word appears once in the
    // front portion of the range and returns an iterator one past the unique range
    auto end_unique = unique(words.begin(), words.end());
    // erase uses a vector operation to remove the nonunique elements
    words.erase(end_unique, words.end());
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void biggies(vector<string> &words,vector<string>::size_type sz)
{
    elimDups(words); // put words in alphabetical order and remove duplicates
    // sort words by size, but maintain alphabetical order for words of the same size
    stable_sort(words.begin(), words.end(),[] (const string &a, const string &b) { return a.size() < b.size();} );
    // get an iterator to the first element whose size() is >= sz
    auto check6 = bind(check_size, _1, 6);
    auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
    // compute the number of elements with size >= sz
    auto count = words.end() - wc;
    cout << count << " " <<  (string("word") + (count > 1 ? "s" : "") ) << " of length " << sz << " or longer" << endl;
    // print words of the given size or longer, each one followed by a space
    for_each(wc, words.end(), [](const string &s){cout << s << " ";});
    cout << endl;
}

int main(int argc, char **argv){
    vector<string> input = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    int sz = 5;
    biggies(input,sz);
    for(int i = 0; i < argc; i++ ){
        cout << argv[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
run 
./a.out -d -o arg1 arg2 ..
*/
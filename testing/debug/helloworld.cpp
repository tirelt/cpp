#include <iostream>
#include <vector>
#include <string>
#include "utils.h"

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    int a = func();
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
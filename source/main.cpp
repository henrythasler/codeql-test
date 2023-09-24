#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"This", "will", "crash"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    try {
        cout << msg[3] << endl;     // <-- this will segfault
        // cout << msg.at(3) << endl;     // <-- this will be catched
    }
    catch(...){
        cout << "Lucky you!" << endl;
    }
}
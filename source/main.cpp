#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg{"This", "will", "crash"};

    // inherently safe
    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    if (msg.size() > 3)
    {
        cout << msg[3] << endl; // inside bounds check
    }

    for (int num = 0; num < msg.size(); num++)
    {
        cout << msg[num] << ", "; // inside bounds check
    }
    cout << endl;

    try
    {
        cout << msg[3] << endl; // <-- this will segfault
        // cout << msg.at(3) << endl;     // <-- this will be catched
    }
    catch (...)
    {
        cout << "Lucky you!" << endl;
    }
}
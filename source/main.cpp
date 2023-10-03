#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg{"This", "might", "crash"};

    // inherently safe
    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    // inside bounds check (safe)
    if (msg.size() > 3)
    {
        cout << msg[3] << endl;
    }

    // inside bounds check (safe)
    for (int i = 0; i < msg.size(); i++)
    {
        cout << msg[i] << ", ";
    }
    cout << endl;

    // UNSAFE
    try
    {
        cout << msg[3] << endl; // <-- this will segfault
        // cout << msg.at(3) << endl;     // <-- this will be caught
    }
    catch (...)
    {
        cout << "Lucky you!" << endl;
    }
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> sentence{"This", "might", "crash"};
    string message{"hello"};
    int num;

    // inside bounds check (safe)
    for (size_t i = 0; i < message.length(); ++i) {
        message[i] = message[i] - 32;
    }    
    cout << message << endl;

    // inherently safe
    for (const string &word : sentence)
    {
        cout << word << " ";
    }
    cout << endl;

    // inside bounds check (safe)
    if (sentence.size() > 3)
    {
        cout << sentence[3] << endl;
    }

    // inside bounds check (safe)
    for (int i = 0; i < sentence.size(); i++)
    {
        cout << sentence[i] << ", ";
    }
    cout << endl;

    // Shifting a negative number is undefined behavior
    num = -1;
    num = num << 2;
    cout << num << endl;

    // UNSAFE
    try
    {
        cout << sentence[3] << endl; // <-- this will segfault
        // cout << msg.at(3) << endl;     // <-- this will be caught
    }
    catch (...)
    {
        cout << "Lucky you!" << endl;
    }
}